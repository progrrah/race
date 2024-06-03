/*здесь дизайн трека*/
#pragma once
#include "library.hpp"
using namespace Drawer;
using namespace Objects;
container_type<container_type<double>> trackMainColor{
    {0.7, 0.3, 0.6}, {0.7, 0.3, 0.6}, {0.6, 0.8, 0.9}, {0.6, 0.9, 0.9}};
container_type<container_type<double>> trackLineColor{
    {0.2, 0.2, 0.1}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.3}, {0.2, 0.7, 0.7}};
////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////  track design
////////////////////////////////////////////////////////////////////////////////////////////////////////
Drawer::Point trackMainPoint1{-0.85, -1};
Drawer::Point trackMainPoint2{-0.85, 1};
Drawer::Point trackMainPoint3{0.85, 1};
Drawer::Point trackMainPoint4{0.85, -1};

Drawer::Point trackLinePoint1{-0.05, -1};
Drawer::Point trackLinePoint2{-0.05, 1};
Drawer::Point trackLinePoint3{0.05, 1};
Drawer::Point trackLinePoint4{0.05, -1};

container_type<Point> pointLists{
    trackMainPoint1, trackMainPoint2, trackMainPoint3, trackMainPoint4,
    trackLinePoint1, trackLinePoint2, trackLinePoint3, trackLinePoint4};
container_type<Point> plist1{trackMainPoint1, trackMainPoint2, trackMainPoint3,
                             trackMainPoint4};
container_type<Point> plist2{trackLinePoint1, trackLinePoint2, trackLinePoint3,
                             trackLinePoint4};

design ds1(plist1, trackMainColor, typeDrawing::QUADS);
design ds2(plist2, trackLineColor, typeDrawing::QUADS);
// дизайн трэка из двух прямоугольников
container_type<design*> designs{&ds1, &ds2};
Design trackDesign{designs};
