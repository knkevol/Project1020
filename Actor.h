#pragma once

#include "Vector.h"

#include <iostream>
using namespace std;

class AActor
{
public:
	AActor();
	virtual ~AActor();

	virtual void Tick();
	virtual void Render();

	__forceinline FVector2D GetActorLocation() const { return Location; }
	void SetActorLocation(FVector2D Value)
	{
		//Location = Value;
		Location.X = Value.X;
		Location.Y = Value.Y;
	}

	__forceinline char GetShape() { return Shape; }
	void SetShape(char Value)
	{
		Shape = Value;
	}

	__forceinline char GetZOrder() const { return ZOrder; }

	//Implement same as UE
	virtual bool CheckCollision(const AActor* Other);
	//virtual void SetSimulatePhysics();
	virtual void ActorBeginOverlap();
	virtual void Hit();

protected:
	FVector2D Location;
	char Shape;
	int ZOrder;
public:
	bool bIsCollision = false;
	bool bIsOverlap = true;
};