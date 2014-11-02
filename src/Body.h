#pragma once

#include "Thorn.h"
#include "cinder/Rand.h"
#include "cinder/Perlin.h"

#include "Cube.h"
#include "Sphere.h"


using namespace ci;

namespace sc {
   
    
    enum children{
        
        THORN_E,
        CUBE_E,
        SPHERE_E
        
    };
    
    
    
    using BodyRef = std::shared_ptr<class Body>;

class Body{
public:

    static BodyRef create(const int32_t segs,const int32_t len = 1,int enum_value=0){
        return BodyRef(new Body(segs,len,enum_value));
    }
    
    ~Body() {}
    
    void setSpline();
    
    void draw();
    void update();
    
    void setBodySpline();
    void sampleCurve();
    void buildPTF();
    void drawPs( float lineWidth );
    void drawTs( float lineLength, float lineWIdth );
    void drawThorns();
    
    void setLength(const int32_t len);
    int32_t getLength();
    void setSegments(const int32_t segs);
    int32_t getSegments();
    
protected:
    Body();
    Body(const int32_t segs,const int32_t len, int enum_value);
    
    
    int32_t mNumSegs;
    
    std::vector<vec3>		mPs;			// Points in b-spline sample
	std::vector<vec3>		mTs;			// Tangents in b-spline sample
	std::vector<mat4>	mFrames;
    
    
    std::vector<vec3>		mLineBase;
	std::vector<vec3>		mLinePoints;
    
    std::vector<vec3>		mProfPoints;
    
	BSpline3f				mBSpline;
    
    //Thorn mThorn;
    ThornRef mThorn;
    
    CubeRef mCube;
    
    BallRef mBall;
    //ThornRef mThorn = Thorn::create_default();
    
    mat4 mModelMatrix;
    int32_t length;
    
    Perlin bPerlin;
    Rand bRand;
    
    int got_enum_value;
};

}