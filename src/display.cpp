#include "display.hpp"
extern car mycar;
extern track mytrack;
void Game::startGame() {
  mytrack = *activeTrack;
  mycar = *activeCar;
  TIME = time;
  YY = mycar.initY;
}
void Game::restartGame() {}
void Game::killGame() {}