#pragma once
#include "gameMenuElems.hpp"
#include "trackObjects.hpp"
#include "library.hpp"
extern std::string BONUSES_IN_STRING;
extern std::string LIFES_IN_STRING;
extern std::string TIME_IN_STRING;
extern Design trackDesign;
using namespace Drawer;
using namespace Objects;
container_type<container_type<double>> menuMainColor{
    {0.9, 0.5, 0.5}, {0.8, 1, 1}, {0.7, 0.9, 06}, {1, 0.5, 0.7}};
container_type<container_type<double>> menuLineColor{
    {0.2, 0.2, 0.1}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.3}, {0.2, 0.7, 0.7}};

Drawer::Point menuMainPoint1{-0.85, 0.75};
Drawer::Point menuMainPoint2{-0.85, 1};
Drawer::Point menuMainPoint3{-0.5, 1};
Drawer::Point menuMainPoint4{-0.5, 0.75};

container_type<Point> menuMainPoints{menuMainPoint1, menuMainPoint2,
                                     menuMainPoint3, menuMainPoint4};
design gameMenuMain{menuMainPoints, menuMainColor, typeDrawing::QUADS};
container_type<design *> gameMenuMainDesigns{&gameMenuMain};

Design gameMenuDesign{gameMenuMainDesigns};

/*
внутриигровая менюшка времени, жизней, бонусов и тд
*/

money bottleinMenu(-0.80, 0.9, moneyDesign, 100, true);
heart heartinMenu(-0.6, 0.9, heartDesign, true);

std::string textString = "";
text textTemplate(0., 0., textDesign, true, &textString);
text textBonus(-0.42, 0.4, textDesign, true, &BONUSES_IN_STRING);
text textTime(0.315, -0.405, textDesign, true, &TIME_IN_STRING);
text textLifes(-0.305, 0.4, textDesign, true, &LIFES_IN_STRING);

block blockMenu(0.65, -0.8, blockDesign, true);

container_type<track_object *> menuElems{
    &textTemplate, &textBonus,   &textTime, &textLifes,
    &bottleinMenu, &heartinMenu, &blockMenu};
track menuGame;
track initmenuGame{gameMenuDesign, menuElems};

std::string textEnd = {"YOU'RE WINNER"};
text END_TEXT(-0.1, 0., textDesign, true, &textEnd);
block END_BLOCK(0., 0., blockEndDesign, true);
container_type<track_object *> endMenu{&END_TEXT, &END_BLOCK};

track menuEnd{trackDesign, endMenu};