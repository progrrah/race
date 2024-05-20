/*
основной файл где инициализируется 
*/
#include <GL/glut.h>
#include <vector>
#include "design.hpp"
#include "interaction.hpp"
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
extern container_type<container_type<double>> rgblist;
extern bool EXIT_KEY_IN_INTERACTION;
extern bool SELECT_KEY_WINDOW;
extern int SELECT_KEY_DISPLAY;

extern car mycar;
extern container_type<track_object *> mytrackObjects;
extern track mytrack;
extern double YY;
extern double XX;
extern double xCar;
extern double yCar;
extern double trackPhi;  // it hold in mycar.x
extern double carPhi;    // it hold in mycar.x
extern double deltaPhi;
void selectDisplay();
void displayStartMenu();
void displayEndMenu();
void displayGame();
void displayTroll();

void initOpengl();
static void RenderSceneCB_win1();
static void RenderSceneCB_win2();
void useTwoWindow();
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  initOpengl();
  glutMainLoop();
  return 0;
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
void displayGame() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  doTransformTrack();
  mytrack.drawTrack();
  glPopMatrix();
  doTransformCar();
  mycar.drawCar();
  glLoadIdentity();
  ///
  // THE MOST IMPORTANT MOMENT!!!
  for (auto object_iter : mytrack.elems) {
    if (canDraw(*object_iter, mycar)) {
      // std::cout << "I'm drawing";
      glPushMatrix();
      doTransformTrackObjects(*object_iter);
      object_iter->drawObject();
      glLoadIdentity();
    }
  }
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
  // glutDisplayFunc(displayGame);
  // glutDisplayFunc(displayStartMenu);
  // glutReshapeFunc(reshape);
  glutTimerFunc(REDISPLAY_TIME, redisplayTimer, 1);
  // glutTimerFunc(SHIFTING_TIME, moveALL, 0);
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