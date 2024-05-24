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
/* перечисляем все объекты которые будут рисоваться на карте, то есть определяем
 * координаты х и у на которых они будут находится и тот дизайн который будет
 * использоваться для этого объекта*/
bottle obj1(0.3, 1, bottleDesign);
bottle obj2(0, 3, bottleDesign);
bottle obj3(0, 4, bottleDesign);
bottle obj4(0, 5, bottleDesign);
bottle obj5(-0.4, 7, bottleDesign);
spikes obj6(0, 2, spikesDesign);
heart obj7(0, 0, heartDesign);

/* добавляем адреса всех объектов, которые будут находится на карте
 */
container_type<track_object*> mytrackObjects{&obj1, &obj2, &obj3, &obj4,
                                             &obj5, &obj6, &obj7};
/*
создаем трек, определяя его дизайн и те объекты которые будут на нем кроме
машины
*/
track mytrack{trackDesign, mytrackObjects};

/*
создаем машину, определяя начальные координаты, дизайн, скорость, жизни, бонусы
в начале игры*/
car mycar{0, -0.425, dcar, 0, 2, 0};
