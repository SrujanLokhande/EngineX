#include "RenderingEngine.h"
#include "RenderComponent.h"


RenderingEngine* RenderingEngine::sInstance = nullptr;

void RenderingEngine::Render(exEngineInterface* mEngine)
{
	for (std::weak_ptr<RenderComponent> componentToRender : mRenderComponents)
	{
		if (!componentToRender.expired())
		{
			componentToRender.lock()->Render(mEngine);

		}
	}
}

void RenderingEngine::RenderBox(exEngineInterface* mEngine)
{
	for (std::weak_ptr<RenderComponent> componentToRender : mRenderComponents)
	{
		if (!componentToRender.expired())
		{
			componentToRender.lock()->RenderBox(mEngine);

		}		
	}
}

void RenderingEngine::AddRenderingComponent(std::shared_ptr<RenderComponent> componentToAdd)
{
	mRenderComponents.push_back(componentToAdd);
}

RenderingEngine::RenderingEngine()
{
}
