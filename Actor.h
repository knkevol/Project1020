#pragma once

#include "Vector.h"
#include <vector>
using namespace std;

class UComponent;

class AActor
{
public:
	AActor();
	virtual ~AActor();

	virtual void Tick();

	__forceinline FVector2D GetActorLocation() const { return Location; }
	void SetActorLocation(FVector2D Value)
	{
		//Location = Value;
		Location.X = Value.X;
		Location.Y = Value.Y;
	}

	//GetComponent()
	
	//virtual void SetSimulatePhysics();
	virtual void ActorBeginOverlap();
	virtual void Hit();

	void SetupAttachment(UComponent* InComponent);
	vector<class UComponent*> Components;

protected:
	FVector2D Location;

public:
	
};