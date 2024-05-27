/*
файл в котором определяются расположения объектов на карте, дизайны(внешний вид)
которых определены в mytrack.hpp, mycar.hpp, trackObjects.hpp
*/
#pragma once
#include "gameMenu.hpp"
#include "library.hpp"
#include "mycar.hpp"
#include "mytrack.hpp"
#include "trackObjects.hpp"
// #include "interaction.hpp"
using namespace Objects;
using namespace Drawer;
extern std::string BONUSES_IN_STRING;
extern std::string LIFES_IN_STRING;
extern std::string TIME_IN_STRING;
/* перечисляем все объекты которые будут рисоваться на карте, то есть определяем
 * координаты х и у на которых они будут находится и тот дизайн который будет
 * использоваться для этого объекта*/
bottle obj1(0.3, 3, bottleDesign);
bottle obj2(0.5, 6, bottleDesign);
bottle obj3(0, 13, bottleDesign);
bottle obj4(0, 20, bottleDesign);
bottle obj5(0.6, 38, bottleDesign);
bottle obj6(0, 10, bottleDesign);
bottle obj7(0.5, 16, bottleDesign);
bottle obj8(0, 23, bottleDesign);
bottle obj9(0, 28, bottleDesign);
bottle obj10(0.6, 38, bottleDesign);
spikes obj11(-0.4, 3, spikesDesign);
spikes obj12(0.4, 7, spikesDesign);
spikes obj13(0.3, 13, spikesDesign);
spikes obj14(0.4, 23, spikesDesign);
spikes obj15(0.4, 32, spikesDesign);
spikes obj16(-0.4, 7, spikesDesign);
spikes obj17(-0.3, 17, spikesDesign);
spikes obj18(-0.4, 29, spikesDesign);
spikes obj19(-0.4, 38, spikesDesign);
money obj20(-0.5, 2, moneyDesign);
money obj21(0.3, 8, moneyDesign);
money obj22(-0.5, 14, moneyDesign);
money obj23(-0.5, 21, moneyDesign);
money obj24(0.3, 25, moneyDesign);
money obj25(-0.4, 38, moneyDesign);
money obj26(-0.5, 44, moneyDesign);
money obj27(0.3, 47, moneyDesign);
money obj28(-0.5, 4, moneyDesign);
money obj29(0.3, 6, moneyDesign);
money obj30(-0.5, 7, moneyDesign);
money obj31(-0.5, 11, moneyDesign);
money obj32(0.3, 15, moneyDesign);
money obj33(-0.4, 20, moneyDesign);
money obj34(-0.5, 24, moneyDesign);
money obj35(0.3, 28, moneyDesign);
money obj36(0.3, 32, moneyDesign);
money obj37(-0.4, 36, moneyDesign);
money obj38(-0.5, 39, moneyDesign);
money obj39(0.3, 43, moneyDesign);
money obj40(-0.2, 5, moneyRedDesign, -100);
money obj41(-0.1, 16, moneyRedDesign, -100);
money obj42(0.7, 30, moneyRedDesign, -100);
money obj43(-0.5, 34, moneyRedDesign, -100);
money obj44(0.5, 40, moneyRedDesign, -100);
money obj45(-0.2, 8, moneyRedDesign, -100);
money obj46(-0.1, 9, moneyRedDesign, -100);
money obj47(0.7, 26, moneyRedDesign, -100);
money obj48(-0.5, 28, moneyRedDesign, -100);
money obj49(0.5, 33, moneyRedDesign, -100);
tramplin obj50a(0.5, 2, tramplinDesign);
breakWay obj50(0, 2.2, breakWayDesign);
tramplin obj51a(-0.7, 34, tramplinDesign);
breakWay obj51(0, 34.2, breakWayDesign);
finish obj52(0, 48, finishDesign);
//
spikes obj53(0.1, 3, spikesDesign);
spikes obj54(-0.13, 33, spikesDesign);
spikes obj55(0.12, 40, spikesDesign);
money obj56(0, 30, moneyRedDesign, -100);
spikes obj57(0, 12, spikesDesign);
bottle obj58(-0.4, 40, bottleDesign);
money obj59(-0.2, 35, moneyRedDesign, -100);
spikes obj60(0.3, 21, spikesDesign);
spikes obj61(0, 17, spikesDesign);
spikes obj62(0.1, 39, spikesDesign);
spikes obj63(-0.1, 30, spikesDesign);
spikes obj64(0.1, 36, spikesDesign);
spikes obj65(0.0, 25, spikesDesign);
spikes obj66(-0.1, 20, spikesDesign);
gear obj67(0, 1, gearDesign);

/* добавляем адреса всех объектов, которые будут находится на карте*/
container_type<track_object *> mytrackObjects{
    &obj1,  &obj2,  &obj3,  &obj4,  &obj5,   &obj6,  &obj7,   &obj8,  &obj9,
    &obj10, &obj11, &obj12, &obj13, &obj14,  &obj15, &obj16,  &obj17, &obj18,
    &obj19, &obj20, &obj21, &obj22, &obj23,  &obj24, &obj25,  &obj26, &obj27,
    &obj28, &obj29, &obj30, &obj31, &obj32,  &obj33, &obj34,  &obj35, &obj36,
    &obj37, &obj38, &obj39, &obj40, &obj41,  &obj42, &obj43,  &obj44, &obj45,
    &obj46, &obj47, &obj48, &obj49, &obj50a, &obj50, &obj51a, &obj51, &obj52,
    &obj53, &obj54, &obj55, &obj56, &obj57,  &obj58, &obj59,  &obj60, &obj61,
    &obj62, &obj63, &obj64, &obj65, &obj66,  &obj67};
/*
создаем трек, определяя его дизайн и те объекты которые будут на нем кроме
машины
*/
container_type<track_object *> oneObject{&obj10};
// track mytrack{trackDesign, oneObject};
track mytrack;
track initTrack{trackDesign, mytrackObjects};

/*
создаем машину, определяя начальные координаты, дизайн, скорость, жизни, бонусы
в начале игры
*/
car mycar;
car initcar{0, -0.425, dcar, 0, 2, 500};
