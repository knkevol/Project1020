#include "Actor.h"

AActor::AActor()
{
	cout << "AActor ������" << "\n";
}

AActor::~AActor()
{
	cout << "AActor �Ҹ���" << "\n";
}

void AActor::Tick()
{
	cout << "AActor Tick" << "\n";
}
