#include "Actor.h"
#include "Windows.h"
#include <iostream>
#include "Engine.h"

AActor::AActor() : Location(0, 0)
{
}

AActor::~AActor()
{
	//cout << "AActor ¼Ò¸êÀÚ" << "\n";
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
