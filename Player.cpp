#include "Player.h"
#include "Engine.h"
#include "World.h"
#include "SDL3/SDL.h"
#include "PaperFlipbookComponent.h"
#include "CollisionComponent.h"

APlayer::APlayer()
{
	Flipbook = new UPaperFlipbookComponent();
	Flipbook->SetShape('P');
	Flipbook->SetOwner(this);
	Flipbook->ZOrder = 3;
	Flipbook->Color = SDL_Color{ 255, 0, 0, 255 };
	SetupAttachment(Flipbook);

	Collision = new UCollisionComponent();
	Collision->SetOwner(this);
	Collision->bIsCollision = true;
	Collision->bIsOverlap = true;
	SetupAttachment(Collision);
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
