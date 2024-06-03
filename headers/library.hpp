/*
библиотека которую еще придеться перелопатить, но она является центральной в
нашей работе
*/
#pragma once
#include <GL/freeglut.h>
#include <GL/glut.h>

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "objectsDefinition.hpp"
/* пока не подключаем, еще не разобралися */
// #include "musicMoment.hpp"
const int WIDTH = 800;    // window width
const int HEIGHT = 1000;  // window height
const int REDISPLAY_TIME = 30;
const int SHIFTING_TIME = 10000;
