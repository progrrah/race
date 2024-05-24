#pragma once

#include "drawer.hpp"

template <typename T>
using container_type = std::vector<T>;
using colorContainer_type = container_type<container_type<double>>;
const float POINT_RADIUS = 6.0f;
const double deltaScaled = 1.01;
extern char **fileName;
extern double YY;
extern double XX;
extern double carPhi;
extern double deltay;
extern double deltax;
extern double deltaSpeed;
extern double scaleX;
extern double scaleY;
extern bool EXIT_KEY_IN_INTERACTION;

namespace Objects {
using namespace Drawer;
struct track_object;
struct track {
  int number_elems;
  const int track_details_numbers;
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
  void animate(double deltaxScaledx = deltaScaled,
               double deltaxScaledy = deltaScaled) {
    scaleX /= deltaxScaledx;
    scaleY /= deltaxScaledy;
    this->width /= deltaxScaledx;
    this->height /= deltaxScaledy;
  };
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
struct track_object {
  double x, y;
  bool IS_STATIC;
  Design objectDesign;
  virtual void doing(car &mycar) = 0;
  void drawObject() {
    auto number = objectDesign.designs.size();
    for (size_t i = 0; i < number; i++) {
      auto designElems = objectDesign.designs.at(i);
      designElems->draw(designElems->drawingMethod);
    }
  }
  track_object(double exx, double exy, Design exDesign, bool static_key = false)
      : x(exx), y(exy), objectDesign(exDesign), IS_STATIC(static_key){};
};
};  // namespace Objects

namespace Objects {
struct heart : track_object {
  void doing(car &mycar) {
    if (mycar.lifes < 2) {
      mycar.lifes++;
    }
  }
  heart(double exx, double exy, Design exDesign, bool key = false)
      : track_object(exx, exy, exDesign, key) {}
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
  money(double exx, double exy, Design exDesign, bool key = false)
      : track_object(exx, exy, exDesign, key) {}
};
struct spikes : track_object {
  void doing(car &mycar) {
    mycar.speed -= deltaSpeed;
    mycar.lifes--;
    if (mycar.lifes == 0) mycar.dead();
  }
  spikes(double exx, double exy, Design exDesign, bool key = false)
      : track_object(exx, exy, exDesign, key) {}
};
struct bottle : track_object {
  void doing(car &mycar) override {
    std::cout << "CONCRET DOING" << std::endl;
    EXIT_KEY_IN_INTERACTION = 1;
    deltax = -deltax;
    scaleX *= deltaScaled;
    scaleY *= deltaScaled;
    mycar.width *= deltaScaled;
    mycar.height *= deltaScaled;
  }
  bottle(double exx, double exy, Design exDesign, bool key = false)
      : track_object(exx, exy, exDesign, key) {}
};
struct finish : track_object {
  void doing(car &mycar) {}
  finish(double exx, double exy, Design exDesign, bool key = false)
      : track_object(exx, exy, exDesign, key) {}
};
struct breakWay : track_object {
  void doing(car &mycar) { std::cout << "concret doing" << std::endl; }
  breakWay(double exx, double exy, Design exDesign, bool key = false)
      : track_object(exx, exy, exDesign, key) {}
};
struct tramplin : track_object {
  void doing(car &mycar) {}
  tramplin(double exx, double exy, Design exDesign, bool key = false)
      : track_object(exx, exy, exDesign, key) {}
};
};  // namespace Objects