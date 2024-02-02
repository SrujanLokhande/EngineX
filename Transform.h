#pragma once
#include "Component.h"
#include "CoreMinimal.h"


class Transform : public Component
{
public:
	Transform() = delete;
	Transform(exVector2 loc, exVector2 rot, exVector2 scale, std::shared_ptr<GameObject> owner);

	virtual ComponentTypes GetComponentType() const override;

	// Game Event Functions
	virtual void BeginPlay() override;
	virtual void EndPlay() override;
	virtual void Tick() override;

	exVector2 GetPosition() const;
	exVector2 GetSize() const;
	void SetPosition(const exVector2&  newPosition);

private:

	exVector2 mLocation;
	exVector2 mScale;
	exVector2 mRotation;
};

