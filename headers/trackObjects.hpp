/*
дизайн всех объектов на треке
1. бутылка bottle
2. шипы spikes
3. бонусы bonuses
4. разрыв дороги breakWay
5. трамплин tramplin
6. финиш finish
7. деньги money
*/
#pragma once
#include "library.hpp"
using namespace Drawer;
using namespace Objects;
// описываем внешний вид бутылки
colorContainer_type bottleColor{
    {0.41, 0.4, 0.7}, {0.4, 0.2, 0.7}, {0.3, 0.4, 0.7}, {0.3, 0.5, 0.2}};

Point b1 = {-0.05, -0.05};
Point b2 = {-0.05, 0.05};
Point b3 = {0.05, 0.05};
Point b4 = {0.05, -0.05};

container_type<Point> bottlePrototype{b1, b2, b3, b4};

design bottleDesignEl1(bottlePrototype, bottleColor, typeDrawing::QUADS);

container_type<design*> bottleDesignElems{&bottleDesignEl1};
Design bottleDesign{bottleDesignElems};

// описываем внешний вид шипов
colorContainer_type spikesColorMain{{0.12, 0.12, 0.12},
                                    {0.12, 0.12, 0.12},
                                    {0.12, 0.12, 0.12},
                                    {0.12, 0.12, 0.12}};
// точки для большого прямоугольника
Point spikesMainP1 = {-0.1, 0};
Point spikesMainP2 = {-0.1, 0.1};
Point spikesMainP3 = {0.1, 0.1};
Point spikesMainP4 = {0.1, 0};

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
Point spikesTriangleP1 = {-0.1, 0};
Point spikesTriangleP2 = {-0.2, 0.05};
Point spikesTriangleP3 = {-0.1, 0.1};
Point spikesTriangleP4 = {-0.1, 0.1};
Point spikesTriangleP5 = {-0.05, 0.2};
Point spikesTriangleP6 = {0, 0.1};
Point spikesTriangleP7 = {0, 0.1};
Point spikesTriangleP8 = {0.05, 0.2};
Point spikesTriangleP9 = {0.1, 0.1};
Point spikesTriangleP10 = {0.1, 0.1};
Point spikesTriangleP11 = {0.2, 0.05};
Point spikesTriangleP12 = {0.1, 0};
Point spikesTriangleP13 = {-0.1, 0};
Point spikesTriangleP14 = {-0.05, -0.1};
Point spikesTriangleP15 = {0, 0};
Point spikesTriangleP16 = {0, 0};
Point spikesTriangleP17 = {0.05, -0.1};
Point spikesTriangleP18 = {0.1, 0};

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

// описываем внешний вид сердца
colorContainer_type heartColor{
    {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}};
// точки для сердца
Point heartTriangleP1 = {-0.05, 0};
Point heartTriangleP2 = {0, -0.05};
Point heartTriangleP3 = {0.05, 0};
container_type<Point> heartTrianglePoints{heartTriangleP1, heartTriangleP2,
                                          heartTriangleP3};
// дизайн треугсердца
design heartTriangle(heartTrianglePoints, heartColor, typeDrawing::TRIANGLES);

colorContainer_type heartColorMain{
    {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0},
    {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}};
// точки квадратов
Point heartMainP1 = {-0.05, 0};
Point heartMainP2 = {-0.03, 0.03};
Point heartMainP4 = {0.0, 0};

Point heartMainP5 = {0.0, 0};
Point heartMainP6 = {0.03, 0.03};
Point heartMainP8 = {0.05, 0};

container_type<Point> heartMainPoints{heartMainP1, heartMainP2, heartMainP4,
                                      heartMainP5, heartMainP6, heartMainP8};
design heartMain(heartMainPoints, heartColorMain, typeDrawing::TRIANGLES);
/* здесь большое сердце
 */
