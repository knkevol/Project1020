#include "Monster.h"
#include "Engine.h"
#include "World.h"
#include "Actor.h"
#include <vector>

AMonster::AMonster()
{
	ZOrder = 2;
	bIsCollision = true;
	bIsCollision = true;
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	int MonsterPosition = rand() % 4;
	FVector2D SaveLocation(Location); //PreLocation
	

	switch (MonsterPosition)
	{
	case 0:
		Location.Y++;
	case 1:
		Location.X++;
	case 2:
		Location.Y--;
	case 3:
		Location.X--;
	}

	vector<AActor*> AllActors;
	GEngine->GetWorld()->GetAllActors(AllActors);

	bool bFlag = false;
	for (auto OtherActor : AllActors)
	{
		if (CheckCollision(OtherActor) && this != OtherActor)
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
