#include "library.hpp"
void Drawer::design::draw(typeDrawing type) {
  switch (type) {
    case typeDrawing::QUADS:
      for (int i{}; i < numberPoints; i += 4) {
        glBegin(GL_QUADS);
        // double r = double(rand()) / RAND_MAX;
        // double g = double(rand()) / RAND_MAX;
        // double b = double(rand()) / RAND_MAX;
        double r = colorList[0];
        double g = colorList[1];
        double b = colorList[2];
        glColor3d(r + 0.1, g + 0.3, b + 0.1);
        glVertex2d(points.at(i).x, points.at(i).y);
        glVertex2d(points.at(i + 1).x, points.at(i + 1).y);
        glVertex2d(points.at(i + 2).x, points.at(i + 2).y);
        glVertex2d(points.at(i + 3).x, points.at(i + 3).y);
      }
      glEnd();
      break;
    case typeDrawing::TRIANGLES:
      for (int i{}; i < numberPoints; i += 3) {
        glBegin(GL_QUADS);
        double r = double(rand()) / RAND_MAX;
        double g = double(rand()) / RAND_MAX;
        double b = double(rand()) / RAND_MAX;
        // double r = colorList[0];
        // double g = colorList[1];
        // double b = colorList[2];
        glColor3d(r + 0.1, g + 0.3, b + 0.1);
        glVertex2d(points.at(i).x, points.at(i).y);
        glVertex2d(points.at(i + 1).x, points.at(i + 1).y);
        glVertex2d(points.at(i + 2).x, points.at(i + 2).y);
      }
      glEnd();
      // glBegin(GL_TRIANGLES);

      // glEnd();
      break;
    case typeDrawing::POLYGONS:
      // for loop
      break;
    case typeDrawing::CIRCLES:
      glBegin(GL_QUADS);
      // for loop
      glEnd();
      break;
    case typeDrawing::POINTS:
      glClear(GL_COLOR_BUFFER_BIT);
      glColor3f(0, 0.5, 0.8);
      glPointSize(POINT_RADIUS);
      glBegin(GL_POINTS);
      for (Point &p : points) {
        glVertex2d(p.x, p.y);
      }
      glEnd();
      break;
    default:
      // std::cout << "I dont know THIS TYPE OF DRAWING\n";
      break;
  }
}