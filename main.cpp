#include "Engine.h"
using namespace std;


int main()
{
	GEngine->Init();
	GEngine->Run();
	GEngine->Term();

	delete GEngine;

	return 0;
}