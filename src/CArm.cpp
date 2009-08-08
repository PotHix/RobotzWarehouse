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

void CMap::setX(int px){
   x = px;
}

void CMap::setY(int py){
   y = py;
}
