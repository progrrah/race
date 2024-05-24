/**/
#pragma once
#include "library.hpp"
using namespace Drawer;
using namespace Objects;
////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                      car design
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

//// Колеса1
Point carWheelPoint1 = {-0.08, 0.1};
Point carWheelPoint2 = {-0.1, 0.1};
Point carWheelPoint3 = {-0.1, 0.15};
Point carWheelPoint4 = {-0.08, 0.15};

////Колеса2
Point carWheelPoint5 = {-0.08, -0.1};
Point carWheelPoint6 = {-0.1, -0.1};
Point carWheelPoint7 = {-0.1, -0.05};
Point carWheelPoint8 = {-0.08, -0.05};

container_type<Point> wheelPoints = {
    carWheelPoint1, carWheelPoint2, carWheelPoint3, carWheelPoint4,
    carWheelPoint5, carWheelPoint6, carWheelPoint7, carWheelPoint8};
container_type<container_type<double>> wheelColor = {
    {0.1, 0.1, 0.1}, {0.1, 0.1, 0.1}, {0.1, 0.1, 0.1}, {0.1, 0.1, 0.1},
    {0.1, 0.1, 0.1}, {0.6, 0.5, 0.1}, {0.8, 0.5, 0.4}, {0.3, 0.5, 0.9}};

design dcarEl2(wheelPoints, wheelColor, typeDrawing::QUADS);

/// Окна1
Point carWindowPoints1 = {-0.05, 0.075};
Point carWindowPoints2 = {-0.05, 0.1125};
Point carWindowPoints3 = {0.05, 0.075};
Point carWindowPoints4 = {0.05, 0.1125};

// Окна2
Point carWindowPoints5 = {-0.09, -0.09};
Point carWindowPoints6 = {-0.09, 0.07};
Point carWindowPoints7 = {-0.07, 0.07};
Point carWindowPoints8 = {-0.07, -0.09};

// Окна3
Point carWindowPoints9 = {-0.07, -0.09};
Point carWindowPoints10 = {0.07, 0.07};
Point carWindowPoints11 = {0.09, 0.07};
Point carWindowPoints12 = {0.09, -0.09};

container_type<Point> windowPoints = {
    carWindowPoints1, carWindowPoints2,  carWindowPoints3,  carWindowPoints4,
    carWindowPoints5, carWindowPoints6,  carWindowPoints7,  carWindowPoints8,
    carWindowPoints9, carWindowPoints10, carWindowPoints11, carWindowPoints12};
container_type<container_type<double>> windowColor = {
    {0.125, 0.34, 0.34}, {0.125, 0.34, 0.34}, {0.125, 0.34, 0.34},
    {0.125, 0.34, 0.34}, {0.125, 0.34, 0.34}, {0.125, 0.34, 0.34},
    {0.125, 0.34, 0.34}, {0.125, 0.34, 0.34}, {0.125, 0.34, 0.34},
    {0.6, 0.5, 0.1},     {0.8, 0.5, 0.4},     {0.3, 0.5, 0.9}};

design dcarEl3(windowPoints, windowColor, typeDrawing::QUADS);

container_type<design*> dcarlist{&dcarEl1, &dcarEl2, &dcarEl3};
Design dcar{dcarlist};
