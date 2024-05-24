#pragma once
#include "library.hpp"
#include "gameMenuElems.hpp"
using namespace Drawer;
using namespace Objects;
container_type<container_type<double>> menuMainColor{
    {0.1, 0.2, 0.7}, {0.3, 0.2, 0.7}, {0.1, 0.4, 0.7}, {0.9, 0.2, 0.7}};
container_type<container_type<double>> menuLineColor{
    {0.2, 0.2, 0.1}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.3}, {0.2, 0.7, 0.7}};

Drawer::Point menuMainPoint1{-0.85, 0.75};
Drawer::Point menuMainPoint2{-0.85, 1};
Drawer::Point menuMainPoint3{-0.5, 1};
Drawer::Point menuMainPoint4{-0.5, 0.75};

// Drawer::Point menuLinePoint1{-0.05, -1};
// Drawer::Point menuLinePoint2{-0.05, 1};
// Drawer::Point menuLinePoint3{0.05, 1};
// Drawer::Point menuLinePoint4{0.05, -1};
container_type<Point> menuMainPoints{menuMainPoint1, menuMainPoint2,
                                     menuMainPoint3, menuMainPoint4};
design gameMenuMain{menuMainPoints, menuMainColor, typeDrawing::QUADS};
container_type<design*> gameMenuMainDesigns{&gameMenuMain};

Design gameMenuDesign{gameMenuMainDesigns};