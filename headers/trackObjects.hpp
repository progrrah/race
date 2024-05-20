/*
дизайн всех объектов на треке
1. бутылка bottle
2. шипы spikes
3. бонусы bonuses
4. разрыв дороги breakWay
5. трамплин tramplin
6. финиш finish
*/
#pragma once
#include "library.hpp"
using namespace Drawer;
using namespace Objects;
colorContainer_type bigQuadColor1{{0.2, 0.2, 0.7}};
colorContainer_type bottleColor{
    {0.41, 0.4, 0.7}, {0.4, 0.2, 0.7}, {0.3, 0.4, 0.7}};

Point b1 = {-0.1, -0.1};
Point b2 = {-0.1, 0.1};
Point b3 = {0.1, 0.1};
// Point b4 = {0.1, -0.1};

container_type<Point> bottlePrototype{b1, b2, b3};
design bottleDesignEl1(bottlePrototype, bottleColor, typeDrawing::TRIANGLES);

container_type<design*> bottleDesignElems{&bottleDesignEl1};
Design bottleDesign{bottleDesignElems};
