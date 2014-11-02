//
//  Cube.cpp
//  SeaCucumber
//
//  Created by Haylee Jung on 10/20/14.
//
//

#include "Sphere.h"

void Ball::draw(int i){
    
    float t = cinder::app::getElapsedSeconds();
    float tHeight = 5;
    gl::drawSphere(vec3(0,tHeight,0), 1, 20);
}