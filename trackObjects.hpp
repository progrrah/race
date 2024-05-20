/*
дизайн всех объектов на треке
1. бутылка bottle
2. шипы spikes
3. бонусы bonuses
4. разрыв дороги breakWay
5. трамплин tramplin
6. финиш finish
*/
#pragma once
#include "library.hpp"
using namespace Drawer;
using namespace Objects;
container_type<container_type<double>> bigQuadColor1{{0.2, 0.2, 0.7}};
container_type<container_type<double>> smallQuadColor1{{0.2, 0.8, 0.1}};

Point pp13 = {-0.1, -0.1};
Point pp14 = {-0.1, 0.1};
Point pp15 = {0.1, 0.1};
Point pp16 = {0.1, -0.1};

container_type<Point> pTrackObject2{pp13, pp14, pp15, pp16};
design dstrObj2(pTrackObject2, smallQuadColor1);

// Point spkQuadp1 = {-0.5, 0};
// Point spkQuadp2 = {-0.5, 0.5};
// Point spkQuadp3 = {0.5, 0.5};
// Point spkQuadp4 = {0.5, 0};

// Point spkTrianglep1 = {-0.5, 0};
// Point spkTrianglep2 = {-1, 0.25};
// Point spkTrianglep3 = {-0.5, 0.5};

// container_type<Point> spkQuadp1List = {spkQuadp1, spkQuadp2, spkQuadp3,
//                                        spkQuadp4};
// container_type<Point> spkTrianglep1List = {spkTrianglep1, spkTrianglep2,
//                                            spkTrianglep3};

// container_type<Point> spk1List = {spkQuadp1,    spkQuadp2,     spkQuadp3,
//                                   spkQuadp4,    spkTrianglep1, spkTrianglep2,
//                                   spkTrianglep3};
// // Point spkTrianglep3;
// design spkDesign1(7, spk1List);
// spikes spk1(0.5, 3, spkDesign1);container_type<track_object*> exelems{&obj1,
// &obj2}; track mytrack{0, designs, exelems};

// auto addObjectsInElemes = [=](int number_elems, double max_y,
//                               container_type<track_object *> &elems) {
//   for (int i{}; i < number_elems; i++) {
//     Point p;
//     std::cin >> p.x;
//     std::cin >> p.y;
//     if (p.x >= -1 && p.x <= 1) {
//     //   elems.insert(&p);
//     }
//   };
// }

// container_type<container_type<double>> manyPoints;