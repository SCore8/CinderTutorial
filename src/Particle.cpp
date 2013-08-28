//
//  Particle.cpp
//  CinderProject1
//
//  Created by Sandra Corella on 8/8/13.
//
//
#include "Particle.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"

using namespace ci;

Particle::Particle()
{
}

Particle::Particle( Vec2f loc )
{
	mLoc	= loc;
	mDir	= Rand::randVec2f();
	mVel	= Rand::randFloat( 5.0f );
	//mRadius	= Rand::randFloat(1.0f, 5.0f);
    mScale = 7.0f;
    //mRadius = cos( mLoc.y * 0.1f) + sin(mLoc.x * 0.1f) +2.0f;
    //mRadius = (sin( mLoc.y * mLoc.x) + 0.1f) *2.0f;
    //int xyOffset = sin(cos(sin(mLoc.y*0.3183f)+cos(mLoc.x*0.3183f)))+1.0f;
    //mRadius = xyOffset * xyOffset*1.8f;
    //float time = app::getElapsedSeconds();
}

void Particle::update(const cinder::Channel32f &channel, const Vec2i &mouseLoc)
{
	//mLoc += mDir * mVel;
    //float grey = channel.getValue(mLoc);
    //mColor = Color(grey, grey, grey);
    //mRadius = channel.getValue(mLoc)*mScale;
    
    mDirToCursor = mouseLoc - mLoc;
    mDirToCursor.safeNormalize();
    mRadius = channel.getValue(mLoc)*mScale;
    
}

void Particle::draw()
{
    //gl::color(mColor);
	//gl::drawSolidCircle( mLoc, mRadius );
    
    gl::color( Color(1.0f, 1.0f, 1.0f));
    float arrowLength = 15.0f;
    Vec3f p1(mLoc, 0.0f);
    Vec3f p2(mLoc+mDirToCursor * arrowLength, 0.0f);
    float headLength = 6.0f;
    float headRadius = 3.0f;
    gl::drawVector(p1,p2,headLength, headRadius);
    
}
