#pragma once
#include "library.hpp"
#include "drawer.hpp"
using namespace Drawer;
using namespace Objects;

Point textP1 = {0, 0};
container_type<Point> points{textP1};

design textDs;
container_type<design*> textdesings{&textDs};

Design textDesign{textdesings};

Point blockPoint1 = {-0.2, -0.05};
Point blockPoint2 = {-0.2, 0.05};
Point blockPoint3 = {0.2, 0.05};
Point blockPoint4 = {0.2, -0.05};
Point blockPoint5 = {-0.2, -0.05};
container_type<Point> blockPoints{blockPoint1, blockPoint2, blockPoint3,
                                  blockPoint4, blockPoint5};
colorContainer_type blockColor{
    {0, 0, 0}, {1, 1, 1}, {1, 1, 1}, {0, 0, 0}, {1, 1, 1}};
design blockDs{blockPoints, blockColor, typeDrawing::LINES, 1};
container_type<design*> blockdesigns{&blockDs};

Design blockDesign{blockdesigns};

Point blockEndPoint1 = {-0.4, -0.05};
Point blockEndPoint2 = {-0.4, 0.05};
Point blockEndPoint3 = {0.4, 0.05};
Point blockEndPoint4 = {0.4, -0.05};
Point blockEndPoint5 = {-0.4, -0.05};
container_type<Point> blockEndPoints{blockEndPoint1, blockEndPoint2,
                                     blockEndPoint3, blockEndPoint4,
                                     blockEndPoint5};
colorContainer_type blockEndColor{
    {0, 0, 0}, {1, 1, 1}, {1, 1, 1}, {0, 0, 0}, {1, 1, 1}};
design blockEndDs{blockEndPoints, blockEndColor, typeDrawing::LINES, 10};
container_type<design*> blockEnddesigns{&blockEndDs};

Design blockEndDesign{blockEnddesigns};
