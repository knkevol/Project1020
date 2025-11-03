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
	if (BitmapImage)
	{
		SDL_DestroySurface(BitmapImage);
		BitmapImage = nullptr;
	}

	if (Texture)
	{
		SDL_DestroyTexture(Texture);
		Texture = nullptr;
	}
}

void UPaperFlipbookComponent::Tick()
{
}


void UPaperFlipbookComponent::Render()
{
	//** Console
	//COORD Position;
	//Position.X = GetOwner()->GetActorLocation().X;
	//Position.Y = GetOwner()->GetActorLocation().Y;
	//SetConsoleCursorPosition((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE), Position);
	//cout << Shape;
	int SizeX = 40;
	int SizeY = 40;

	if (!BitmapImage && !Texture)
	{
		SDL_SetRenderDrawColor(GEngine->MyRenderer, Color.r, Color.g, Color.b, Color.a);
		
		//SDL_RenderDrawPoint(GEngine->MyRenderer, (float)Location.X, (float)Location.Y);
		SDL_FRect DrawRact = {
			(float)(GetOwner()->GetActorLocation().X * SizeX),
			(float)(GetOwner()->GetActorLocation().Y * SizeY),
			(float)SizeX,
			(float)SizeY };
		SDL_RenderFillRect(GEngine->MyRenderer, &DrawRact);
	}
	else
	{

		
		SDL_FRect SourceRect = { 0, 0, (float)BitmapImage->w, (float)BitmapImage->h }; // ImageFile w, h
		SDL_FRect DestRect = { 
		(float)(GetOwner()->GetActorLocation().X * SizeX),
			(float)(GetOwner()->GetActorLocation().Y * SizeY),
			(float)SizeX,
			(float)SizeY }; // Draw Location and Size
		SDL_RenderCopy(GEngine->MyRenderer, Texture, &SourceRect, &DestRect);
	}

	
}

void UPaperFlipbookComponent::LoadBMP(std::string FileName)
{
	// GPU, CPU Memory Setting | Require Destroy 
	BitmapImage = SDL_LoadBMP(FileName.c_str());
	Texture = SDL_CreateTextureFromSurface(GEngine->MyRenderer, BitmapImage);


}
