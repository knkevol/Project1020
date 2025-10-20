#include "Player.h"

APlayer::APlayer()
{
	cout << "APlayer 持失切" << "\n";
}

APlayer::~APlayer()
{
	cout << "APlayer 社瑚切" << "\n";
}

void APlayer::Tick()
{
	AActor::Tick();
	cout << "APlayer Tick" << "\n";
}
