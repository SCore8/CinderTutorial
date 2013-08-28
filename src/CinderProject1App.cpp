#include "cinder/app/AppNative.h"
//#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "ParticleController.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CinderProject1App : public AppNative {
  public:
    void prepareSettings( Settings *settings);
	void setup();
    void keyDown( KeyEvent event );
	void mouseMove( MouseEvent event );
	void mouseDrag( MouseEvent event );
	void mouseDown( MouseEvent event );
	void update();
	void draw();
    
    gl::Texture myImage;
    Channel32f mChannel;
    
    Vec2i mMouseLoc;
    
    ParticleController mParticleController;
    
    bool mRenderImage;
    bool mRenderParticles;
};

void CinderProject1App::prepareSettings( Settings *settings)
{
    settings->setWindowSize(800,600);
    settings->setFrameRate(60.0f);
}


void CinderProject1App::setup()
{
    //myImage = gl::Texture( loadImage( loadResource( "image.jpg" ) ) );
    
    /*try {
        path p = getOpenFilePath( "", ImageIo::getLoadExtensions() );
        if( ! p.empty() ) { // an empty string means the user canceled
            myImage = gl::Texture( loadImage( p ) );
        }
    }
    catch( ... ) {
        console() << "Unable to load the image." << std::endl;
    }*/
    
    mChannel = Channel32f(loadImage(loadResource("image.jpg")));
    myImage = mChannel;
    
    mRenderImage = false;
    mRenderParticles = true;
    //mParticleController.addParticles( 250 );
}


void CinderProject1App::keyDown(KeyEvent event){
    if(event.getChar() == '1') mRenderImage =! mRenderImage;
    else if(event.getChar() == '2') mRenderParticles =! mRenderParticles;
    else if(event.getCode() == KeyEvent::KEY_RIGHT) console() << "right arrow pressed" << std::endl;
}
void CinderProject1App::mouseDown( MouseEvent event ){
    if(event.isRight() && event.isShiftDown()){
        console() << "Special thing happened!" << std::endl;
    }
}
void CinderProject1App::mouseMove( MouseEvent event ){
    mMouseLoc = event.getPos();
}
void CinderProject1App::mouseDrag( MouseEvent event ){
    mouseMove(event);
}
void CinderProject1App::update()
{
    mParticleController.update(mChannel, mMouseLoc);
}


void CinderProject1App::draw()
{
    //float gray = sin(getElapsedSeconds() ) * 0.5f + 0.5f;
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ), true);
    
    /*if(mRenderImage) {
        myImage.enableAndBind();
        gl::draw( myImage, getWindowBounds() );
    }*/
    if(mRenderParticles){
        glDisable(GL_TEXTURE_2D);
        mParticleController.draw();
    }
    //float x = cos(getElapsedSeconds())*100.0f;
    //float y = sin(getElapsedSeconds())*100.0f;
    //gl::drawSolidCircle(Vec2f(x, y)+ getWindowSize()/2, abs(x));
    
    
}

CINDER_APP_NATIVE( CinderProject1App, RendererGl )
