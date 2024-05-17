#include <GL/glut.h>
#include <vector>
#include "design.hpp"
#include "interaction.hpp"
// #include "library.hpp"
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
extern container_type<double> rgblist;
extern bool EXIT_KEY_IN_INTERACTION;

extern car mycar;
extern track mytrack;
extern bottle obj1;
extern double YY;
extern double XX;
extern double xCar;
extern double yCar;
extern double trackPhi;  // it hold in mycar.x
extern double carPhi;    // it hold in mycar.x
extern double deltaPhi;
void display();
void initOpengl();
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  initOpengl();
  glutMainLoop();
  return 0;
}
void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  doTransformTrack();
  mytrack.drawTrack();
  glPopMatrix();
  doTransformCar();
  mycar.drawCar();
  glLoadIdentity();
  ////
  ////
  ////
  // THE MOST IMPORTANT MOMENT!!!
  ////
  ////
  ////
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
void initOpengl() {
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(WIDTH, HEIGHT);
  glutInitWindowPosition(500, 500);
  glutCreateWindow("race");
  glClearColor(1, 1, 1, 1);

  glutKeyboardFunc(keyBoard);
  // how does it work
  glutDisplayFunc(display);
  // glutReshapeFunc(reshape);
  glutTimerFunc(REDISPLAY_TIME, redisplayTimer, 1);
  // glutTimerFunc(SHIFTING_TIME, moveALL, 0);
}