#include <GL/glut.h>

#include "initLibrary.hpp"

#include <vector>

#include "initLibrary.hpp"
#include "design.hpp"
#include "interaction.hpp"
#include "library.hpp"
template <typename T>
using container_type = std::vector<T>;
using namespace Interaction;
using namespace Objects;
using namespace Drawer;
extern const int SHIFTING_TIME;
// extern const int REDISPLAY_TIME;
extern const int WIDTH;   // window width
extern const int HEIGHT;  // window height
extern const float POINT_RADIUS;
extern bool EXIT_KEY_IN_INTERACTION;
extern bool SELECT_KEY_WINDOW;
extern int SELECT_KEY_DISPLAY;

char **fileName;
extern car mycar;
extern track mytrack;
extern track menuGame;
void displayGame() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  doTransformTrack();
  mytrack.drawTrack();
  glPopMatrix();
  menuGame.drawTrack();
  auto drawMenuObjects = []() {
    for (auto object_iter : menuGame.elems) {
      glPushMatrix();
      doTransformTrackObjects(*object_iter);
      object_iter->drawObject();
      glLoadIdentity();
    }
  };
  drawMenuObjects();
  doTransformCar();
  mycar.drawCar();
  glLoadIdentity();
  auto drawTrackObjects = []() {
    for (auto object_iter : mytrack.elems) {
      if (canDraw(*object_iter, mycar)) {
        glPushMatrix();
        doTransformTrackObjects(*object_iter);
        object_iter->drawObject();
        glLoadIdentity();
      }
    }
  };
  drawTrackObjects();
  glutSwapBuffers();
}
void displayStartMenu() {
  // something here
  // mouse handling we should
}
void displayEndMenu() {
  // something here
  // mouse handling we should
}
void displayTroll() {}
void initOpengl() {
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(WIDTH, HEIGHT);
  glutInitWindowPosition(500, 500);
  glutCreateWindow("race");
  glClearColor(1, 1, 1, 1);
  glutKeyboardFunc(keyBoard);
  // how does it work
  selectDisplay();
  glutTimerFunc(REDISPLAY_TIME, redisplayTimer, 1);
  glutTimerFunc(SHIFTING_TIME, moveСontinuously, 0);
}
void selectDisplay() {
  switch (SELECT_KEY_DISPLAY) {
    case 0:
      glutDisplayFunc(displayStartMenu);
      break;
    case 1:
      glutDisplayFunc(displayGame);
      break;
    case 2:
      glutDisplayFunc(displayEndMenu);
      break;
    default:
      displayTroll();
      break;
  }
}