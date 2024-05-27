#include "display.hpp"
extern car mycar;
extern track mytrack;
void Game::startGame() {
  mytrack = *activeTrack;
  mycar = *activeCar;
  TIME = time;
  YY = mycar.initY;
  carPhi = 0;
  scaleX = 1;
  scaleY = 1;
  EXIT_KEY_IN_INTERACTION = false;
}
void Game::restartGame() {}
void Game::killGame() {}