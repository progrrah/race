#pragma once
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "library.hpp"
namespace Interaction {
using namespace Drawer;
using namespace Objects;
void keyBoard(unsigned char key, int x, int y);
void anymalKeyboard(
    unsigned char key, int x,
    int y);  // function for random changed buttons for hard level
void redisplayTimer(int value = 1);
void changeYY(double deltay = deltay);
void changeXX(double deltax = deltax);
void moveСontinuously(int value = 2);
void doTransformTrack();
void doTransformCar();
void doTransformTrackObjects(track_object &object);
bool canDraw(track_object &object, car &mycar);
void drawALL();
void interact(track &mytrack, car &mycar);
};  // namespace Interaction
