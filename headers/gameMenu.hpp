#pragma once
#include "gameMenuElems.hpp"
#include "trackObjects.hpp"
#include "library.hpp"
extern std::string BONUSES_IN_STRING;
extern std::string LIFES_IN_STRING;
extern std::string TIME_IN_STRING;
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
container_type<design *> gameMenuMainDesigns{&gameMenuMain};

Design gameMenuDesign{gameMenuMainDesigns};

/*
внутриигровая менюшка времени, жизней, бонусов и тд
*/

money bottleinMenu(-0.80, 0.9, moneyDesign, 100, true);
heart menuHeart(-0.6, 0.9, heartDesign, true);
// for correct color selecting

std::string textString = "LOLOL";
// text textRandom(-1, -1, textDesign, true, "lol");

// colorContainer_type textLifesColorList{{0.9, 0., 1.},
//                                        {0.2, 0.3, 1.},
//                                        {0.9, 0., 0.9},
//                                        {0.9, 0.3, 1.},
//                                        {0.3, 0.9, 1.}};
// text textLifes(-0.32, 0.4, textDesign, textLifesColorList, true, "lifes");
// text textMoney(-0.42, 0.4, textDesign, true, "money");
// text textNumberMoney(-0.3, 0.38, textDesign, true, "2");
// text textNumberLifes(-0.42, 0.38, textDesign, true, "2000");

// container_type<track_object *> menuElems{
//     &bottleinMenu, &menuHeart,       &textRandom,     &textMoney,
//     &textLifes,    &textNumberMoney, &textNumberLifes};
text textTemplate(0., 0., textDesign, true, &textString);
text textBonus(-0.42, 0.38, textDesign, true, &BONUSES_IN_STRING);
text textTime(-0.42, 0.28, textDesign, true, &TIME_IN_STRING);
text textLifes(-0.42, 0.18, textDesign, true, &LIFES_IN_STRING);

container_type<track_object *> menuElems{&textTemplate, &textBonus,
                                         &textTime,     &textLifes,
                                         &bottleinMenu, &menuHeart};
track menuGame{gameMenuDesign, menuElems};