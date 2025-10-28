#include "Actor.h"
#include "Windows.h"
#include <iostream>
#include "Engine.h"

AActor::AActor()
{
	//cout << "AActor 持失切" << "\n";
	Shape = ' ';
	Location = 0, 0;
	//ZOrder = 0;
}

AActor::~AActor()
{
	//cout << "AActor 社瑚切" << "\n";
}

void AActor::Tick()
{
	//cout << "AActor Tick" << "\n";
}

void AActor::Render()
{
	COORD Position;

	Position.X = Location.X;
	Position.Y = Location.Y;

	SetConsoleCursorPosition((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE), Position);
	cout << Shape;

	SDL_SetRenderDrawColor(GEngine->MyRenderer, Color.r, Color.g, Color.b, Color.a);
	int SizeX = 30;
	int SizeY = 30;
	//SDL_RenderDrawPoint(GEngine->MyRenderer, (float)Location.X, (float)Location.Y);
	SDL_FRect DrawRact = {Location.X * SizeX, Location.Y * SizeY, SizeX, SizeY};
	SDL_RenderFillRect(GEngine->MyRenderer, &DrawRact);
}

bool AActor::CheckCollision(const AActor* Other)
{
	if (Other->bIsOverlap)
	{
		return false;
	}
	
	//Only Collision Check
	if ((Other->bIsCollision) && bIsCollision && (this->Location == Other->Location))
	{
		return true;
	}

	return false;
}

void AActor::ActorBeginOverlap()
{
}

void AActor::Hit()
{
}
