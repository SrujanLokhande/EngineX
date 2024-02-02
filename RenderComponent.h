#pragma once
#include "Component.h"
#include "Engine/Public/EngineInterface.h"

class RenderComponent : public Component , public std::enable_shared_from_this<RenderComponent>
{
public:

	RenderComponent() = delete;
	RenderComponent(std::shared_ptr<GameObject> owner, exColor color = {255});


	virtual ComponentTypes GetComponentType() const;

	// Game Event Functions
	virtual void BeginPlay();
	virtual void EndPlay();

	virtual void Tick();

	virtual void Render(exEngineInterface* engineIterface);
	void RenderBox(exEngineInterface* engineIterface);
	void SetColor(exColor color);

protected:

	exColor mColor;
};

