/**/
#pragma once
#include "library.hpp"
using namespace Drawer;
using namespace Objects;
////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////  car design
////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Большой квадрат
Point carMainPoint1 = {-0.1, -0.15};
Point carMainPoint2 = {-0.1, 0.15};
Point carMainPoint3 = {0.1, 0.15};
Point carMainPoint4 = {0.1, -0.15};
container_type<Point> mainPoints{carMainPoint1, carMainPoint2, carMainPoint3,
                                 carMainPoint4};
container_type<container_type<double>> carColor{
    {0.1, 0.5, 0.1}, {0.6, 0.5, 0.1}, {0.8, 0.5, 0.4}, {0.3, 0.5, 0.9}};

// дизайн машины
design dcarEl1(mainPoints, carColor, typeDrawing::QUADS);
//////
////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Колеса1
Point carWheelPoint1 = {};
Point carWheelPoint2 = {};
Point carWheelPoint3 = {};
Point carWheelPoint4 = {};

////Колеса2
Point carWheelPoint5 = {};
Point carWheelPoint6 = {};
Point carWheelPoint7 = {};
Point carWheelPoint8 = {};

///
container_type<Point> wheelPoints = {carWheelPoint1, carWheelPoint2};
container_type<container_type<double>> wheelColor = {};
design dcarWheels(wheelPoints, wheelColor, typeDrawing::QUADS);

container_type<design*> dcarlist{&dcarEl1};
Design dcar{dcarlist};
