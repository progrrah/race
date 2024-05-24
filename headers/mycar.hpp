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
    {0.4, 0.2, 0.35}, {0.5, 0.2, 0.35}, {0.9, 0.3, 0.1}, {0.9, 0.1, 0.4}};
// container_type<container_type<double>> carColor{
//     {0.5, 0.2, 0.1}, {0.9, 0.2, 0.1}, {0.9, 0.1, 0.35}, {0.5, 0.1, 0.35}};

// дизайн машины
design dcarEl1(mainPoints, carColor, typeDrawing::QUADS);

//// Колеса1
Point carWheelPoint1 = {-0.1, 0.1};
Point carWheelPoint2 = {-0.14, 0.1};
Point carWheelPoint3 = {-0.14, 0.15};
Point carWheelPoint4 = {-0.1, 0.15};

////Колеса2
Point carWheelPoint5 = {-0.1, -0.1};
Point carWheelPoint6 = {-0.14, -0.1};
Point carWheelPoint7 = {-0.14, -0.05};
Point carWheelPoint8 = {-0.1, -0.05};

////Колеса3
Point carWheelPoint9 = {0.1, 0.1};
Point carWheelPoint10 = {0.1, 0.15};
Point carWheelPoint11 = {0.14, 0.15};
Point carWheelPoint12 = {0.14, 0.1};

////Колеса4
Point carWheelPoint13 = {0.1, -0.1};
Point carWheelPoint14 = {0.1, -0.05};
Point carWheelPoint15 = {0.14, -0.05};
Point carWheelPoint16 = {0.14, -0.1};

container_type<Point> wheelPoints = {
    carWheelPoint1,  carWheelPoint2,  carWheelPoint3,  carWheelPoint4,
    carWheelPoint5,  carWheelPoint6,  carWheelPoint7,  carWheelPoint8,
    carWheelPoint9,  carWheelPoint10, carWheelPoint11, carWheelPoint12,
    carWheelPoint13, carWheelPoint14, carWheelPoint15, carWheelPoint16};
container_type<container_type<double>> wheelColor = {
    {0.4, 0.0, 0.1}, {0.0, 0.0, 0.1}, {0.0, 0.0, 0.1}, {0.0, 0.0, 0.8},
    {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};

design dcarEl2(wheelPoints, wheelColor, typeDrawing::QUADS);

/// Окна1
Point carWindowPoints1 = {-0.05, 0.075};
Point carWindowPoints2 = {-0.05, 0.1125};
Point carWindowPoints3 = {0.05, 0.1125};
Point carWindowPoints4 = {0.05, 0.075};

// Окна2
Point carWindowPoints5 = {-0.09, -0.09};
Point carWindowPoints6 = {-0.09, 0.07};
Point carWindowPoints7 = {-0.07, 0.07};
Point carWindowPoints8 = {-0.07, -0.09};

// Окна3
Point carWindowPoints9 = {0.07, -0.09};
Point carWindowPoints10 = {0.07, 0.07};
Point carWindowPoints11 = {0.09, 0.07};
Point carWindowPoints12 = {0.09, -0.09};

// Окна4
Point carWindowPoints13 = {-0.15, -0.15};
Point carWindowPoints14 = {-0.15, -0.13};
Point carWindowPoints15 = {0.15, -0.13};
Point carWindowPoints16 = {0.15, -0.15};

container_type<Point> windowPoints = {
    carWindowPoints1,  carWindowPoints2,  carWindowPoints3,  carWindowPoints4,
    carWindowPoints5,  carWindowPoints6,  carWindowPoints7,  carWindowPoints8,
    carWindowPoints9,  carWindowPoints10, carWindowPoints11, carWindowPoints12,
    carWindowPoints13, carWindowPoints14, carWindowPoints15, carWindowPoints16};
container_type<container_type<double>> windowColor = {
    {0.8, 0.5, 0.4}, {0.1, 0.3, 0.3}, {0.8, 0.5, 0.4}, {0.3, 0.5, 0.9},
    {0.1, 0.3, 0.3}, {0.6, 0.5, 0.1}, {0.1, 0.3, 0.3}, {0.8, 0.5, 0.4},
    {0.1, 0.3, 0.3}, {0.6, 0.5, 0.1}, {0.8, 0.5, 0.4}, {0.3, 0.5, 0.9},
    {0.1, 0.3, 0.3}, {0.8, 0.5, 0.4}, {0.1, 0.3, 0.3}, {0.1, 0.3, 0.3}};

design dcarEl3(windowPoints, windowColor, typeDrawing::QUADS);

container_type<design*> dcarlist{&dcarEl1, &dcarEl2, &dcarEl3};
Design dcar{dcarlist};
