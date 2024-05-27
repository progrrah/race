/*
дизайн всех объектов на треке
1. бутылка bottle
2. шипы spikes
3. бонусы money
4. разрыв дороги breakWay
5. трамплин tramplin
6. финиш finish
7. шестерня gear
8. сердце heart
*/
#pragma once
#include "library.hpp"
using namespace Drawer;
using namespace Objects;
// описываем внешний вид бутылки
colorContainer_type bottleMainColor{
    {1, 0.4, 0.7}, {1, 0.6, 0.7}, {1, 0.8, 0.7}, {1, 0.8, 0.7}};

Point b1 = {-0.03, -0.05};
Point b2 = {-0.03, 0.05};
Point b3 = {0.03, 0.05};
Point b4 = {0.03, -0.05};

container_type<Point> bottlePrototype{b1, b2, b3, b4};
design bottleDesignEl1(bottlePrototype, bottleMainColor, typeDrawing::QUADS);

colorContainer_type bottleSmallColor{
    {0., 0., 0.}, {0., 0., 0.}, {0., 0., 0.}, {0., 0., 0.9}};

Point bottleSmallPoint1 = {-0.02, 0.05};
Point bottleSmallPoint2 = {-0.02, 0.06};
Point bottleSmallPoint3 = {0.02, 0.06};
Point bottleSmallPoint4 = {0.02, 0.05};

container_type<Point> bottleSmallPoints{bottleSmallPoint1, bottleSmallPoint2,
                                        bottleSmallPoint3, bottleSmallPoint4};

design bottleDesignEl2(bottleSmallPoints, bottleSmallColor, typeDrawing::QUADS);

container_type<design*> bottleDesignElems{&bottleDesignEl1, &bottleDesignEl2};
Design bottleDesign{bottleDesignElems};

// описываем внешний вид шипов
colorContainer_type spikesColorMain{
    {0.5, 0.0, 0.5}, {0.5, 0.0, 0.5}, {0.5, 0.0, 0.5}, {0.5, 0.0, 0.5},
    {0.5, 0.0, 0.5}, {0.5, 0.0, 0.5}, {0.5, 0.0, 0.5}, {0.5, 0.0, 0.5},
    {0.5, 0.0, 0.5}, {0.5, 0.0, 0.5}, {0.5, 0.0, 0.5}, {0.5, 0.0, 0.5},
};
// точки для большого прямоугольника
Point spikesMainP1 = {-0.05, 0};
Point spikesMainP2 = {-0.05, 0.05};
Point spikesMainP3 = {0.05, 0.05};
Point spikesMainP4 = {0.05, 0};

container_type<Point> spikesMainPoints{spikesMainP1, spikesMainP2, spikesMainP3,
                                       spikesMainP4};
// дизайн этого прямоугольника
design spikesMain(spikesMainPoints, spikesColorMain, typeDrawing::QUADS);

colorContainer_type spikesColor{
    {0.5, 0.0, 0.5}, {0.5, 0.0, 0.5}, {0.5, 0.0, 0.5}, {0.5, 0.0, 0.5},
    {0.5, 0.0, 0.5}, {0.5, 0.0, 0.5}, {0.5, 0.0, 0.5}, {0.5, 0.0, 0.5},
    {0.5, 0.0, 0.5}, {0.5, 0.0, 0.5}, {0.5, 0.0, 0.5}, {0.5, 0.0, 0.5},
    {0.5, 0.0, 0.5}, {0.5, 0.0, 0.5}, {0.5, 0.0, 0.5}, {0.5, 0.0, 0.5},
    {0.5, 0.0, 0.5}, {0.5, 0.0, 0.5},
};
// точки для треугольников
Point spikesTriangleP1 = {-0.05, 0};
Point spikesTriangleP2 = {-0.1, 0.025};
Point spikesTriangleP3 = {-0.05, 0.05};
Point spikesTriangleP4 = {-0.05, 0.05};
Point spikesTriangleP5 = {-0.025, 0.1};
Point spikesTriangleP6 = {0, 0.05};
Point spikesTriangleP7 = {0, 0.05};
Point spikesTriangleP8 = {0.025, 0.1};
Point spikesTriangleP9 = {0.05, 0.05};
Point spikesTriangleP10 = {0.05, 0.05};
Point spikesTriangleP11 = {0.1, 0.025};
Point spikesTriangleP12 = {0.05, 0};
Point spikesTriangleP13 = {-0.05, 0};
Point spikesTriangleP14 = {-0.025, -0.05};
Point spikesTriangleP15 = {0, 0};
Point spikesTriangleP16 = {0, 0};
Point spikesTriangleP17 = {0.025, -0.05};
Point spikesTriangleP18 = {0.05, 0};

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
container_type<design*> heartDesignElems{&heartTriangle, &heartMain};
Design heartDesign{heartDesignElems};

