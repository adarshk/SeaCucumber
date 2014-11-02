

#pragma once

using namespace ci;

using CubeRef = std::shared_ptr<class Cube>;

class Cube{

public:
    static CubeRef create(){ return CubeRef( new Cube ); }
    void draw(int i);
};