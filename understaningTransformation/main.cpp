#include <GL/freeglut.h>
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
#include "graphicks.hpp"

#include <GL/glut.h>
// #include <stdlib.h>  // Include the standard library for generating random numbers

// #define WINDOW_WIDTH 800
// #define WINDOW_HEIGHT 600

// float carX = WINDOW_WIDTH / 2;
// float carY = 50;
// float carSpeed = 3;

// float heartX, heartY;
// bool heartCollected = false;
// int DOING_TRANSFORM_KEY = -1;
// int SELECT_TRANSFORM_KEY = -1;
// void keyBoardTransformationUnderstand(unsigned char key, int x, int y);
// // Function to draw the car
// void doingTransform() {
//   if (SELECT_TRANSFORM_KEY == 0) glLoadIdentity();
//   if (SELECT_TRANSFORM_KEY == 1) glPushMatrix();
//   if (SELECT_TRANSFORM_KEY == 2) glPopMatrix();
//   if (SELECT_TRANSFORM_KEY == 3) glTranslatef(1, 1, 1);
// }
// void drawCar() {
//   glPushMatrix();
//   glTranslatef(carX, carY, 0);

//   // Draw the car body
//   glColor3f(1.0, 0.0, 0.0);
//   glBegin(GL_QUADS);
//   glVertex2f(-20, 0);
//   glVertex2f(20, 0);
//   glVertex2f(20, 40);
//   glVertex2f(-20, 40);
//   glEnd();

//   // Draw the car windows
//   glColor3f(0.0, 0.0, 1.0);
//   glBegin(GL_TRIANGLES);
//   glVertex2f(-20, 40);
//   glVertex2f(20, 40);
//   glVertex2f(0, 60);
//   glEnd();

//   glPopMatrix();
// }

// // Function to draw the hearts
// void drawHeart() {
//   if (!heartCollected) {
//     glPushMatrix();
//     glTranslatef(heartX, heartY, 0);

//     glColor3f(1.0, 0.0, 0.0);
//     glBegin(GL_TRIANGLES);
//     glVertex2f(0, 0);
//     glVertex2f(10, 20);
//     glVertex2f(20, 0);
//     glEnd();

//     glPopMatrix();
//   }
// }

// // Function to handle window draw events
// void display() {
//   glutKeyboardFunc(keyBoardTransformationUnderstand);
//   glClear(GL_COLOR_BUFFER_BIT);
//   // defaultly
//   glMatrixMode(GL_MODELVIEW);
//   // glMatrixMode(GL_PROJECTION);
//   // Draw the road

//   // if (DOING_TRANSFORM_KEY == 0)
//   doingTransform();

//   glColor3f(0.5, 0.5, 0.5);
//   glBegin(GL_QUADS);
//   glVertex2f(0, 0);
//   glVertex2f(WINDOW_WIDTH, 0);
//   glVertex2f(WINDOW_WIDTH, WINDOW_HEIGHT);
//   glVertex2f(0, WINDOW_HEIGHT);
//   glEnd();

//   if (DOING_TRANSFORM_KEY == 1) doingTransform();
//   drawCar();
//   if (DOING_TRANSFORM_KEY == 2) doingTransform();
//   drawHeart();
//   if (DOING_TRANSFORM_KEY == 3) doingTransform();

//   glutSwapBuffers();
// }

// // Function to update the game state
// void update() {
//   carY += carSpeed;

//   if (carY > WINDOW_HEIGHT) {
//     carY = 0;
//   }

//   // Check collision with heart
//   if (!heartCollected && carX >= heartX && carX <= heartX + 20 &&
//       carY >= heartY && carY <= heartY + 20) {
//     heartCollected = true;
//   }

//   glutPostRedisplay();
// }

// // Function to handle the keyboard input
// void keyboard(unsigned char key, int x, int y) {
//   switch (key) {
//     case 'a':
//       carX -= 10;
//       break;
//     case 'd':
//       carX += 10;
//       break;
//     case 'q':
//       exit(0);
//       break;
//   }
// }
// void specialKeyboard1();
// void specialKeyboard2();
// void specialKeyboard3();

// void generateHeart() {
//   heartX = rand() % (WINDOW_WIDTH - 20);
//   heartY = rand() % (WINDOW_HEIGHT - 20);
//   heartCollected = false;
// }

// int main(int argc, char** argv) {
//   glutInit(&argc, argv);
//   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
//   glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
//   glutCreateWindow("Racing Game");

//   glutDisplayFunc(display);
//   glutIdleFunc(update);
//   // glutKeyboardFunc(keyBoardTransformationUnderstand);
//   // glutSpecialFunc(specialKeyboard1);

//   glOrtho(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT, -1, 1);

//   glClearColor(0.0, 0.0, 0.0, 1.0);

//   generateHeart();  // Generate initial heart

//   glutMainLoop();

//   return 0;
// }
// // void specialKeyboard1(int key, int x, int y) {
// //   int mod;
// //   switch (key) {
// //     case GLUT_KEY_F1:
// //       mod = glutGetModifiers();
// //       if (mod == (GLUT_ACTIVE_SHIFT)) {
// //       }
// //       break;
// //     case GLUT_KEY_F2:

// //       break;
// //     case GLUT_KEY_F3:

// //       break;
// //   }
// // }
// void keyBoardTransformationUnderstand(unsigned char key, int x, int y) {
//   switch (key) {
//     case 1:
//       DOING_TRANSFORM_KEY = 0;
//       break;
//     case 2:
//       DOING_TRANSFORM_KEY = 1;
//       break;
//     case 3:
//       DOING_TRANSFORM_KEY = 2;
//       break;
//     case 4:
//       DOING_TRANSFORM_KEY = 3;
//       break;
//     case 'z':
//       SELECT_TRANSFORM_KEY = 0;
//       break;
//     case 'x':
//       SELECT_TRANSFORM_KEY = 1;
//       break;
//     case 'c':
//       SELECT_TRANSFORM_KEY = 2;
//       break;
//     case 'v':
//       SELECT_TRANSFORM_KEY = 3;
//       break;
//     default:
//       break;
//   }
// }
