#pragma once

#include "Vector.h"
#include "SDL3/SDL.h"
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

	

	//Implement same as UE
	virtual bool CheckCollision(const AActor* Other);
	//virtual void SetSimulatePhysics();
	virtual void ActorBeginOverlap();
	virtual void Hit();

	void AddComponent(UComponent* InComponent);

protected:
	FVector2D Location;
	

	vector<class UComponent*> Components;
public:
	bool bIsCollision = false;
	bool bIsOverlap = true;

	
};