#pragma once
#include "library.hpp"
template <typename T>
using container_type = std::vector<T>;
extern container_type<double> rgblist;
namespace Drawer {
enum class typeDrawing { QUADS, TRIANGLES, POLYGONS, CIRCLES, POINTS };
struct Point {
  double x, y;
  // OKAY
  bool operator==(const Point &other) const {
    return (x == other.x) && (y == other.y);
  }
  bool operator!=(const Point &other) const {
    return x != other.x || y != other.y;
  }
  bool operator<(const Point &other) const {
    return x < other.x || (x == other.x && y < other.y);
  }
  bool operator>(const Point &other) const {
    return x > other.x || (x == other.x && y > other.y);
  }
  // I DONT REMEMBER
  Point &operator=(const std::initializer_list<double> &other) {
    this->x = *other.begin();
    this->y = *(other.end());
    return *this;
  }
};

struct design {
  int numberPoints;
  container_type<Point> points; /*size it numberPoints*/
  double width, height;
  container_type<double> colorList; /*size it numberPoints*/
  container_type<typeDrawing> drawingMethods;
  void draw(typeDrawing type);
  design() = default;
  design(int number, container_type<Point> externPoints,
         container_type<double> externColorList = rgblist,
         container_type<typeDrawing> exdrawingMethods = {typeDrawing::POINTS})
      : numberPoints(number), points(externPoints), colorList(externColorList) {
    double maxX, minX;
    double maxY, minY;
    std::set<Point> sortedPoints{points.begin(), points.end()};
    minX = sortedPoints.begin()->x;
    maxX = (--sortedPoints.end())->x;
    minY = sortedPoints.begin()->y;
    maxY = (--sortedPoints.end())->y;
    this->width = abs(minX - maxX);
    this->height = abs(minY - maxY);
  };
  void printPoints() {
    std::set<Point> sortedPoints{points.begin(), points.end()};
    for (auto const &i : sortedPoints) std::cout << i.x << ' ' << i.y << '\n';
  }
};
};  // namespace Drawer
  