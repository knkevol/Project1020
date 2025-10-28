#include "Wall.h"
#include "PaperFlipbookComponent.h"

AWall::AWall()
{
	bIsCollision = true;
	bIsOverlap = false;

	UPaperFlipbookComponent* Paper = new UPaperFlipbookComponent();
	Paper->SetShape('*');
	Paper->SetOwner(this);
	Paper->ZOrder = 1;
	Paper->Color = SDL_Color{ 128, 128, 128, 0 };
	AddComponent(Paper);
}

AWall::~AWall()
{
}
