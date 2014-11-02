

#pragma once

#include "cinder/gl/GlslProg.h"

using namespace ci;

using BallRef = std::shared_ptr<class Ball>;

class Ball{
    
public:
    static BallRef create(){ return BallRef( new Ball ); }
    void draw(int i);
};