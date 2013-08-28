//
//  Particle.h
//  CinderProject1
//
//  Created by Sandra Corella on 8/8/13.
//
//

#pragma once
#include "cinder/Channel.h"
#include "cinder/Vector.h"

#include <vector>

class Particle {
public:
	Particle();
	Particle( ci::Vec2f );
	void update(const cinder::Channel32f &channel, const ci::Vec2i &mouseLoc);
	void draw();
	
	ci::Vec2f	mLoc;
	ci::Vec2f	mDir;
    ci::Vec2f   mDirToCursor;
	float		mVel;
    cinder::Color       mColor;
    float mScale;
	
	float		mRadius;
};