#include "Player.h"
#include "Engine.h"
#include "World.h"
#include "SDL3/SDL.h"

APlayer::APlayer()
{
	bIsCollision = true;
	bIsOverlap = true;
}

APlayer::~APlayer()
{
	//cout << "APlayer ¼Ò¸êÀÚ" << "\n";
}

void APlayer::Tick()
{
	// Move
	int KeyCode = GEngine->GetKeyCode();
	FVector2D SaveLocation(Location); //PreLocation

	if (KeyCode == SDLK_w)
	{
		Location.Y--;
	}
	else if (KeyCode == SDLK_a)
	{
		Location.X--;
	}
	else if (KeyCode == SDLK_S)
	{
		Location.Y++;
	}
	else if (KeyCode == SDLK_d)
	{
		Location.X++;
	}

	if (KeyCode == SDLK_ESCAPE)
	{
		exit(-1);
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