// описываем внешний вид монеток

colorContainer_type moneyColor{
    // желтые для + бонусов
    {1.0, 0.7, 0.0}, {1.0, 0.7, 0.0}, {1.0, 0.7, 0.0}, {1.0, 0.7, 0.0},
    {1.0, 0.7, 0.0}, {1.0, 0.7, 0.0}, {1.0, 0.7, 0.0}, {1.0, 0.7, 0.0},
    {1.0, 0.7, 0.0}, {1.0, 0.7, 0.0}, {1.0, 0.7, 0.0}, {1.0, 0.7, 0.0},
    {1.0, 0.8, 0.0}, {1.0, 0.8, 0.0}, {1.0, 0.8, 0.0}, {1.0, 0.8, 0.0}};
// точки для сердца
Point MoneyP1 = {-0.05, 0.025};
Point MoneyP2 = {-0.05, -0.025};
Point MoneyP3 = {0.05, -0.025};
Point MoneyP4 = {0.05, 0.025};
Point MoneyP5 = {-0.05, 0.025};
Point MoneyP6 = {-0.025, 0.05};
Point MoneyP7 = {0.025, 0.05};
Point MoneyP8 = {0.05, 0.025};
Point MoneyP9 = {-0.05, -0.025};
Point MoneyP10 = {-0.025, -0.05};
Point MoneyP11 = {0.025, -0.05};
Point MoneyP12 = {0.05, -0.025};
Point MoneyP13 = {-0.025, 0.025};
Point MoneyP14 = {-0.025, -0.025};
Point MoneyP15 = {0.025, -0.025};
Point MoneyP16 = {0.025, 0.025};

container_type<Point> moneyPoints{MoneyP1,  MoneyP2,  MoneyP3,  MoneyP4,
                                  MoneyP5,  MoneyP6,  MoneyP7,  MoneyP8,
                                  MoneyP9,  MoneyP10, MoneyP11, MoneyP12,
                                  MoneyP13, MoneyP14, MoneyP15, MoneyP16};
// дизайн треугсердца
design moneymoney(moneyPoints, moneyColor, typeDrawing::QUADS);

container_type<design*> moneyDesignElems{&moneymoney};
Design moneyDesign{moneyDesignElems};

colorContainer_type moneyRedColor{
    // красные для - бонусов
    {0.7, 0.0, 0.0}, {0.7, 0.0, 0.0}, {0.7, 0.0, 0.0}, {0.7, 0.0, 0.0},
    {0.7, 0.0, 0.0}, {0.7, 0.0, 0.0}, {0.7, 0.0, 0.0}, {0.7, 0.0, 0.0},
    {0.7, 0.0, 0.0}, {0.7, 0.0, 0.0}, {0.7, 0.0, 0.0}, {0.7, 0.0, 0.0},
    {0.7, 0.0, 0.3}, {0.7, 0.0, 0.3}, {0.7, 0.0, 0.3}, {0.7, 0.0, 0.3}};

Point MoneyRedP1 = {-0.05, 0.025};
Point MoneyRedP2 = {-0.05, -0.025};
Point MoneyRedP3 = {0.05, -0.025};
Point MoneyRedP4 = {0.05, 0.025};
Point MoneyRedP5 = {-0.05, 0.025};
Point MoneyRedP6 = {-0.025, 0.05};
Point MoneyRedP7 = {0.025, 0.05};
Point MoneyRedP8 = {0.05, 0.025};
Point MoneyRedP9 = {-0.05, -0.025};
Point MoneyRedP10 = {-0.025, -0.05};
Point MoneyRedP11 = {0.025, -0.05};
Point MoneyRedP12 = {0.05, -0.025};
Point MoneyRedP13 = {-0.025, 0.025};
Point MoneyRedP14 = {-0.025, -0.025};
Point MoneyRedP15 = {0.025, -0.025};
Point MoneyRedP16 = {0.025, 0.025};

