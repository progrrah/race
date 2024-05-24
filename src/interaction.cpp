#include "interaction.hpp"
extern Objects::car mycar;
extern Objects::track mytrack;
extern Objects::bottle obj1;
extern char **fileName;
double YY = mycar.initY;
double XX = 0;
double trackPhi = 0;
double carPhi = 0;
double deltaPhi = 5;
double deltay = 0.1;
double deltax = 0.2;
double deltaSpeed = 0.1;
double scaleX = 1;
double scaleY = 1;
bool EXIT_KEY_IN_INTERACTION = 0;
int SELECT_KEY_DISPLAY = 1;
std::string line_1 = "----------------------------------------";
std::string line_2 = "";
int step_number = 1;
// DONE
// CREATE A CANDRAW FUNCTION IN HERE
void Interaction::keyBoard(unsigned char key, int x, int y) {
  switch (key) {
    case 'd':
      Interaction::changeXX();
      break;
    case 'a':
      Interaction::changeXX(-deltax);
      break;
    case 'w':
      if (YY + mycar.height / 2 <= 1) YY += deltay;
      break;
    case 's':
      if (YY - mycar.height / 2 >= -1) YY -= deltay;
      break;
    case 'q':
      exit(0);
    case 'Q':
      exit(0);
    case 'z':
      exit(0);
    default:
      break;
  }
};
void Interaction::redisplayTimer(int) {
  // USE STACK FOR DRAWING NEEDED TRACKOBJECTS
  auto fooPrint = [=]() {
    std::cout << "IT'S " << step_number++ << "' step!!!" << std::endl;
    std::cout << line_1 << std::endl;
  };
  interact(mytrack, mycar);
  glutPostRedisplay();
  changeYY(deltay);
  // playMusic(2, fileName);
  glutTimerFunc(REDISPLAY_TIME, redisplayTimer, 1);
}
void Interaction::changeXX(double deltax) {
  if (mycar.x + mycar.width / 2 <= 1 && deltax >= 0)
    mycar.x += deltax;
  else if (mycar.x - mycar.width / 2 >= -1 && deltax < 0)
    mycar.x += deltax;
}
void Interaction::changeYY(double deltay) { mycar.y += deltay; }
// DONE
bool Interaction::canDraw(track_object &object, car &mycar) {
  bool flag = 0;
  auto ycar = mycar.y;
  auto htrack = mytrack.trackDesign.designs.at(0)->height;
  auto yobj = object.y;
  if (yobj <= htrack / 2 + ycar && yobj >= ycar - htrack) {
    flag = 1;
  }
  return flag;
}

// TODO : TOO MUCH CHECKING
void Interaction::interact(track &mytrack, car &mycar) {
  auto accurancy = 0.01;
  auto wcar = mycar.width;
  auto hcar = mycar.height;
  auto xcar = mycar.x;
  auto ycar = (mycar.y + YY - accurancy * hcar);
  // auto LEVEL_LENGTH = mytrack.trackDesign.at(0).height - hcar / 2;
  for (auto &trackOb : mytrack.elems) {
    auto wobj = trackOb->objectDesign.designs.at(0)->width;
    auto hobj = trackOb->objectDesign.designs.at(0)->height;
    auto xobj = trackOb->x;
    auto yobj = trackOb->y;
    auto fooPrint = [=]() {
      std::cout << line_1 << std::endl;
      std::cout << xcar << std::endl;
      std::cout << "\txcar" << std::endl;
      std::cout << line_1 << std::endl;
      std::cout << wcar << std::endl;
      std::cout << "\twcar" << std::endl;
      std::cout << line_1 << std::endl;
      std::cout << xobj << std::endl;
      std::cout << "\txobj" << std::endl;
      std::cout << line_1 << std::endl;
      std::cout << wobj << std::endl;
      std::cout << "\twobj" << std::endl;
      std::cout << line_1 << std::endl;
    };
    auto check = [&]() {
      if (xcar + wcar / 2 >= xobj - wobj / 2 &&
          xcar - wcar / 2 <= xobj + wobj / 2)
        if (ycar + hcar / 2 >= yobj - hobj / 2 &&
            ycar - hcar / 2 <= yobj + hobj / 2) {
          trackOb->doing(mycar);
          mytrack.elems.erase(
              std::find(mytrack.elems.begin(), mytrack.elems.end(), trackOb));
        }
    };
    fooPrint();
    check();
  };
}
void Interaction::drawALL() {
  for (auto &trackObj : mytrack.elems) {
    canDraw(*trackObj, mycar);
    trackObj->drawObject();
  }
}

void Interaction::doTransformTrack() { glRotated(trackPhi, 0, 0, 1); }
void Interaction::doTransformCar() {
  glRotated(carPhi, 0, 0, 1);
  glTranslated(mycar.x, 0, 0);
  glTranslated(0, YY, 0);
  glScaled(scaleX, scaleY, 0);
}
void Interaction::doTransformTrackObjects(track_object &obj) {
  glTranslated(obj.x, obj.y, 0);
  if (!obj.IS_STATIC) {
    glTranslated(0, -mycar.y, 0);
  }
}