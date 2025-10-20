#include "Engine.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <algorithm>

#include "Actor.h"
#include "Wall.h"
#include "World.h"
#include "Player.h"
#include "Monster.h"
#include "Goal.h"
#include "Floor.h"

FEngine* FEngine::Instance = nullptr;

using namespace std;

FEngine::FEngine()
{
}

FEngine::~FEngine()
{
}

void FEngine::Init()
{
	World = new UWorld;

	ifstream MapFile("Level101.map");
	if (MapFile.is_open())
	{
		char Buffer[1024] = { 0, };
		int Y = 0;
		while (MapFile.getline(Buffer, 80)) // Y
		{
			string Line = Buffer;
			for (int X = 0; X < Line.size(); ++X) // X
			{
				if (Line[X] == '*')
				{
					AActor* NewActor = new AWall();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'P')
				{
					AActor* NewActor = new APlayer();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'M')
				{
					AActor* NewActor = new AMonster();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'G')
				{
					AActor* NewActor = new AGoal();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				//else if (Line[X] == ' ')
				
				AActor* NewActor = new AFloor();
				NewActor->SetActorLocation(FVector2D(X, Y));
				NewActor->SetShape(' ');
				World->SpawnActor(NewActor);
				
			}
			Y++;
		}
		
		vector<AActor*> ActorsList = World->GetAllActors();
		sort(ActorsList.begin(), ActorsList.end(), [](const AActor* A, const AActor* B)
			{ return A->GetZOrder() < B->GetZOrder(); });
		MapFile.close();
	}
}

void FEngine::Run()
{
	while (bIsRunning)
	{
		Input();
		Tick();
		Render();
	}
}

void FEngine::Term()
{
	bIsRunning = false;
}

void FEngine::Input()
{
	KeyCode = _getch();
}

void FEngine::Tick()
{
	GetWorld()->Tick();
}

void FEngine::Render()
{
	GetWorld()->Render();
}
