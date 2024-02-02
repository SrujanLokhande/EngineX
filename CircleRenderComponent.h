#pragma once
#include "RenderComponent.h"

class CircleRenderComponent :   public RenderComponent
{
public:

	CircleRenderComponent() = delete;
	CircleRenderComponent(float radius, std::shared_ptr<GameObject> owner, exColor color = {255,255,0,255});

	void Render(exEngineInterface* engineInterface) override;

	exColor GetColor() const;

private:
	float mRadius;
};

