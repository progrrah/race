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

static void RenderSceneCB_win1() {
  GLclampf Red = 1.0f, Green = 0.0f, Blue = 0.0f, Alpha = 0.0f;
  glClearColor(Red, Green, Blue, Alpha);
  glClear(GL_COLOR_BUFFER_BIT);
  glutSwapBuffers();
}

static void RenderSceneCB_win2() {
  GLclampf Red = 0.0f, Green = 1.0f, Blue = 0.0f, Alpha = 0.0f;
  glClearColor(Red, Green, Blue, Alpha);
  glClear(GL_COLOR_BUFFER_BIT);
  glutSwapBuffers();
}
void useTwoWindow() {
  int width = 1920;
  int height = 1080;
  glutInitWindowSize(width, height);

  int x = 0;
  int y = 0;
  glutInitWindowPosition(x, y);
  int win1 = glutCreateWindow("Window #1");
  printf("Window #1 id: %d\n", win1);

  width = 1024;
  height = 768;
  glutInitWindowSize(width, height);

  x = 200;
  y = 300;
  glutInitWindowPosition(x, y);
  int win2 = glutCreateWindow("Window #2");
  printf("Window #2 id: %d\n", win2);

  glutSetWindow(win1);
  glutDisplayFunc(RenderSceneCB_win1);

  glutSetWindow(win2);
  glutDisplayFunc(RenderSceneCB_win2);
}