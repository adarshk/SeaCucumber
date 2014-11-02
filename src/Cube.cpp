//
//  Cube.cpp
//  SeaCucumber
//
//  Created by Haylee Jung on 10/20/14.
//
//

#include "Cube.h"

void Cube::draw(int i){
    
    float t = cinder::app::getElapsedSeconds();
    float tHeight = sin(t*i*0.1+5)*2 + 5;
    gl::drawColorCube(vec3(0,tHeight,0), vec3(1,1,1));
}