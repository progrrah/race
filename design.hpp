#pragma once
#include "library.hpp"
#include "mytrack.hpp"
#include "mycar.hpp"
#include "trackObjects.hpp"
using namespace Objects;
using namespace Drawer;
container_type<double> rgblist{0, 1, 0.5};
container_type<double> bigQuadColor{0.2, 0.2, 0.7};
container_type<double> smallQuadColor{0.2, 0.8, 0.1};
extern car mycar;
extern container_type<track_object*> mytrackObjects;
track mytrack{0, designs, mytrackObjects};
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
