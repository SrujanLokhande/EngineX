#pragma once
#include "RenderComponent.h"
class SquareRenderComponent :   public RenderComponent
{
public:

	SquareRenderComponent() = delete;
	SquareRenderComponent(float length, float height, std::shared_ptr<GameObject> owner, exColor color = { 255,0,0,255 });

	void Render(exEngineInterface* engineInterface) override;
	void BeginPlay() override;

private:
	float mLength;
	float mHeight;
};

