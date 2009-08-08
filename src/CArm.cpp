/**
 * GameJam 2009 - GamePlay
 *
 * The robot arm class file.
 */

#include "CArm.h"

CArm::CArm(){
   setX(DEFAULT_X);
   setY(DEFAULT_Y);
   sprite = new AnimSprite();
}

void CArm::setX(int px){
   x = px;
}

void CArm::setY(int py){
   y = py;
}

int CArm::getX(){
   return x;
}

int CArm::getY(){
   return y;
}
