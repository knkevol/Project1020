#include "Wall.h"
#include "PaperFlipbookComponent.h"
#include "CollisionComponent.h"

AWall::AWall()
{
	UPaperFlipbookComponent* Paper = new UPaperFlipbookComponent();
	Paper->SetShape('*');
	Paper->SetOwner(this);
	Paper->ZOrder = 1;
	Paper->Color = SDL_Color{ 128, 128, 128, 0 };
	SetupAttachment(Paper);

	UCollisionComponent* CollisionComp = new UCollisionComponent();
	CollisionComp->SetOwner(this);;
	CollisionComp->bIsCollision = true;
	CollisionComp->bIsOverlap = false;
	SetupAttachment(CollisionComp);
}

AWall::~AWall()
{
}
