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
// colorContainer_type bigQuadColor1{{0.2, 0.2, 0.7}};
colorContainer_type bottleColor{
    {0.41, 0.4, 0.7}, {0.4, 0.2, 0.7}, {0.3, 0.4, 0.7}, {0.3, 0.5, 0.2}};

// colorContainer_type bottleMainColor{};
// точки для
Point b1 = {-0.1, -0.1};
Point b2 = {-0.1, 0.1};
Point b3 = {0.1, 0.1};
Point b4 = {0.1, -0.1};

container_type<Point> bottlePrototype{b1, b2, b3, b4};
design bottleDesignEl1(bottlePrototype, bottleColor, typeDrawing::QUADS);
// design bottleDesignEl2(b)
container_type<design*> bottleDesignElems{&bottleDesignEl1};
Design bottleDesign{bottleDesignElems};

colorContainer_type spikesColorMain{{0.12, 0.12, 0.12},
                                    {0.12, 0.12, 0.12},
                                    {0.12, 0.12, 0.12},
                                    {0.12, 0.12, 0.12}};
// точки для большого прямоугольника
Point spikesMainP1 = {-0.5, 0};
Point spikesMainP2 = {-0.5, 0.5};
Point spikesMainP3 = {0.5, 0.5};
Point spikesMainP4 = {0.5, 0};

container_type<Point> spikesMainPoints{spikesMainP1, spikesMainP2, spikesMainP3,
                                       spikesMainP4};
// дизайн этого прямоугольника
design spikesMain(spikesMainPoints, spikesColorMain, typeDrawing::QUADS);

colorContainer_type spikesColor{
    {0.12, 0.12, 0.12}, {0.12, 0.12, 0.12}, {0.12, 0.12, 0.12},
    {0.12, 0.12, 0.12}, {0.12, 0.12, 0.12}, {0.12, 0.12, 0.12},
    {0.12, 0.12, 0.12}, {0.12, 0.12, 0.12}, {0.12, 0.12, 0.12},
    {0.12, 0.12, 0.12}, {0.12, 0.12, 0.12}, {0.12, 0.12, 0.12},
    {0.12, 0.12, 0.12}, {0.12, 0.12, 0.12}, {0.12, 0.12, 0.12},
    {0.12, 0.12, 0.12}, {0.12, 0.12, 0.12}, {0.12, 0.12, 0.12},
};
// точки для треугольников
Point spikesTriangleP1 = {-0.5, 0};
Point spikesTriangleP2 = {-1, 0.25};
Point spikesTriangleP3 = {-0.5, 0.5};
Point spikesTriangleP4 = {-0.5, 0.5};
Point spikesTriangleP5 = {-0.25, 1};
Point spikesTriangleP6 = {0, 0.5};
Point spikesTriangleP7 = {0, 0.5};
Point spikesTriangleP8 = {0.25, 1};
Point spikesTriangleP9 = {0.5, 0.5};
Point spikesTriangleP10 = {0.5, 0.5};
Point spikesTriangleP11 = {1, 0.25};
Point spikesTriangleP12 = {0.5, 0};
Point spikesTriangleP13 = {-0.5, 0};
Point spikesTriangleP14 = {-0.25, -0.5};
Point spikesTriangleP15 = {0, 0};
Point spikesTriangleP16 = {0, 0};
Point spikesTriangleP17 = {0.25, -0.5};
Point spikesTriangleP18 = {0.5, 0};

container_type<Point> spikesTrianglePoints{
    spikesTriangleP1,  spikesTriangleP2,  spikesTriangleP3,  spikesTriangleP4,
    spikesTriangleP5,  spikesTriangleP6,  spikesTriangleP7,  spikesTriangleP8,
    spikesTriangleP9,  spikesTriangleP10, spikesTriangleP11, spikesTriangleP12,
    spikesTriangleP13, spikesTriangleP14, spikesTriangleP15, spikesTriangleP16,
    spikesTriangleP17, spikesTriangleP18};
design spikesTriangle(spikesTrianglePoints, spikesColor,
                      typeDrawing::TRIANGLES);

container_type<design*> spikesDesignElems{&spikesMain, &spikesTriangle};
Design spikesDesign{spikesDesignElems};

colorContainer_type heartColor{
    {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}};
// точки для сердца
Point heartTriangleP1 = {0, -1};
Point heartTriangleP2 = {-1, 0.5};
Point heartTriangleP3 = {1, 0.5};
container_type<Point> heartTrianglePoints{heartTriangleP1, heartTriangleP2,
                                          heartTriangleP3};
// дизайн треугсердца
design heartTriangle(heartTrianglePoints, heartColor, typeDrawing::TRIANGLES);

colorContainer_type heartColorMain{
    {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0},
    {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}};
// точки квадратов
Point heartMainP1 = {-0.2, 0.5};
Point heartMainP2 = {-1, 0.5};
Point heartMainP3 = {-1, 1};
Point heartMainP4 = {-0.2, 1};
Point heartMainP5 = {0.2, 1};
Point heartMainP6 = {0.2, 0.5};
Point heartMainP7 = {1, 0.5};
Point heartMainP8 = {1, -1};

container_type<Point> heartMainPoints{heartMainP1, heartMainP2, heartMainP3,
                                      heartMainP4, heartMainP5, heartMainP6,
                                      heartMainP7, heartMainP8};
design heartMain(heartMainPoints, heartColorMain, typeDrawing::QUADS);
container_type<design*> heartDesignElems{&heartTriangle, &heartMain};
Design heartDesign{heartDesignElems};
// монетки

// design;
