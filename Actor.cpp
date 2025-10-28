#include "Actor.h"
#include <Windows.h>
#include <iostream>
#include "Engine.h"
#include "Component.h"

AActor::AActor() : Location(0, 0)
{
}

AActor::~AActor()
{
	for (auto Component : Components)
	{
		delete Component;
	}
}

void AActor::Tick()
{
	//cout << "AActor Tick" << "\n";
}

//void AActor::Render()
//{
//	
//}

//bool AActor::CheckCollision(const AActor* Other)
//{
//	if (Other->bIsOverlap)
//	{
//		return false;
//	}
//	
//	//Only Collision Check
//	if ((Other->bIsCollision) && this != Other && bIsCollision && (this->Location == Other->Location))
//	{
//		return true;
//	}
//
//	return false;
//}

void AActor::ActorBeginOverlap()
{
}

void AActor::Hit()
{
}

void AActor::SetupAttachment(UComponent* InComponent)
{
	Components.push_back(InComponent);
}
