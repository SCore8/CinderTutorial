//
//  ParticleController.h
//  CinderProject1
//
//  Created by Sandra Corella on 8/8/13.
//
//

#pragma once
#include "Particle.h"
#include <list>

class ParticleController {
public:
	ParticleController();
	void update(const cinder::Channel32f &channel, const ci::Vec2i &mouseLoc);
	void draw();
	void addParticles( int amt );
    void addParticle(int xi, int yi);
	void removeParticles( int amt );
	
	std::list<Particle>	mParticles;
    
    int mXRes = 40;
    int mYRes = 30;
};