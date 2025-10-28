#include "Floor.h"
#include "PaperFlipbookComponent.h"

AFloor::AFloor()
{
	UPaperFlipbookComponent* Paper = new UPaperFlipbookComponent();
	Paper->SetShape(' ');
	Paper->SetOwner(this);
	Paper->ZOrder = 0;
	Paper->Color = SDL_Color{ 0, 0, 0, 0 };
	SetupAttachment(Paper);
	
}

AFloor::~AFloor()
{
}
