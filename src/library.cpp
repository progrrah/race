/*
здесь главная функция для отрисовки объектов
////
  void Drawer::design::draw(typeDrawing type);
////
*/
bool RANDOM_COLOR_OPTION = 0;
#include "library.hpp"
void Drawer::design::draw(typeDrawing type) {
  switch (type) {
    case typeDrawing::QUADS:
      for (int i{0}; i < numberPoints; i++) {
        glBegin(GL_QUADS);
        double r, g, b;
        if (RANDOM_COLOR_OPTION) {
          r = double(rand()) / RAND_MAX;
          g = double(rand()) / RAND_MAX;
          b = double(rand()) / RAND_MAX;
        } else {
          r = colorList[i][0];
          g = colorList[i][1];
          b = colorList[i][2];
        }
        glColor3d(r, g, b);
        glVertex2d(points.at(i).x, points.at(i).y);
      }
      glEnd();
      break;
    case typeDrawing::TRIANGLES:
      for (int i{0}; i < numberPoints; i += 1) {
        glBegin(GL_TRIANGLES);
        double r, g, b;
        if (RANDOM_COLOR_OPTION) {
          r = double(rand()) / RAND_MAX;
          g = double(rand()) / RAND_MAX;
          b = double(rand()) / RAND_MAX;
        } else {
          r = colorList[i][0];
          g = colorList[i][1];
          b = colorList[i][2];
        }
        glColor3d(r, g, b);
        glVertex2d(points.at(i).x, points.at(i).y);
      }
      glEnd();
      break;
    case typeDrawing::POLYGONS:
      break;
    case typeDrawing::CIRCLES:
      glBegin(GL_QUADS);
      // for loop
      glEnd();
      break;
    case typeDrawing::POINTS:
      glPointSize(POINT_RADIUS);
      glBegin(GL_POINTS);
      for (int i{}; i < numberPoints; i++) {
        double r, g, b;
        if (RANDOM_COLOR_OPTION) {
          r = double(rand()) / RAND_MAX;
          g = double(rand()) / RAND_MAX;
          b = double(rand()) / RAND_MAX;
        } else {
          r = colorList[i][0];
          g = colorList[i][1];
          b = colorList[i][2];
        }
        glColor3d(r, g, b);
        glVertex2d(points.at(i).x, points.at(i).y);
      }
      glEnd();
      break;
    case typeDrawing::LINES:
      glLineWidth(WIDTH_LINES_OR_POINTS);
      glBegin(GL_LINE_STRIP);
      // glBegin(GL_LINES);
      for (int i{}; i < numberPoints; i++) {
        double r, g, b;
        if (RANDOM_COLOR_OPTION) {
          r = double(rand()) / RAND_MAX;
          g = double(rand()) / RAND_MAX;
          b = double(rand()) / RAND_MAX;
        } else {
          r = colorList[i][0];
          g = colorList[i][1];
          b = colorList[i][2];
        }
        glColor3d(r, g, b);
        glVertex2d(points.at(i).x, points.at(i).y);
      }
      glEnd();
      break;
    default:
      std::cout << "I dont know THIS TYPE OF DRAWING\n";
      break;
  }
}