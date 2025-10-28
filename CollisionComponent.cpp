#include "CollisionComponent.h"
#include "Actor.h"

UCollisionComponent::UCollisionComponent()
{
}

UCollisionComponent::~UCollisionComponent()
{
}

void UCollisionComponent::Tick()
{

}


bool UCollisionComponent::CheckCollision(const UCollisionComponent* InOtherComp)
{
	if (InOtherComp->bIsOverlap)
	{
		return false;
	}

	//Only Collision Check
	if ((InOtherComp->bIsCollision) && this != InOtherComp && bIsCollision && (this->GetOwner()->GetActorLocation() == InOtherComp->GetOwner()->GetActorLocation()))
	{
		return true;
	}

	return false;
}