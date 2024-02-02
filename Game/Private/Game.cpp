//
// * SOURCE 3
// * INDUSTRY-READY GAME
// * READY TO SHIP
//
// COPYRIGHT SRUJAN AND GAVIN (CSGO 3 TEAM)
// COLLAB WITH YOUTUBE
// FEATURING THE PRICE IS RIGHT
// THANKS PLAYTESTING TEAM 
// - JESSY 
// FOR PLAYTESTING
//
// * RAY TRACING DLC COMES SOON

#include "Game/Private/Game.h"

#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h"
#include "GameObject.h"
#include "GameObjectManager.h"
#include "RenderComponent.h"
#include "CircleRenderComponent.h"
#include "SquareRenderComponent.h"
#include "PhysicsEngine.h"
#include "RenderingEngine.h"
#include "Transform.h"
#include "PhysicsComponent.h"
#include "MouseTrackingComponent.h"
#include "StateMachineComponent.h"
#include "HomingComponent.h"
#include "Random.h"
#include <thread>
#include <string>
#include <iostream>
#include <chrono>
#include <windows.h>
#include <shellapi.h>

#define RANDOM_COLOR (unsigned char)RandomInt(255)

#include <iostream>

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* gWindowName = "CSGO 3.2";
MyGame* MyGame::mCurrentGame = nullptr;


//-----------------------------------------------------------------
//-----------------------------------------------------------------

int MyGame::mPoints = 0;
void EnemyGotHit(std::shared_ptr<PhysicsComponent> enemyPhysicsComp);