container_type<Point> moneyRedPoints{
    MoneyRedP1,  MoneyRedP2,  MoneyRedP3,  MoneyRedP4,
    MoneyRedP5,  MoneyRedP6,  MoneyRedP7,  MoneyRedP8,
    MoneyRedP9,  MoneyRedP10, MoneyRedP11, MoneyRedP12,
    MoneyRedP13, MoneyRedP14, MoneyRedP15, MoneyRedP16};
// дизайн треугсердца
design moneyRedmoney(moneyRedPoints, moneyRedColor, typeDrawing::QUADS);

container_type<design*> moneyRedDesignElems{&moneyRedmoney};
Design moneyRedDesign{moneyRedDesignElems};

// описываем внешний вид трамплина
// описываем внешний вид разрыва дороги
colorContainer_type breakWayColor{
    {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
// точки для большого прямоугольника
Point breakWayP1 = {-0.85, 0};
Point breakWayP2 = {-0.85, 0.05};
Point breakWayP3 = {0.85, 0.05};
Point breakWayP4 = {0.85, 0};

container_type<Point> breakWayPoints{breakWayP1, breakWayP2, breakWayP3,
                                     breakWayP4};
// дизайн этого прямоугольника
design breakWayDs1(breakWayPoints, breakWayColor, typeDrawing::QUADS);

container_type<design*> breakWayDesignElems{&breakWayDs1};

Design breakWayDesign{breakWayDesignElems};

// описываем внешний вид финиша
colorContainer_type finishColor{
    // желтые для + бонусов
    {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0},
    {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0},
    {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0},
    {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0},
    {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0},
    {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0},
    {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0},
    {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0},
    {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0},
    {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0},
    {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0},
    {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0},
};
// точки для сердца
Point finishP1 = {-0.85, 0};
Point finishP2 = {-0.85, 0.1};
Point finishP3 = {-0.5, 0.1};
Point finishP4 = {-0.5, 0};
Point finishP5 = {-0.5, 0.1};
Point finishP6 = {-0.25, 0.1};
Point finishP7 = {-0.25, 0};
Point finishP8 = {-0.5, 0};
Point finishP9 = {-0.25, 0};
Point finishP10 = {-0.25, 0.1};
Point finishP11 = {0, 0.1};
Point finishP12 = {0, 0};
Point finishP13 = {0, 0};
Point finishP14 = {0, 0.1};
Point finishP15 = {0.25, 0.1};
Point finishP16 = {0.25, 0};
Point finishP17 = {0.25, 0};
Point finishP18 = {0.25, 0.1};
Point finishP19 = {0.5, 0.1};
Point finishP20 = {0.5, 0};
Point finishP21 = {0.5, 0};
Point finishP22 = {0.5, 0.1};
Point finishP23 = {0.85, 0.1};
Point finishP24 = {0.85, 0};
Point finishP25 = {-0.85, 0};
Point finishP26 = {-0.5, 0};
Point finishP27 = {-0.5, -0.1};
Point finishP28 = {-0.85, -0.1};
Point finishP29 = {-0.5, 0};
Point finishP30 = {-0.25, 0};
Point finishP31 = {-0.25, -0.1};
Point finishP32 = {-0.5, -0.1};
Point finishP33 = {-0.85, 0};
Point finishP34 = {0, 0};
Point finishP35 = {0, -0.1};
Point finishP36 = {-0.25, -0.1};
Point finishP37 = {0, 0};
Point finishP38 = {0.25, 0};
Point finishP39 = {0.25, -0.1};
Point finishP40 = {0, -0.1};
Point finishP41 = {0.25, 0};
Point finishP42 = {0.5, 0};
Point finishP43 = {0.5, -0.1};
Point finishP44 = {0.25, -0.1};
Point finishP45 = {0.5, 0};
Point finishP46 = {0.85, 0};
Point finishP47 = {0.85, -0.1};
Point finishP48 = {0.5, -0.1};

container_type<Point> finishPoints{
    finishP1,  finishP2,  finishP3,  finishP4,  finishP5,  finishP6,  finishP7,
    finishP8,  finishP9,  finishP10, finishP11, finishP12, finishP13, finishP14,
    finishP15, finishP16, finishP17, finishP18, finishP19, finishP20, finishP21,
    finishP22, finishP23, finishP24, finishP25, finishP26, finishP27, finishP28,
    finishP29, finishP30, finishP31, finishP32, finishP33, finishP34, finishP35,
    finishP36, finishP37, finishP38, finishP39, finishP40, finishP41, finishP42,
    finishP43, finishP44, finishP45, finishP46, finishP47, finishP48};

design finishDs1(finishPoints, finishColor, typeDrawing::QUADS);

container_type<design*> finishDesignElems{&finishDs1};
Design finishDesign{finishDesignElems};
// трамплин tramplin
colorContainer_type tramplinColor{
    {0.6, 0.3, 0.5}, {0.6, 0.3, 0.5}, {0.6, 0.4, 0.4}, {0.6, 0.4, 0.4},
    {0.6, 0.5, 0.6}, {0.6, 0.5, 0.6}, {0.6, 0.5, 0.6}, {0.6, 0.5, 0.6}};
Point tramplinP1 = {-0.1, 0.15};
Point tramplinP2 = {0.1, 0.15};
Point tramplinP3 = {0.1, -0.1};
Point tramplinP4 = {-0.1, -0.1};
Point tramplinP5 = {-0.05, 0.15};
Point tramplinP6 = {-0.05, 0.2};
Point tramplinP7 = {0.05, 0.2};
Point tramplinP8 = {0.05, 0.15};
container_type<Point> tramplinPoints{tramplinP1, tramplinP2, tramplinP3,
                                     tramplinP4, tramplinP5, tramplinP6,
                                     tramplinP7, tramplinP8};

design tramplinDs1(tramplinPoints, tramplinColor, typeDrawing::QUADS);
container_type<design*> tramplinDesignElems{&tramplinDs1};
Design tramplinDesign{tramplinDesignElems};

colorContainer_type gearColor{
    // желтые для + бонусов
    {0.8, 0.9, 1},   {0.8, 0.9, 1},   {0.8, 0.9, 1},   {0.8, 0.9, 1},
    {0.8, 0.9, 1},   {0.8, 0.9, 1},   {0.8, 0.9, 1},   {0.8, 0.9, 1},
    {0.8, 0.9, 1},   {0.8, 0.9, 1},   {0.8, 0.9, 1},   {0.8, 0.9, 1},
    {0.6, 0.8, 0.9}, {0.6, 0.8, 0.9}, {0.6, 0.8, 0.9}, {0.6, 0.8, 0.9}};
// точки для сердца
Point GearP1 = {-0.05, 0.025};
Point GearP2 = {-0.05, -0.025};
Point GearP3 = {0.05, -0.025};
Point GearP4 = {0.05, 0.025};
Point GearP5 = {-0.05, 0.025};
Point GearP6 = {-0.025, 0.05};
Point GearP7 = {0.025, 0.05};
Point GearP8 = {0.05, 0.025};
Point GearP9 = {-0.05, -0.025};
Point GearP10 = {-0.025, -0.05};
Point GearP11 = {0.025, -0.05};
Point GearP12 = {0.05, -0.025};
Point GearP13 = {-0.025, 0.025};
Point GearP14 = {-0.025, -0.025};
Point GearP15 = {0.025, -0.025};
Point GearP16 = {0.025, 0.025};

container_type<Point> gearPoints{
    GearP1, GearP2,  GearP3,  GearP4,  GearP5,  GearP6,  GearP7,  GearP8,
    GearP9, GearP10, GearP11, GearP12, GearP13, GearP14, GearP15, GearP16};
// дизайн треугсердца
design geardesigns(gearPoints, gearColor, typeDrawing::QUADS);

container_type<design*> gearDesignElems{&geardesigns};
Design gearDesign{gearDesignElems};
