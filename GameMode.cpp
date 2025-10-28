#include "GameMode.h"
#include <vector>
#include "Engine.h"
#include "World.h"
#include "Player.h"
#include "Monster.h"
#include "Goal.h"

using namespace std;

AGameMode::AGameMode()
{
}

AGameMode::~AGameMode()
{
}

void AGameMode::Tick()
{
	AActor* Player = nullptr;
	vector<AActor*> AllActors;
	GEngine->GetWorld()->GetAllActors(AllActors);
	for (auto Actor : AllActors) // Player Search
	{
		if (dynamic_cast<APlayer*>(Actor))
		{
			Player = dynamic_cast<APlayer*>(Actor);
			break;
		}
	}

	for (auto Actor : AllActors) // Monster Search
	{
		if (dynamic_cast<AMonster*>(Actor))
		{
			if (Player->GetActorLocation() == Actor->GetActorLocation())
			{
				//overlap = game over
				
				break;
			}
		}
	}

	for (auto Actor : AllActors) // Goal Search
	{
		if (dynamic_cast<AGoal*>(Actor))
		{
			if (Player->GetActorLocation() == Actor->GetActorLocation())
			{
				//Game Clear
				//exit(-1); //c lang
				break;
			}
		}
	}
	SDL_Log("deltaSeconds : %f", GEngine->GetWorldDeltaSeconds());
}