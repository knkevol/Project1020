#include "Goal.h"
#include "PaperFlipbookComponent.h"

AGoal::AGoal()
{
	UPaperFlipbookComponent* Paper = new UPaperFlipbookComponent();
	Paper->SetShape('G');
	Paper->SetOwner(this);
	Paper->ZOrder = 1000;
	Paper->Color = SDL_Color{ 255, 255, 0, 0 };
	AddComponent(Paper);
}

AGoal::~AGoal()
{
}
