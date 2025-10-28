#include "Actor.h"
#include "Windows.h"
#include <iostream>
#include "Engine.h"

AActor::AActor()
{
	//cout << "AActor 持失切" << "\n";
	//Shape = ' ';
	Location = 0, 0;
	//ZOrder = 0;
}

AActor::~AActor()
{
	//cout << "AActor 社瑚切" << "\n";
}

void AActor::Tick()
{
	//cout << "AActor Tick" << "\n";
}

//void AActor::Render()
//{
//	
//}

bool AActor::CheckCollision(const AActor* Other)
{
	if (Other->bIsOverlap)
	{
		return false;
	}
	
	//Only Collision Check
	if ((Other->bIsCollision) && bIsCollision && (this->Location == Other->Location))
	{
		return true;
	}

	return false;
}

void AActor::ActorBeginOverlap()
{
}

void AActor::Hit()
{
}

void AActor::AddComponent(UComponent* InComponent)
{
	Components.push_back(InComponent);
}
