#pragma once

#include "Actor.h"

class APlayer : public AActor
{
public:
	APlayer();
	virtual ~APlayer();

	void Tick() override;

	//overloading
	void Jump();
	void Jump(int a);
	void Jump(float a);
};