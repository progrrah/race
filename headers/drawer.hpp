/*
представлены структуры для задания внешнего вида объектов и отрисовки их
struct Point, design;
*/
#pragma once
#include "library.hpp"
// #include "animation.hpp"
template <typename T>
using container_type = std::vector<T>;
extern container_type<container_type<double>> rgblist;
namespace Drawer {
enum class typeDrawing { QUADS, TRIANGLES, POLYGONS, CIRCLES, POINTS, LINES };
struct Point {
  double x, y;
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
  Point &operator=(const std::initializer_list<double> &other) {
    this->x = *other.begin();
    this->y = *(other.end());
    return *this;
  }
};

struct design {
  double WIDTH_LINES_OR_POINTS;
  int numberPoints;
  container_type<Point> points;
  double width, height;
  container_type<container_type<double>> colorList;
  typeDrawing drawingMethod;
  void draw(typeDrawing type);
  design() {}
  design(container_type<Point> externPoints,
         container_type<container_type<double>> externColorList,
         typeDrawing exdrawingMethod = typeDrawing::POINTS, double exWIDTH = 0)
      : numberPoints(externPoints.size()),
        points(externPoints),
        colorList(externColorList),
        drawingMethod(exdrawingMethod),
        WIDTH_LINES_OR_POINTS(exWIDTH) {
    calculateSizes();
  };
  void calculateSizes() {
    double maxX, minX;
    double maxY, minY;
    std::set<Point> sortedPoints{points.begin(), points.end()};
    minX = sortedPoints.begin()->x;
    maxX = (--sortedPoints.end())->x;
    minY = sortedPoints.begin()->y;
    maxY = (--sortedPoints.end())->y;
    this->width = abs(minX - maxX);
    this->height = abs(minY - maxY);
  }
  void printPoints() {
    std::set<Point> sortedPoints{points.begin(), points.end()};
    for (auto const &i : sortedPoints) std::cout << i.x << ' ' << i.y << '\n';
  }
  void inputPoints() {
    std::cout << "Ввод точки в систему";
    Point p;
    double x{};
    double y{};
    std::cin >> x;
    std::cin >> y;
    if (x >= -1 && x <= 1) {
      p.x = x;
      p.y = y;
      points.push_back(p);
      numberPoints++;
    }
  }
};
struct Design {
  container_type<design *> designs;
  double width;
  double height;
  Design() : width(0), height(0) {}
  Design(container_type<design *> exdesins) : designs(exdesins) {
    double tempW{0};
    double tempH{0};
    for (size_t i = 0; i < designs.size(); i++) {
      tempW += designs.at(i)->width;
      tempH += designs.at(i)->height;
    }
    width = tempW;
    height = tempH;
  }
};
};  // namespace Drawer
