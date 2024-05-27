#include "display.hpp"
extern car mycar;
extern track mytrack;
void Game::startGame() {
  mytrack = *activeTrack;
  mycar = *activeCar;
  TIME = time;
  YY = mycar.initY;
  deltax = 0.1;
  carPhi = 0;
  scaleX = 0.7;
  scaleY = 0.7;
  EXIT_KEY_IN_INTERACTION = false;
}
void Game::restartGame() {}
void Game::killGame() {}