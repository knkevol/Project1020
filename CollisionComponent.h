#pragma once
#include "Component.h"

class AActor;

class UCollisionComponent : public UComponent
{
public:
	UCollisionComponent();
	virtual ~UCollisionComponent();

	virtual void Tick() override;

	//Implement same as UE
	bool CheckCollision(const UCollisionComponent* InOtherComp);


	bool bIsCollision = false;
	bool bIsOverlap = true;
};

