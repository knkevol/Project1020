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

	__forceinline FVector2D GetActorLocation() const { return Location; }
	void SetActorLocation(FVector2D Value)
	{
		//Location = Value;
		Location.X = Value.X;
		Location.Y = Value.Y;
	}

private:
	FVector2D Location;
};