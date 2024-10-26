#include "EventTrigger.h"
#include "../include/raylib.h"
double lastUpdatedTime = 0.0;

// ToDo :- Try to optimise this method as it's calling GetTime() 60 time per sec
bool eventTriggered(double interval) {
  double currentTime = GetTime();
  if (currentTime - lastUpdatedTime >= interval) {
    lastUpdatedTime = currentTime;
    return true;
  }
  return false;
}