MyGame::MyGame()
	: mEngine(nullptr)
	, mFontID(-1)
	, mUp(false)
	, mDown(false)
    , mBackgroundColor(exColor{ 36, 44, 68, 255 })
{
    mCurrentGame = this;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::~MyGame()
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Initialize(exEngineInterface* pEngine)
{
    mDeltaTime = std::chrono::high_resolution_clock::now();

    mEngine = pEngine;

    mFontID = mEngine->LoadFont("Resources/Rohit.ttf", 32);
    mHorseSprite = mEngine->LoadSprite(HorseSprite);

    //Ball = std::make_shared<GameObject>();
    Ball = GAME_OBJECT_MANAGER->SpawnGameObject<GameObject>();
    Ball->Initialize();
    Square = GAME_OBJECT_MANAGER->SpawnGameObject<GameObject>();
    Square->Initialize();
    Enemy = GAME_OBJECT_MANAGER->SpawnGameObject<GameObject>();
    Enemy->Initialize();

    exVector2 vector{ 1.0f, 1.0f };
    exVector2 locVector{ 1.0f, 1.0f };
       
    Ball->AddComponent<Transform>(vector, vector, vector);
    Ball->AddComponent<CircleRenderComponent>(0.1f);
    Ball->AddComponent<MouseTrackingComponent>();
    Ball->AddComponent<PhysicsComponent>();
    Ball->FindComponentOfType<PhysicsComponent>()->mCanCollide = false;

    Square->AddComponent<Transform>(vector, vector, vector);
    Square->AddComponent<SquareRenderComponent>(10.0f, 10.0f);
    Square->AddComponent<PhysicsComponent>();

    Enemy->AddComponent<Transform>(vector, vector, vector);
    Enemy->AddComponent<SquareRenderComponent>(20.0f, 20.0f);
    Enemy->AddComponent<PhysicsComponent>();

    Square->AddComponent<HomingComponent>();
    Square->FindComponentOfType<HomingComponent>()->mToTrack = (Enemy->FindComponentOfType<Transform>());
}


void EnemyGotHit(std::shared_ptr<PhysicsComponent> enemyPhysicsComp)
{
    enemyPhysicsComp->GetRenderComponent()->SetColor( { RANDOM_COLOR, RANDOM_COLOR, RANDOM_COLOR, 255 } );
    std::cout << "Enemy got hit" << std::endl;
    enemyPhysicsComp->SetRandomPosition();

    MyGame::mPoints++;
}


//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* MyGame::GetWindowName() const
{
	return gWindowName;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::GetClearColor(exColor& color) const
{
    color = mBackgroundColor;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEvent(SDL_Event* pEvent)
{
    // Handle mouse events and update MouseTrackingComponent
    if (pEvent->type == SDL_MOUSEMOTION)
    {
        int mouseX = pEvent->motion.x;
        int mouseY = pEvent->motion.y;
                                                                                                                                  //                   ______     _______.  _______   ______       ____                           
        if (Ball->HasComponentOfType<MouseTrackingComponent>())                                                                   //                  /      |   /       | /  _____| /  __  \     |___ \                          
        {                                                                                                                         //                 |  ,----'  |   (----`|  |  __  |  |  |  |      __) |                         
            //std::cout << "ball has component" << std::endl;                                                                     //                 |  |        \   \    |  | |_ | |  |  |  |     |__ <                          
                                                                                                                                  //                 |  `----.----)   |   |  |__| | |  `--'  |     ___) |                         
            std::shared_ptr<MouseTrackingComponent> mouseTrackingComp = Ball->FindComponentOfType<MouseTrackingComponent>();      //                  \______|_______/     \______|  \______/     |____/                          
            mouseTrackingComp->SetMousePosition(mouseX, mouseY);                                                                  //                                                                                              
        }                                                                                                                         //                      _______.  ______    __    __  .______        ______  _______     ____   
    }                                                                                                                             //                     /       | /  __  \  |  |  |  | |   _  \      /      ||   ____|   |___ \  
}                                                                                                                                 //                    |   (----`|  |  |  | |  |  |  | |  |_)  |    |  ,----'|  |__        __) | 
                                                                                                                                  //                     \   \    |  |  |  | |  |  |  | |      /     |  |     |   __|      |__ <  
//-----------------------------------------------------------------                                                               //                 .----)   |   |  `--'  | |  `--'  | |  |\  \----.|  `----.|  |____     ___) | 
//-----------------------------------------------------------------                                                               //                 |_______/     \______/   \______/  | _| `._____| \______||_______|   |____/  
                                                                                                                                  //                                                                                              
void MyGame::OnEventsConsumed()                                                                                                   //                   ______   ______    _______   _______                                       
{                                                                                                                                 //                  /      | /  __  \  |       \ |   ____|                                      
	int nKeys = 0;                                                                                                                //                 |  ,----'|  |  |  | |  .--.  ||  |__                                         
	const Uint8* pState = SDL_GetKeyboardState(&nKeys);                                                                           //                 |  |     |  |  |  | |  |  |  ||   __|                                        
                                                                                                                                  //                 |  `----.|  `--'  | |  '--'  ||  |____                                       
	mUp = pState[SDL_SCANCODE_UP];                                                                                                //                  \______| \______/  |_______/ |_______|                                      
	mDown = pState[SDL_SCANCODE_DOWN];                                                                                            //                                                                                              
                                                                                                                                  //                      _______..______       __    __         __       ___      .__   __.      
    mRelease = pState[SDL_SCANCODE_SPACE];                                                                                        //                     /       ||   _  \     |  |  |  |       |  |     /   \     |  \ |  |      
    mShootBullet = pState[SDL_SCANCODE_SPACE];                                                                                    //                    |   (----`|  |_)  |    |  |  |  |       |  |    /  ^  \    |   \|  |      
                                                                                                                                  //                     \   \    |      /     |  |  |  | .--.  |  |   /  /_\  \   |  . `  |      
}                                                                                                                                 //                 .----)   |   |  |\  \----.|  `--'  | |  `--'  |  /  _____  \  |  |\   |      
                                                                                                                                  //                 |_______/    | _| `._____| \______/   \______/  /__/     \__\ |__| \__|      
//-----------------------------------------------------------------                                                               //                                                                                              
//-----------------------------------------------------------------                                                               //                   _______      ___   ____    ____  __  .__   __.                             
                                                                                                                                  //                  /  _____|    /   \  \   \  /   / |  | |  \ |  |                             
void MyGame::Run(float fDeltaT)                                                                                                   //                 |  |  __     /  ^  \  \   \/   /  |  | |   \|  |                             
{                                                                                                                                 //                 |  | |_ |   /  /_\  \  \      /   |  | |  . `  |                             
    //std::cout << "FPS: " << 1.0f / fDeltaT << std::endl;                                                                        //                 |  |__| |  /  _____  \  \    /    |  | |  |\   |                             
                                                                                                                                  //                  \______| /__/     \__\  \__/     |__| |__| \__|                             
    exVector2 playerPosition = Ball->FindComponentOfType<Transform>()->GetPosition();                                             //                                                                                              
                                                                                                                                  //                 .______        ______    __    __   __  .___________.                        
    mTextPosition.x = playerPosition.x - 5;                                                                                       //                 |   _  \      /  __  \  |  |  |  | |  | |           |                        
    mTextPosition.y = playerPosition.y - 5;                                                                                       //                 |  |_)  |    |  |  |  | |  |__|  | |  | `---|  |----`                        
                                                                                                                                  //                 |      /     |  |  |  | |   __   | |  |     |  |                             
    if (!mShootBullet)                                                                                                            //                 |  |\  \----.|  `--'  | |  |  |  | |  |     |  |                             
    {                                                                                                                             //                 | _| `._____| \______/  |__|  |__| |__|     |__|                             
                                                                                                                                  //                                                                                              
        //std::cout << "HI :)" << std::endl;

        Square->FindComponentOfType<Transform>()->SetPosition(playerPosition);
    }

#undef DrawText

    mEngine->DrawText(mHorseSprite, mTextPosition, (mShootBullet? "H" : "G"), exColor{ 162,97,72,255}, 5);


    //GAME_OBJECT_MANAGER->Update();

    const int POINTS_TO_WIN = 30;

    if (mPoints > POINTS_TO_WIN) {
        return;
    }
    else if (mPoints == POINTS_TO_WIN)
    {
#undef DrawText
        mEngine->DrawText(mHorseSprite, mTextPosition, ("S"), exColor{ 240,141,85,255}, 5);
        mFontID = mEngine->LoadFont("Resources/Rohit.ttf", 80);
        mEngine->DrawText(mFontID, exVector2(90, 120), "YOU WIN CSGO 3!", exColor{223,233,239,255}, 5);
        mEngine->DrawText(mFontID, exVector2(150, 300), "GOOD JOB!", exColor{ 223,233,239,255 }, 5);
        
        mBackgroundColor = exColor{ 158, 46, 71, 255 };

        std::thread Render(&RenderingEngine::Render, RENDER_ENGINE, mEngine);
        Render.join();
        return;
    }

    std::string pointsText = "< Points:" + std::to_string(mPoints) + ">";
    mEngine->DrawText(mFontID, exVector2(50, 50), pointsText.c_str(), exColor{ 223,233,239,255 }, 5);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - mDeltaTime;

    const int FAIL_TIME = 20;

    if (elapsed.count() > FAIL_TIME)
    {
        ShellExecute(NULL, "open", "https://youtu.be/_asNhzXq72w", NULL, NULL, SW_SHOWNORMAL);

        // COLLAB WITH THE PRICE IS RIGHT
        exit(true);
    }

    //for (auto it = mExplosions.begin(); it != mExplosions.end(); )
    //{
    //    float radius = it->GetRadius();
    //
    //    radius *= 0.9f;
    //
    //    if (radius <= 0.0f)
    //    {
    //        it = mExplosions.erase(it);
    //    }
    //    else
    //    {
    //        unsigned char red = RANDOM_COLOR;
    //        unsigned char green = RANDOM_COLOR;
    //        unsigned char blue = RANDOM_COLOR;
    //
    //        mEngine->DrawCircle(it->GetPosition(), radius, exColor{ red, green, blue }, -1);
    //
    //        ++it;
    //    }
    //}

    std::thread GameObjectManager(&GameObjectManager::Update, GAME_OBJECT_MANAGER);
    std::thread Physics(&PhysicsEngine::PhysicsUpdate, PHYSICS_ENGINE);
    std::thread Render(&RenderingEngine::Render, RENDER_ENGINE, mEngine);
    GameObjectManager.join();
    Physics.join();
    Render.join();
}

void MyGame::AddExplosion(exVector2 position)
{
    mExplosions.push_back(Explosion(position));
}
