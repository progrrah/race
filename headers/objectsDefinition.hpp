#pragma once

#include "drawer.hpp"

template <typename T>
using container_type = std::vector<T>;
using colorContainer_type = container_type<container_type<double>>;
const float POINT_RADIUS = 6.0f;
const double deltaScaled = 1.05;
extern char **fileName;
extern double YY;
extern double XX;
extern double carPhi;
extern double deltaPhi;
extern double deltay;
extern double deltax;
extern double deltaSpeed;
extern double scaleX;
extern double scaleY;
extern bool EXIT_KEY_IN_INTERACTION;
// void *fonts[] = {GLUT_BITMAP_9_BY_15, GLUT_BITMAP_TIMES_ROMAN_10,
//                  GLUT_BITMAP_TIMES_ROMAN_24};

namespace Objects {
using namespace Drawer;
struct track_object;
struct track {
  int number_elems;
  container_type<track_object *> elems;
  Design trackDesign;
  track(){};
  track(Design extrackDesign, container_type<track_object *> exelems)
      : number_elems(exelems.size()),
        trackDesign(extrackDesign),
        elems(exelems) {}

  void addElems(container_type<track_object *> exelems) {
    for (auto const &i : exelems) {
      this->elems.push_back(i);
    }
  }
  void clearElems() {
    for (auto const &i : elems) {
      this->elems.pop_back();
    }
  }
  void drawTrack() {
    for (int i{}; i < trackDesign.designs.size(); i++) {
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
    carPhi += deltaPhi;
  };
  void setSpeed(double newspeed) { speed = newspeed; }
  void dead() {
    lifes = 0;
    EXIT_KEY_IN_INTERACTION = true;
    for (int i{}; i < 10; i++) {
      animate();
      // glutPostRedisplay();
    }
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
  virtual void drawObject() {
    auto number = objectDesign.designs.size();
    for (size_t i = 0; i < number; i++) {
      auto designElems = objectDesign.designs.at(i);
      designElems->draw(designElems->drawingMethod);
    }
  }
  track_object(){};
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
  money(double exx, double exy, Design exDesign, int exBonus = 100,
        bool key = false)
      : track_object(exx, exy, exDesign, key) {
    bonus = exBonus;
  }
};
struct spikes : track_object {
  void doing(car &mycar) {
    mycar.speed -= deltaSpeed;
    mycar.lifes--;
    // if (mycar.lifes == 0)
    mycar.dead();
  }
  spikes(double exx, double exy, Design exDesign, bool key = false)
      : track_object(exx, exy, exDesign, key) {}
};
struct bottle : track_object {
  void doing(car &mycar) override {
    std::cout << "CONCRET DOING" << std::endl;
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
  void doing(car &mycar) {
    mycar.dead();
    std::cout << "concret doing" << std::endl;
  }
  breakWay(double exx, double exy, Design exDesign, bool key = false)
      : track_object(exx, exy, exDesign, key) {}
};
struct tramplin : track_object {
  void doing(car &mycar) {}
  tramplin(double exx, double exy, Design exDesign, bool key = false)
      : track_object(exx, exy, exDesign, key) {}
};
struct text : track_object {
  std::string *message;
  bool COLOR_RICHNESS;
  colorContainer_type color;
  void *mainFont = GLUT_BITMAP_HELVETICA_18;
  // void *mainFont = GLUT_BITMAP_HELVETICA_12;
  // void *mainFont = GLUT_BITMAP_TIMES_ROMAN_24;
  text(){};
  text(double exx, double exy, Design exDesign, bool key = false,
       std::string *msg = nullptr)
      : track_object(exx, exy, exDesign, key) {
    message = msg;
  }
  text(double exx, double exy, Design exDesign, colorContainer_type exColor,
       bool key = false, std::string *msg = nullptr)
      : track_object(exx, exy, exDesign, key) {
    color = exColor;
    message = msg;
    COLOR_RICHNESS = true;
  }
  void doing(car &mycar) {}
  void drawObject() override {
    if (!message) {
      std::cerr << "MESSAGE DONT EXIST";
      return;
    }
    int len, i;
    glRasterPos2f(x, y);
    len = message->size();
    for (i = 0; i < len; i++) {
      if (COLOR_RICHNESS && color.size() == message->size()) {
        glColor3d(color[i][0], color[i][1], color[i][2]);
      }

      else
        glColor3d(0, 0, 0);
      glutBitmapCharacter(mainFont, message->at(i));
    }
  }
};
struct block : track_object {
  void doing(car &mycar) {}
  block(double exx, double exy, Design exDesign, bool key = false)
      : track_object(exx, exy, exDesign, key) {}
};

};  // namespace Objects