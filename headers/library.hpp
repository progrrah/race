/*
библиотека которую еще придеться перелопатить
*/
#pragma once
#include <GL/freeglut.h>
#include <initializer_list>
#include <GL/glut.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <ctime>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include "drawer.hpp"
template <typename T>
using container_type = std::vector<T>;
using colorContainer_type = container_type<container_type<double>>;
const int REDISPLAY_TIME = 50;
const int SHIFTING_TIME = 100;
const int WIDTH = 800;    // window width
const int HEIGHT = 1000;  // window height
const float POINT_RADIUS = 6.0f;
const double deltaScaled = 1.1;

extern double YY;
extern double XX;
extern double carPhi;
extern double deltay;
extern double deltax;
extern double deltaSpeed;
extern double scaleX;
extern double scaleY;
extern bool EXIT_KEY_IN_INTERACTION;

extern colorContainer_type rgblist;
namespace Objects {
using namespace Drawer;
// TODO CONSTRUCTOR AND FUNCTIONS
struct track_object;
struct track {
  // количество всех элементов без машины(всех trackobjects)
  int number_elems;
  // количество элементов, из которых будет рисоваться полотно трека
  const int track_details_numbers;
  // all track_objects here
  container_type<track_object *> elems;
  Design trackDesign;
  track() = default;
  track(Design extrackDesign, container_type<track_object *> exelems)
      : number_elems(exelems.size()),
        track_details_numbers(extrackDesign.designs.size()),
        trackDesign(extrackDesign),
        elems(exelems) {}

  void addElems(container_type<track_object *> exelems) {
    for (auto const &i : exelems) {
      this->elems.push_back(i);
    }
  }
  void clearElems();
  void drawTrack() {
    for (int i{}; i < track_details_numbers; i++) {
      auto trackDesignElems = trackDesign.designs.at(i);
      trackDesignElems->draw(trackDesignElems->drawingMethod);
    }
  }
};
// OK
struct car {
  double initX, initY;
  double x{initX};
  double y{};
  double width;
  double height;

  Design carDesign;
  double speed;
  int lifes;
  int bonus;
  void drawCar() {
    auto component_numbers = carDesign.designs.size();
    for (size_t i = 0; i < component_numbers; i++) {
      carDesign.designs.at(i)->draw(carDesign.designs.at(i)->drawingMethod);
    }
  }
  void setSpeed(double newspeed) { speed = newspeed; }
  void dead() {
    lifes = 0;
    // TODO draw dead animation
    // gameEndDisplay()
  }
  int getLifes() { return lifes; }
  car(){};
  car(double exInitX, double exInitY, Design exDs, double exSpeed, int exLifes,
      int exBonus)
      : initX(exInitX),
        initY(exInitY),
        carDesign(exDs),
        lifes(exLifes),
        bonus(exBonus),
        width(exDs.designs.at(0)->width),
        height(exDs.designs.at(0)->height) {}
};
// REWRITE THE DRAW METHOD
struct track_object {
  // coords of centre
  double x, y;
  Design objectDesign;
  // interact with car
  virtual void doing(car &mycar) = 0;
  void drawObject() {
    // objectDesign.draw(typeDrawing::QUADS);
    auto number = objectDesign.designs.size();
    for (size_t i = 0; i < number; i++) {
      auto designElems = objectDesign.designs.at(i);
      designElems->draw(designElems->drawingMethod);
    }
  }
  track_object(double exx, double exy, Design exDesign)
      : x(exx), y(exy), objectDesign(exDesign){};
};
};  // namespace Objects

namespace Objects {
struct heart : track_object {
  void doing(car &mycar) {
    if (mycar.lifes < 2) {
      mycar.lifes++;
    }
  }
};
struct money : track_object {
  int bonus;
  void doing(car &mycar) {
    mycar.bonus += bonus;
    if (mycar.bonus >= 1000) {
      mycar.lifes++;
      mycar.bonus -= 1000;
    }
  }
};
struct spikes : track_object {
  void doing(car &mycar) {
    mycar.speed -= deltaSpeed;
    mycar.lifes--;
    if (mycar.lifes == 0) mycar.dead();
  }
  spikes(double exx, double exy, Design exDesign)
      : track_object(exx, exy, exDesign) {}
};
struct bottle : track_object {
  void doing(car &mycar) override {
    std::cout << "CONCRET DOING" << std::endl;
    EXIT_KEY_IN_INTERACTION = 1;
    deltax = -deltax;
    // deltaScaled
    scaleX *= deltaScaled;
    scaleY *= deltaScaled;
    mycar.width *= deltaScaled;
    mycar.height *= deltaScaled;
    // carPhi = 50;
  }
  bottle(double exx, double exy, Design exDesign)
      : track_object(exx, exy, exDesign) {}
};
};  // namespace Objects