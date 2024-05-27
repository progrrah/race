#include "display.hpp"
extern bool RANDOM_COLOR_OPTION;
extern car mycar;
extern track mytrack;
extern track menuEnd;
extern track menuGame;
extern track initmenuGame;
void Game::startGame() {
  mytrack = *activeTrack;
  mycar = *activeCar;
  menuGame = *activeMenu;
  TIME = time;
  YY = mycar.initY;
  deltax = 0.1;
  deltay = 0.015;
  carPhi = 0;
  scaleX = 0.7;
  scaleY = 0.7;
  EXIT_KEY_IN_INTERACTION = false;
  RANDOM_COLOR_OPTION = false;
}
void Game::restartGame() {}
void Game::killGame() {}
void Game::finishGame() {
  menuGame = menuEnd;
  EXIT_KEY_IN_INTERACTION = true;
  RANDOM_COLOR_OPTION = true;
  EXIT_KEY_IS_FINISHED = false;
}