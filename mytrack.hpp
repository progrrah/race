#pragma once
#include "library.hpp"
using namespace Drawer;
using namespace Objects;
extern bottle obj1;
extern bottle obj2;
extern container_type<double> rgblist;
container_type<double> bigQuadColor2{0.2, 0.2, 0.7};
container_type<double> smallQuadColor2{0.2, 0.8, 0.1};
////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////  track design
////////////////////////////////////////////////////////////////////////////////////////////////////////
Drawer::Point p1{-0.85, -1};
Drawer::Point p2{-0.85, 1};
Drawer::Point p3{0.85, 1};
Drawer::Point p4{0.85, -1};

Drawer::Point p5{-0.05, -1};
Drawer::Point p6{-0.05, 1};
Drawer::Point p7{0.05, 1};
Drawer::Point p8{0.05, -1};

container_type<Point> pointLists{p1, p2, p3, p4, p5, p6, p7, p8};
container_type<Point> plist1{p1, p2, p3, p4};
container_type<Point> plist2{p5, p6, p7, p8};

design ds1(4, plist1, bigQuadColor2);
design ds2(4, plist2, smallQuadColor2);
// дизайн трэка из двух прямоугольников
container_type<design> designs{ds1, ds2};
