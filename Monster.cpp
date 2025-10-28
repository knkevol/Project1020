#include "Monster.h"
#include "Engine.h"
#include "World.h"
#include "Actor.h"
#include <vector>
#include "PaperFlipbookComponent.h"

AMonster::AMonster()
{
	bIsCollision = true;
	bIsOverlap = true;
	UPaperFlipbookComponent* Paper = new UPaperFlipbookComponent();
	Paper->SetShape('M');
	Paper->SetOwner(this);
	Paper->ZOrder = 2;
	Paper->Color = SDL_Color{ 0, 0, 255, 0 };
	AddComponent(Paper);
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

	for (auto OtherActor : AllActors)
	{
		if (CheckCollision(OtherActor))
		{
			bFlag = true;
			break;
		}
	}

	if (bFlag)
	{
		Location = SaveLocation;
	}

}
