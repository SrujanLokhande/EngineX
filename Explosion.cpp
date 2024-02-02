//
// + Explosion.cpp
// colourful explosion
//

#include "Explosion.h"

//-----------------------------------------------------------------
//-----------------------------------------------------------------

//-----------------------------------------------------------------
//-----------------------------------------------------------------

//-----------------------------------------------------------------
//-----------------------------------------------------------------

//-----------------------------------------------------------------
//-----------------------------------------------------------------

Explosion::Explosion(exVector2 position)
{
	mSpawnedAt = std::chrono::high_resolution_clock::now();
	mDuration = 1;
	mLocation = position;
}

float Explosion::GetRadius() const
{
	auto currentTime = std::chrono::high_resolution_clock::now();
	auto timeDifference = currentTime - mSpawnedAt;
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(timeDifference);
	return static_cast<float>(1 - duration.count());
}

exVector2 Explosion::GetPosition() const
{
	return mLocation;
}
