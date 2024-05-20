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
container_type<container_type<double>> rgblist{{0.2, 0.7, 0.5}};
bottle obj1(0.3, 1, dstrObj2);
bottle obj2(0, 3, dstrObj2);

container_type<track_object*> mytrackObjects{&obj1, &obj2};
car mycar{0, -0.425, dcar, 0, 2, 0};
track mytrack{designs, mytrackObjects};
