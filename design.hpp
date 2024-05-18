#pragma once
#include "library.hpp"
using namespace Drawer;
using namespace Objects;
container_type<double> rgblist{0, 1, 0.5};
Drawer::Point p1{-0.85, -1};
Drawer::Point p2{-0.85, 1};
Drawer::Point p3{0.85, 1};
Drawer::Point p4{0.85, -1};

Drawer::Point p5{-0.05, -1};
Drawer::Point p6{-0.05, 1};
Drawer::Point p7{0.05, 1};
Drawer::Point p8{0.05, -1};

container_type<Point> pointLists{p1, p2, p3, p4, p5, p6, p7, p8};
container_type<Point> plist1{p1, p2, p3, p4};
container_type<Point> plist2{p5, p6, p7, p8};
container_type<double> bigQuadColor{0.2, 0.2, 0.7};
container_type<double> smallQuadColor{0.2, 0.8, 0.1};

design ds1(4, plist1, bigQuadColor);
design ds2(4, plist2, smallQuadColor);
// дизайн трэка из двух прямоугольников
container_type<design> designs{ds1, ds2};
////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////  car design
////////////////////////////////////////////////////////////////////////////////////////////////////////
Point p9 = {-0.1, -0.15};
Point p10 = {-0.1, 0.15};
Point p11 = {0.1, 0.15};
Point p12 = {0.1, -0.15};
container_type<Point> pcarlist{p9, p10, p11, p12};
container_type<double> carColor{0.9, 0.5, 0.1};
// дизайн машины
design dcar(4, pcarlist, carColor);
car mycar{0, -0.425, dcar, 0, 2, 0};
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

Point p13 = {-0.1, -0.3};
Point p14 = {-0.1, 0.3};
Point p15 = {0.1, 0.3};
Point p16 = {0.1, -0.3};

Point pp13 = {-0.1, -0.1};
Point pp14 = {-0.1, 0.1};
Point pp15 = {0.1, 0.1};
Point pp16 = {0.1, -0.1};
container_type<Point> pTrackObject1{p13, p14, p15, p16};
container_type<Point> pTrackObject2{pp13, pp14, pp15, pp16};
design dstrObj1(4, pTrackObject1);
design dstrObj2(4, pTrackObject2, smallQuadColor);
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
bottle obj1(0.3, 1, dstrObj1);
bottle obj2(0, 3, dstrObj2);
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
Point spkQuadp1 = {-0.5, 0};
Point spkQuadp2 = {-0.5, 0.5};
Point spkQuadp3 = {0.5, 0.5};
Point spkQuadp4 = {0.5, 0};

Point spkTrianglep1 = {-0.5, 0};
Point spkTrianglep2 = {-1, 0.25};
Point spkTrianglep3 = {-0.5, 0.5};

container_type<Point> spkQuadp1List = {spkQuadp1, spkQuadp2, spkQuadp3,
                                       spkQuadp4};
container_type<Point> spkTrianglep1List = {spkTrianglep1, spkTrianglep2,
                                           spkTrianglep3};

container_type<Point> spk1List = {spkQuadp1,    spkQuadp2,     spkQuadp3,
                                  spkQuadp4,    spkTrianglep1, spkTrianglep2,
                                  spkTrianglep3};
// Point spkTrianglep3;
design spkDesign1(7, spk1List);
spikes spk1(0.5, 3, spkDesign1);

container_type<track_object*> exelems{&obj1, &obj2};
// container_type<track_object *> exelems;
// container_type<track_object*> exelems{&obj1};
track mytrack{0, designs, exelems};
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
