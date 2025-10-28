#include "Player.h"
#include "Engine.h"
#include "World.h"
#include "SDL3/SDL.h"
#include "PaperFlipbookComponent.h"

APlayer::APlayer()
{
	bIsCollision = true;
	bIsOverlap = true;

	UPaperFlipbookComponent* Paper = new UPaperFlipbookComponent();
	Paper->SetShape('P');
	Paper->SetOwner(this);
	Paper->ZOrder = 3;
	Paper->Color = SDL_Color{ 255, 0, 0, 255 };
	AddComponent(Paper);
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
