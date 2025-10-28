#include "Monster.h"
#include "Engine.h"
#include "World.h"
#include "Actor.h"
#include <vector>
#include "PaperFlipbookComponent.h"
#include "CollisionComponent.h"
#include "Component.h"

AMonster::AMonster()
{
	Flipbook = new UPaperFlipbookComponent();
	Flipbook->SetShape('M');
	Flipbook->SetOwner(this);
	Flipbook->ZOrder = 2;
	Flipbook->Color = SDL_Color{ 0, 0, 255, 0 };
	SetupAttachment(Flipbook);

	Collision = new UCollisionComponent();
	Collision->SetOwner(this);
	Collision->bIsCollision = true;
	Collision->bIsOverlap = true;
	SetupAttachment(Collision);
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	TotalTime += (float)GEngine->GetWorldDeltaSeconds();

	if (TotalTime < ExecuteTime)
	{
		return;
	}
	TotalTime = 0.f;

	int KeyCode = rand() % 4;

	FVector2D SaveLocation;
	SaveLocation = Location;

	if (KeyCode == 0)
	{
		Location.Y--;
	}
	if (KeyCode == 1)
	{
		Location.Y++;
	}
	if (KeyCode == 2)
	{
		Location.X--;
	}
	if (KeyCode == 3)
	{
		Location.X++;
	}
	std::vector<AActor*> AllActors;
	GEngine->GetWorld()->GetAllActors(AllActors);

	bool bFlag = false;

	//Other CollisionComp Search
	for (auto OtherActor : AllActors)
	{
		for (auto Component : OtherActor->Components)
		{
			UCollisionComponent* OtherCollision = dynamic_cast<UCollisionComponent*>(Component);
			if (OtherCollision)
			{
				if (Collision->CheckCollision(OtherCollision))
				{
					bFlag = true;
					break;
				}
			}
		}
	}

	if (bFlag)
	{
		Location = SaveLocation;
	}

}