// Point heartMainP1 = {-0.07, 0};
// Point heartMainP2 = {-0.05, 0.05};
// Point heartMainP3 = {-0.01, 0.05};
// Point heartMainP4 = {-0.01, 0};
// Point heartMainP5 = {0.01, 0};
// Point heartMainP6 = {0.01, 0.05};
// Point heartMainP7 = {0.05, 0.05};
// Point heartMainP8 = {0.07, 0};

// container_type<Point> heartMainPoints{heartMainP1, heartMainP2, heartMainP3,
//                                       heartMainP4, heartMainP5, heartMainP6,
//                                       heartMainP7, heartMainP8};
// design heartMain(heartMainPoints, heartColorMain, typeDrawing::QUADS);

container_type<design*> heartDesignElems{&heartTriangle, &heartMain};
Design heartDesign{heartDesignElems};

// описываем внешний вид монеток

colorContainer_type moneyColor{
    // желтые для + бонусов
    {1.0, 1.0, 0.0}, {1.0, 1.0, 0.0}, {1.0, 1.0, 0.0}, {1.0, 1.0, 0.0},
    {1.0, 0.5, 0.0}, {1.0, 0.5, 0.0}, {1.0, 0.5, 0.0}, {1.0, 0.5, 0.0}};
// точки для сердца
Point MoneyP1 = {-0.05, -0.05};
Point MoneyP2 = {-0.05, 0.05};
Point MoneyP3 = {0.05, 0.05};
Point MoneyP4 = {0.05, -0.05};
Point MoneyP5 = {-0.025, -0.025};
Point MoneyP6 = {-0.025, 0.025};
Point MoneyP7 = {0.025, 0.025};
Point MoneyP8 = {0.025, -0.025};

container_type<Point> moneyPoints{MoneyP1, MoneyP2, MoneyP3, MoneyP4,
                                  MoneyP5, MoneyP6, MoneyP7, MoneyP8};
// дизайн треугсердца
design moneymoney(moneyPoints, moneyColor, typeDrawing::QUADS);

container_type<design*> moneyDesignElems{&moneymoney};
Design moneyDesign{moneyDesignElems};

colorContainer_type moneyRedColor{
    // красные для - бонусов
    {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0},
    {1.0, 0.1, 0.1}, {1.0, 0.1, 0.1}, {1.0, 0.1, 0.1}, {1.0, 0.1, 0.1}};
// точки для сердца
Point MoneyRedP1 = {-0.05, -0.05};
Point MoneyRedP2 = {-0.05, 0.05};
Point MoneyRedP3 = {0.05, 0.05};
Point MoneyRedP4 = {0.05, -0.05};
Point MoneyRedP5 = {-0.025, -0.025};
Point MoneyRedP6 = {-0.025, 0.025};
Point MoneyRedP7 = {0.025, 0.025};
Point MoneyRedP8 = {0.025, -0.025};

container_type<Point> moneyRedPoints{MoneyRedP1, MoneyRedP2, MoneyRedP3,
                                     MoneyRedP4, MoneyRedP5, MoneyRedP6,
                                     MoneyRedP7, MoneyRedP8};
// дизайн треугсердца
design moneyRedmoney(moneyRedPoints, moneyRedColor, typeDrawing::QUADS);

container_type<design*> moneyRedDesignElems{&moneyRedmoney};
Design moneyRedDesign{moneyRedDesignElems};

// описываем внешний вид финиша
// описываем внешний вид трамплина
// описываем внешний вид разрыва дороги
colorContainer_type breakWayColor{
    {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
// точки для большого прямоугольника
Point breakWayP1 = {-0.75, 0};
Point breakWayP2 = {-0.75, 0.1};
Point breakWayP3 = {0.75, 0.1};
Point breakWayP4 = {0.75, 0};

container_type<Point> breakWayPoints{breakWayP1, breakWayP2, breakWayP3,
                                     breakWayP4};
// дизайн этого прямоугольника
design breakWayDs1(breakWayPoints, breakWayColor, typeDrawing::QUADS);

container_type<design*> breakWayDesignElems{&breakWayDs1};

Design breakWayDesign{breakWayDesignElems};
