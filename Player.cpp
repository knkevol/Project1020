#include "Player.h"
#include "Engine.h"

APlayer::APlayer()
{
	ZOrder = 3;
}

APlayer::~APlayer()
{
	//cout << "APlayer ¼Ò¸êÀÚ" << "\n";
}

void APlayer::Tick()
{
	// Move
	int KeyCode = GEngine->GetKeyCode();

	if (KeyCode == 'w')
	{
		Location.Y--;
	}
	else if (KeyCode == 'a')
	{
		Location.X--;
	}
	else if (KeyCode == 's')
	{
		Location.Y++;
	}
	else if (KeyCode == 'd')
	{
		Location.X++;
	}
}
