#include "Actor.h"

AActor::AActor()
{
	cout << "AActor 持失切" << "\n";
}

AActor::~AActor()
{
	cout << "AActor 社瑚切" << "\n";
}

void AActor::Tick()
{
	cout << "AActor Tick" << "\n";
}
