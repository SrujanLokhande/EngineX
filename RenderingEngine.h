#pragma once
#include <vector>
#include <memory>
#include "Engine/Public/EngineInterface.h"

#define RENDER_ENGINE RenderingEngine::GetInstance()

class RenderComponent;
class RenderingEngine
{

public:

	static RenderingEngine* GetInstance()
	{
		if (!sInstance)
		{
			sInstance = new RenderingEngine();
		}
		return sInstance;
	}

	void Render(exEngineInterface* mEngine);
	void RenderBox(exEngineInterface* mEngine);
	void AddRenderingComponent(std::shared_ptr<RenderComponent> componentToAdd);

private:

	RenderingEngine();

	std::vector<std::weak_ptr<RenderComponent>> mRenderComponents;
	static RenderingEngine* sInstance;
};