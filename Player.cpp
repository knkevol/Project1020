#include "Player.h"
#include "Engine.h"
#include "World.h"

APlayer::APlayer()
{
	ZOrder = 3;
	bIsCollision = true;
	bIsOverlap = true;
	Color = { 255, 0, 0, 0 };
}

APlayer::~APlayer()
{
	//cout << "APlayer �Ҹ���" << "\n";
}

void APlayer::Tick()
{
	// Move
	int KeyCode = GEngine->GetKeyCode();
	FVector2D SaveLocation(Location); //PreLocation

	if (KeyCode == 'w')
	{
		Location.Y--;
	}
	else if (KeyCode == 'a')
	{
		Location.X--;
	}
	else if (KeyCode == 's')
	{
		Location.Y++;
	}
	else if (KeyCode == 'd')
	{
		Location.X++;
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
