//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.h
// definition of MyGame, an implementation of exGameInterface
//

#include "Game/Public/GameInterface.h"
#include "Engine/Public/EngineTypes.h"
#include "Explosion.h"
#include <memory>
#include <vector>
#include <chrono>

using TIME = std::chrono::high_resolution_clock::time_point;

class Ball;
class GameObject;
class StateMachineComponent;

//-----------------------------------------------------------------
//-----------------------------------------------------------------

class MyGame : public exGameInterface
{
public:

	MyGame();
	virtual						~MyGame();

	virtual void				Initialize(exEngineInterface* pEngine);

	virtual const char*         GetWindowName() const;
	virtual void				GetClearColor(exColor& color) const;

	virtual void				OnEvent(SDL_Event* pEvent);
	virtual void				OnEventsConsumed();

	virtual void				Run(float fDeltaT);

	static int                  mPoints;

	void AddExplosion(exVector2 position);

	static MyGame* mCurrentGame;

private:

	exEngineInterface* mEngine;

	int							mFontID;
	int							mHorseSprite;

	bool						mUp;
	bool						mDown;
	bool						mRelease;
	bool						mShootBullet;

	std::vector<Explosion>      mExplosions;

	TIME                        mDeltaTime;

	exVector2					mTextPosition;

	std::shared_ptr<GameObject>   Ball;
	std::shared_ptr<GameObject>   Square;
	std::shared_ptr<GameObject>   Enemy;
	std::shared_ptr<StateMachineComponent>   State;

	exColor mBackgroundColor;

};
