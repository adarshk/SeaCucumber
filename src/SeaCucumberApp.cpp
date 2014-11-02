#include "cinder/app/AppNative.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/params/Params.h"
#include "cinder/Quaternion.h"

#include "Thorn.h"
#include "Body.h"
#include "cinder/Arcball.h"
#include "cinder/Camera.h"
#include "cinder/gl/Batch.h"
#include "cinder/gl/GlslProg.h"
#include "cinder/gl/Shader.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace sc;

class SeaCucumberApp : public AppNative {
public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
    void mouseDrag( MouseEvent event ) override;
	void update() override;
	void draw() override;
    void resize();

    
private:
    Arcball		mArcball;
    CameraPersp mCam;

    //Thorn mThorn;
    //Body mBody = *new Body(20);
    BodyRef mBody = Body::create(20,5,CUBE_E);
    
    bool isWireframe;
    
    gl::GlslProgRef mFlatShading;
    gl::GlslProgRef mPhongShading;
    bool enable_frag = false;
    bool enable_phong = true;
    //gl::BatchRef mTorus;
};

void SeaCucumberApp::setup()
{
    setWindowSize(600, 600 );

	mCam.lookAt( vec3( 0, 0, 50 ), vec3(0,0,0) );
    
    isWireframe = true;
    
    mFlatShading = gl::GlslProg::create(loadAsset("Flat.vert"), loadAsset("Flat.frag"));
    mPhongShading = gl::GlslProg::create(loadAsset("Phong.vert"), loadAsset("Phong.frag"));
    //mTorus = gl::Batch::create(geom::Torus(), mFlatShading);
    
    // Arcball
	mArcball.setWindowSize( getWindowSize() );
	mArcball.setCenter( getWindowCenter() );
	mArcball.setRadius( 150 );
    
    gl::enableDepthWrite();
    gl::enableDepthRead();
}

void SeaCucumberApp::resize()
{
	mCam.setPerspective( 60, getWindowAspectRatio(), 1, 1000 );
	gl::setMatrices( mCam );
}

void SeaCucumberApp::mouseDown( MouseEvent event )
{
    ivec2 P = event.getPos();
	P.y = getWindowHeight() - P.y;
	mArcball.mouseDown( P );
}

void SeaCucumberApp::mouseDrag( MouseEvent event )
{
    ivec2 P = event.getPos();
	P.y = getWindowHeight() - P.y;
	mArcball.mouseDrag( P );
}

void SeaCucumberApp::update()
{
    mBody->update();
    //mThorn.update();
    //gl::setMatrices( mCam );
}

void SeaCucumberApp::draw()
{
    
    
	gl::clear( Color( 0,0,0 ));
    gl::setMatrices( mCam );
    gl::rotate( mArcball.getQuat() );
    
    if (enable_frag) {
        mFlatShading->bind();
    }
    
    if (enable_phong) {
        mPhongShading->bind();
    }
    
    mBody->draw();

}

CINDER_APP_NATIVE( SeaCucumberApp, RendererGl )
