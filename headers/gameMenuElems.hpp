#pragma once
#include "library.hpp"
using namespace Drawer;
using namespace Objects;

Point textP1 = {0, 0};
container_type<Point> points{textP1};

design textDs;
container_type<design*> textdesings{&textDs};

Design textDesign{textdesings};