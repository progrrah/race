#pragma once
#include <GL/glut.h>

#include "initLibrary.hpp"

#include <vector>

#include "interaction.hpp"
#include "library.hpp"
extern int TIME;
extern int SELECT_KEY_DISPLAY;
using namespace Objects;
using namespace Drawer;
struct Game {
  track* activeTrack;
  car* activeCar;
  int time;
  void startGame();
  void restartGame();
  void killGame();
  Game(){};
  Game(track* exTrack, car* exCar, int exTime)
      : activeTrack(exTrack), activeCar(exCar), time(exTime) {}
};