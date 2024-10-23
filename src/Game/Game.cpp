#include "Game.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
Game::Game() {
  // Set Srand one time
  srand(time(NULL));
  current_block = get_random_block();
  next_block = get_random_block();
  blocks = get_all_blocks();
  game_over = false;
  game_score = 0;

  // handle audio of game
  InitAudioDevice();
  game_music = LoadMusicStream("Music/tetris_background_music.mp3");
  PlayMusicStream(game_music);
  sound_move_reverted = LoadSound("Music/tetris_move_reverted.mp3");
  sound_move_success = LoadSound("Music/tetris_move_success.mp3");
  sound_game_over = LoadSound("Music/tetris_game_over.mp3");
  sound_tetris_clear = LoadSound("Music/tetris_clear.mp3");
}

Game::~Game() {
  UnloadSound(sound_move_reverted);
  UnloadSound(sound_move_success);
  UnloadSound(sound_game_over);
  UnloadSound(sound_tetris_clear);
  UnloadMusicStream(game_music);
  CloseAudioDevice();
}

Tetromino Game::get_random_block() {
  if (blocks.empty()) {
    blocks = get_all_blocks();
  }
  auto randomValue = rand();
  uint32_t randomIndex = randomValue % blocks.size();
  Tetromino random_block = blocks[randomIndex];
  blocks.erase(blocks.begin() + randomIndex);
  return random_block;
}

std::vector<Tetromino> Game::get_all_blocks() {
  return {LBlock(), JBlock(), IBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::draw() {
  window.draw();
  current_block.draw((CELL_SEPERATOR_SIZE + GAME_WINDOW_OFF_SET),
                     (CELL_SEPERATOR_SIZE + GAME_WINDOW_OFF_SET));
  // draw next block to right side of user section. Some hard coded offSet which
  // makes it look fine and centered for all the next blocks
  switch (next_block.tetromino_shape) {
  case 3:
    next_block.draw(255, 255);
    break;
  case 4:
    next_block.draw(255, 280);
    break;
  default:
    next_block.draw(270, 270);
    break;
  }
}

void Game::handle_input() {
  int key = GetKeyPressed();
  if (game_over && key == KEY_SPACE) {
    game_over = false;
    reset_game();
  }
  switch (key) {
  case KEY_LEFT:
    move_current_block_left();
    break;
  case KEY_RIGHT:
    move_current_block_right();
    break;
  case KEY_DOWN:
    move_current_block_down();
    update_score(0, 1);
    break;
  case KEY_UP:
    rotate_current_block();
    break;
  default:
    break;
  }
}

void Game::move_current_block_left() {
  if (game_over)
    return;
  current_block.move(0, -1);
  if (is_current_block_outside() || !does_current_block_fits()) {
    current_block.move(0, 1);
    PlaySound(sound_move_reverted);
    return;
  }
  PlaySound(sound_move_success);
}

void Game::move_current_block_right() {
  if (game_over)
    return;
  current_block.move(0, 1);
  if (is_current_block_outside() || !does_current_block_fits()) {
    current_block.move(0, -1);
    PlaySound(sound_move_reverted);
    return;
  }
  PlaySound(sound_move_success);
}

void Game::move_current_block_down() {
  if (game_over)
    return;
  current_block.move(1, 0);
  if (is_current_block_outside() || !does_current_block_fits()) {
    current_block.move(-1, 0);
    lock_current_block();
  }
}

void Game::rotate_current_block() {
  if (game_over)
    return;
  current_block.rotate();
  if (is_current_block_outside() || !does_current_block_fits()) {
    current_block.undo_rotation();
    PlaySound(sound_move_reverted);
    return;
  }
  PlaySound(sound_move_success);
}

bool Game::is_current_block_outside() {
  std::vector<CellPosition> tiles = current_block.get_moved_position();
  return std::any_of(
      tiles.begin(), tiles.end(), [&](const CellPosition &position) {
        return window.is_cell_outside(position.row, position.column);
      });
}

void Game::lock_current_block() {
  std::vector<CellPosition> tiles = current_block.get_moved_position();
  std::for_each(tiles.begin(), tiles.end(), [&](CellPosition &position) {
    window.surface.at(position.row).at(position.column) =
        current_block.tetromino_shape;
  });
  current_block = next_block;
  if (!does_current_block_fits()) {
    game_over = true;
    PlaySound(sound_game_over);
  }
  next_block = get_random_block();
  uint32_t row_cleared = window.clear_full_row();
  if (row_cleared) {
    PlaySound(sound_tetris_clear);
    update_score(row_cleared, 0);
  }
}

bool Game::does_current_block_fits() {
  std::vector<CellPosition> tiles = current_block.get_moved_position();
  return std::all_of(tiles.begin(), tiles.end(), [&](CellPosition &postion) {
    return window.is_cell_empty(postion.row, postion.column);
  });
}

void Game::reset_game() {
  window.initialize_window();
  blocks = get_all_blocks();
  current_block = get_random_block();
  next_block = get_random_block();
  // when game get reset after game over we set score to zero
  game_score = 0;
}

void Game::update_score(uint32_t row_cleared, uint32_t moved_down_points) {
  switch (row_cleared) {
  case 1:
    game_score += 100;
    break;
  case 2:
    game_score += 300;
    break;
  case 3:
    game_score += 500;
    break;
  default:
    break;
  }
  game_score += moved_down_points;
}