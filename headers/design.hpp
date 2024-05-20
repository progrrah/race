/*
файл в котором определяются расположения объектов на карте, дизайны(внешний вид)
которых определены в mytrack.hpp, mycar.hpp, trackObjects.hpp
*/
#pragma once
#include "library.hpp"
#include "mytrack.hpp"
#include "mycar.hpp"
#include "trackObjects.hpp"
using namespace Objects;
using namespace Drawer;
colorContainer_type rgblist{{0.2, 0.7, 0.5}};
bottle obj1(0.3, 1, bottleDesign);
bottle obj2(0, 3, bottleDesign);

container_type<track_object*> mytrackObjects{&obj1, &obj2};
car mycar{0, -0.425, dcar, 0, 2, 0};
track mytrack{trackDesign, mytrackObjects};
