#include "Goal.h"
#include "PaperFlipbookComponent.h"

AGoal::AGoal()
{
	Flipbook = new UPaperFlipbookComponent();
	Flipbook->SetShape('G');
	Flipbook->SetOwner(this);
	Flipbook->ZOrder = 1;
	Flipbook->Color = SDL_Color{ 255, 255, 0, 0 };
	SetupAttachment(Flipbook);
}

AGoal::~AGoal()
{
}
