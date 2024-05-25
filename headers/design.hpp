/*
файл в котором определяются расположения объектов на карте, дизайны(внешний вид)
которых определены в mytrack.hpp, mycar.hpp, trackObjects.hpp
*/
#pragma once
#include "library.hpp"
#include "mytrack.hpp"
#include "mycar.hpp"
#include "gameMenu.hpp"
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
heart obj7(0.5, 0.5, heartDesign);
money obj8(0.5, 2, moneyDesign);
money obj9(-0.5, 2, moneyRedDesign);
breakWay obj10(0, 2, breakWayDesign);

/* добавляем адреса всех объектов, которые будут находится на карте*/
container_type<track_object*> mytrackObjects{
    &obj1, &obj2, &obj3, &obj4, &obj5, &obj6, &obj7, &obj8, &obj9, &obj10};
/*
создаем трек, определяя его дизайн и те объекты которые будут на нем кроме
машины
*/
container_type<track_object*> oneObject{&obj10};
// track mytrack{trackDesign, oneObject};
track mytrack{trackDesign, mytrackObjects};

/*
создаем машину, определяя начальные координаты, дизайн, скорость, жизни, бонусы
в начале игры
*/
car mycar{0, -0.425, dcar, 0, 2, 0};

/*
внутриигровая менюшка времени, жизней, бонусов и тд
*/

bottle bottleinMenu(-0.8, 0.9, bottleDesign, true);
heart menuHeart(-0.6, 0.9, heartDesign, true);
text text1(-0.42, 0.4, textDesign, true, "bottles");
text text2(-0.32, 0.4, textDesign, true, "lifes");
container_type<track_object*> menuElems{&bottleinMenu, &menuHeart, &text1,
                                        &text2};
track menuGame{gameMenuDesign, menuElems};
