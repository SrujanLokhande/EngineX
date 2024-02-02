//
// + Explosion.h
// colourful explosion
//

#pragma once

#include "GameObject.h"
#include <chrono>

using TIME = std::chrono::high_resolution_clock::time_point;

//-----------------------------------------------------------------
//-----------------------------------------------------------------

class Explosion 
{
public:
	Explosion() = delete;
	Explosion(exVector2 location);

	float GetRadius() const;
	exVector2 GetPosition() const;

	TIME mSpawnedAt;
	double mDuration;
	exVector2 mLocation;
};