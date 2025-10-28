#pragma once

#include "Actor.h"

class UCollisionComponent;
class UPaperFlipbookComponent;

class APlayer : public AActor
{
public:
	APlayer();
	virtual ~APlayer();

	virtual void Tick() override;

	UCollisionComponent* Collision; //MyCollisionComp Search ¾ÈÇØµµµÊ
	UPaperFlipbookComponent* Flipbook;

};