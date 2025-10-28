#include "PaperFlipbookComponent.h"
#include "Vector.h"
#include "Actor.h"
#include <Windows.h>
#include <iostream>
#include "Engine.h"


UPaperFlipbookComponent::UPaperFlipbookComponent()
{
}

UPaperFlipbookComponent::~UPaperFlipbookComponent()
{
}

void UPaperFlipbookComponent::Tick()
{
}


void UPaperFlipbookComponent::Render()
{
	COORD Position;

	Position.X = GetOwner()->GetActorLocation().X;
	Position.Y = GetOwner()->GetActorLocation().Y;

	SetConsoleCursorPosition((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE), Position);
	cout << Shape;

	SDL_SetRenderDrawColor(GEngine->MyRenderer, Color.r, Color.g, Color.b, Color.a);
	int SizeX = 30;
	int SizeY = 30;
	//SDL_RenderDrawPoint(GEngine->MyRenderer, (float)Location.X, (float)Location.Y);
	SDL_FRect DrawRact = { GetOwner()->GetActorLocation().X * SizeX, 
		GetOwner()->GetActorLocation().Y * SizeY, SizeX, SizeY };
	SDL_RenderFillRect(GEngine->MyRenderer, &DrawRact);
}
