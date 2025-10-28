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
#include "GameMode.h"
#include "Timer.h"
#include "Input.h"


#pragma comment(lib, "SDL3") //x64 SDL3.lib

FEngine* FEngine::Instance = nullptr;



FEngine::FEngine() : 
	World(nullptr), MyEvent(SDL_Event())
{
	MyRenderer = nullptr;
	MyWindow = nullptr;
	Timer = new UTimer();
	InputDevice = new UInput();
}

FEngine::~FEngine()
{
	if (Timer)
	{
		delete Timer;
	}
	
	if (World)
	{
		delete World;
	}

	if (InputDevice)
	{
		delete InputDevice;
	}
	
}

void FEngine::Init()
{

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	MyWindow = SDL_CreateWindow("GameEngine", 800, 600, SDL_WINDOW_OPENGL);
	MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);

	OpenLevel();
	
}

void FEngine::OpenLevel()
{
	srand((unsigned int)time(nullptr));

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

		//vector<AActor*> ActorsList = World->GetAllActors();
		//sort(ActorsList.begin(), ActorsList.end(), [](const AActor* A, const AActor* B)
		//	{ return A->GetZOrder() < B->GetZOrder(); });
	}
	MapFile.close();
	World->SortActor();

	//UE Gameplay Framwork
	World->SpawnActor(new AGameMode());
}

void FEngine::Run()
{
	while (bIsRunning)
	{
		Timer->Tick();
		//1frame Tick
		SDL_PollEvent(&MyEvent); // event exist = input		
		Input();
		Tick();
		Render();
		
	}
}

void FEngine::Term()
{
	bIsRunning = false;

	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();
}

double FEngine::GetWorldDeltaSeconds() const
{
	return Timer->DeltaSeconds;
}

void FEngine::Input()
{
	InputDevice->Tick();
	//KeyCode = _getch();
}

void FEngine::Tick()
{
	
	GetWorld()->Tick();
}

void FEngine::Render()
{
	// screen clear
	SDL_SetRenderDrawColor(MyRenderer, 255, 255, 255, 0);
	SDL_RenderClear(MyRenderer);

	GetWorld()->Render();

	SDL_RenderPresent(MyRenderer);
}
