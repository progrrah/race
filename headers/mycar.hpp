/**/
#pragma once
#include "library.hpp"
using namespace Drawer;
using namespace Objects;
extern container_type<container_type<double>> rgblist;
////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////  car design
////////////////////////////////////////////////////////////////////////////////////////////////////////
Point p9 = {-0.1, -0.15};
Point p10 = {-0.1, 0.15};
Point p11 = {0.1, 0.15};
Point p12 = {0.1, -0.15};
container_type<Point> pcarlist{p9, p10, p11, p12};
container_type<container_type<double>> carColor{{0.9, 0.5, 0.1}};

// дизайн машины
design dcarEl1(pcarlist, carColor, typeDrawing::QUADS);
// design dcarEl2(pcarlist, carColor);
container_type<design*> dcarlist{&dcarEl1};
Design dcar{dcarlist};