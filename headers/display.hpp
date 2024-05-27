#pragma once
#include <GL/glut.h>
#include <vector>
#include "library.hpp"
extern int TIME;
extern int SELECT_KEY_DISPLAY;
using namespace Objects;
using namespace Drawer;
struct Game {
  track* activeTrack;
  track* activeMenu;
  car* activeCar;

  int time;
  void startGame();
  void restartGame();
  void killGame();
  void finishGame();
  Game(){};
  Game(track* exTrack, track* exactiveMenu, car* exCar, int exTime)
      : activeTrack(exTrack),
        activeCar(exCar),
        time(exTime),
        activeMenu(exactiveMenu) {}
};