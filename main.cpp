#include <iostream>
#include "Actor.h"
#include "Player.h"

#include <vector>

int main()
{
	vector<AActor*> Actors;
	Actors.push_back(new AActor());


	AActor* MyActor = new APlayer;

	MyActor->Tick();

	delete MyActor;

	return 0;
}