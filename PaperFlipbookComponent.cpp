#include "PaperFlipbookComponent.h"
#include "Vector.h"
#include "Actor.h"
#include <Windows.h>
#include <iostream>
#include "Engine.h"
#include "Input.h"
#include "Player.h"


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
	TotalTime += (float)GEngine->GetWorldDeltaSeconds();

	if (TotalTime < ExecuteTime)
	{
		return;
	}
	TotalTime = 0.f;

	if (bAnimation)
	{
		XIndex = (float)(((int)XIndex) % (int)SpriteCountX);
		YIndex = (float)(((int)YIndex) % (int)SpriteCountY);

		SDL_Log("Index X : %f", XIndex);
	}
	else
	{
		XIndex = 0.f;
		YIndex = 0.f;
	}
}


void UPaperFlipbookComponent::Render()
{
	//** Console
	//COORD Position;
	//Position.X = GetOwner()->GetActorLocation().X;
	//Position.Y = GetOwner()->GetActorLocation().Y;
	//SetConsoleCursorPosition((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE), Position);
	//cout << Shape;
	int SizeX = 30;
	int SizeY = 30;
	if (!BitmapImage && !Texture)
	{
		SDL_SetRenderDrawColor(GEngine->MyRenderer, Color.r,
			Color.g, Color.b, Color.a);


		//SDL_RenderDrawPoint(GEngine->MyRenderer, (float)Location.X, (float)Location.Y);
		SDL_FRect DrawRect =
		{
			(float)(GetOwner()->GetActorLocation().X * SizeX),
			(float)(GetOwner()->GetActorLocation().Y * SizeY),
			(float)SizeX,
			(float)SizeY
		};
		SDL_RenderFillRect(GEngine->MyRenderer, &DrawRect);
	}
	else
	{
		SDL_FRect SourceRect;
		if (bAnimation)
		{
			float SpirteSizeX = (float)BitmapImage->w / SpriteCountX;
			float SpirteSizeY = (float)BitmapImage->h / SpriteCountY;
			SourceRect = {
				XIndex * SpirteSizeX,
				YIndex * SpirteSizeY,
				SpirteSizeX,
				SpirteSizeY
			};
		}
		else
		{
			SourceRect = { 0, 0, (float)BitmapImage->w, (float)BitmapImage->h };
		}

		SDL_FRect DestinationRect = {
			(float)(GetOwner()->GetActorLocation().X * SizeX),
			(float)(GetOwner()->GetActorLocation().Y * SizeY),
			(float)SizeX,
			(float)SizeY
		};
		SDL_RenderCopy(GEngine->MyRenderer, Texture, &SourceRect, &DestinationRect);
	}

	
}

void UPaperFlipbookComponent::LoadBMP(std::string FileName)
{
	// GPU, CPU Memory Setting | Require Destroy 
	BitmapImage = SDL_LoadBMP(FileName.c_str());
	// BackgroundColor Remove
	SDL_SetColorKey(BitmapImage, true, SDL_MapRGBA(SDL_GetPixelFormatDetails(BitmapImage->format),
		nullptr,
		ColorKey.r,
		ColorKey.g,
		ColorKey.b,
		ColorKey.a));

	Texture = SDL_CreateTextureFromSurface(GEngine->MyRenderer, BitmapImage);


}
