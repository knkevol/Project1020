#pragma once
#include "SceneComponent.h"
#include <string>

#include "SDL3/SDL.h"

class UPaperFlipbookComponent : public USceneComponent
{
public:
	UPaperFlipbookComponent();
	virtual ~UPaperFlipbookComponent();

	virtual void Tick() override;
	virtual void Render() override;

	__forceinline char GetShape() { return Shape; }
	void SetShape(char Value)
	{
		Shape = Value;
	}

	void LoadBMP(std::string FileName);

	__forceinline char GetZOrder() const { return ZOrder; }
	int ZOrder = 0;

	SDL_Color Color = { 255, 255, 255, 255 };
	SDL_Surface* BitmapImage = nullptr; // In Memory(CPU) int
	SDL_Texture* Texture = nullptr; // In GPU float
	SDL_Color ColorKey = { 255, 0, 255, 255 };
	bool bAnimation = false;

	float SpriteCountX = 5;
	float SpriteCountY = 5;
	float XIndex = 0;
	float YIndex = 0;

	float ExecuteTime = 0.2f;
	float TotalTime = 0.f;

protected:
	char Shape = ' ';

};

