/*
// файл, где инициализируется программа
*/
#include <GL/glut.h>
#include "initLibrary.hpp"
void initOpengl();
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  initOpengl();
  glutMainLoop();
  return 0;
}
