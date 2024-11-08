# Tetris Game with raylib

Tetris game is built on top of [raylib](https://www.raylib.com/index.html) using C++17.</br>
![Tetris](/screenshots/screenshot_1.png)

## Table of Contents

- [Dependency](#Dependency)
- [Compiling & Building](#Compiling)
- [Game Control](#Game)
- [License](#license)

### Dependency

As of Oct 2024 whole game is built on mac using C++17 and raylib library. You would need working setup for C++17. I am using [CMake](https://cmake.org/) as buid tool. Instruction for how to install CMake and how to setup C++ is available everywhere so skipping :).

1. [CMake](https://cmake.org/)
2. [Raylib](https://www.raylib.com/index.html)

### Compiling & Building

As it doesn't have static libaray of raylib included. Have to install raylib in system itself. (my first choice of OS was Mac. Will include static lib or dynamic build in upcoming version).

1. Clone the repository.
2. `brew install raylib` Install raylib in your Mac first.
   a. To install on Linux follow [official guide](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux)
   b. TLDR :- Easiest way to do is [install dependency](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux#ubuntu) and [build from source](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux#build-raylib-using-cmake) using cmake.
3. Move inside the Repo `cd Tetris`
4. Create a folder in root folder name `mkdir build`
5. `cd build`
6. `cmake .. && make`
7. It will create an executable name <b>Tetris</b> which can be run with `./Tetris`

Resource of this game (Music, Fonts) are outside the build folder, and paths to load these are relative. To get music and correct font for score copy <b>Tetris</b> exicutable to root folder and run again.

- `cp Tetris ../`
- `./Tetris` this should bring music.

##### Testing raylib setup

If compile and build failed first place to look at is setup of raylib.
inside root folder <b>tests/test_raylib_setup.cpp</b> follow same bulding process with creating a build folder. Exicutable <b>TestRayLib</b> should show following screen.
![TestRayLib](/screenshots/screenshot_2.png)

## Game Control

- Left Arrow key :point_right: :- To move block left.
- Right Arrow key :point_right: :- To move block right.
- Up Arrow key :point_right: :- To rotate the block.

## License

[LICENSE](https://github.com/xpd54/Tetris/blob/main/LICENSE)
