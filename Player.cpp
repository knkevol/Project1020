#include "Player.h"

APlayer::APlayer()
{
	cout << "APlayer ������" << "\n";
}

APlayer::~APlayer()
{
	cout << "APlayer �Ҹ���" << "\n";
}

void APlayer::Tick()
{
	AActor::Tick();
	cout << "APlayer Tick" << "\n";
}
