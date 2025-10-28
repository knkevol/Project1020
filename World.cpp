﻿#include "World.h"
#include "Actor.h"
#include "SceneComponent.h"
#include "PaperFlipbookComponent.h"
#include <algorithm>

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
}

void UWorld::GetAllActors(std::vector<AActor*>& OutActors) const
{
	OutActors = Actors;
}
//팩토리 패턴(생성도 이함수가 함)
AActor* UWorld::SpawnActor(AActor* NewActor)
{
	Actors.push_back(NewActor);

	return NewActor;
}

void UWorld::Tick()
{
	//All Actors Process.
	for (auto Actor : Actors)
	{
		//runtime시에 결정됨. 문제는 이놈이 문제.
		Actor->Tick();
	}
}

void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		for (auto Component : Actor->Components)
		{
			USceneComponent* Scene = dynamic_cast<USceneComponent*>(Component);
			if (Scene)
			{
				Scene->Render();
			}
		}
	}
}



//[][][][][]
void UWorld::SortActor()
{
	std::sort(Actors.begin(), Actors.end(), [](const AActor* A, const AActor* B) {
		UPaperFlipbookComponent* Scene1 = nullptr;
		for (auto Component : A->Components)
		{
			Scene1 = dynamic_cast<UPaperFlipbookComponent*>(Component);
			if (Scene1)
			{
				break;
			}
		}
		UPaperFlipbookComponent* Scene2 = nullptr;
		for (auto Component : B->Components)
		{
			Scene2 = dynamic_cast<UPaperFlipbookComponent*>(Component);
			if (Scene2)
			{
				break;
			}
		}

		if (!Scene1 || !Scene2)
		{
			return false;
		}

		return (Scene1->GetZOrder() < Scene2->GetZOrder());
		});

	for (int j = 0; j < Actors.size(); ++j)
	{
		//선택한 액터
		UPaperFlipbookComponent* Scene1 = nullptr;
		for (auto Component : Actors[j]->Components)
		{
			Scene1 = dynamic_cast<UPaperFlipbookComponent*>(Component);
			if (Scene1)
			{
				break;
			}
		}

		if (!Scene1)
		{
			continue;
		}

		for (int i = 0; i < Actors.size(); ++i)
		{
			UPaperFlipbookComponent* Scene2 = nullptr;
			for (auto Component : Actors[i]->Components)
			{
				Scene2 = dynamic_cast<UPaperFlipbookComponent*>(Component);
				if (Scene2)
				{
					break;
				}
			}

			if (!Scene2)
			{
				continue;
			}


			if (Scene1->GetZOrder() < Scene2->GetZOrder())
			{
				AActor* Temp = Actors[j];
				Actors[j] = Actors[i];
				Actors[i] = Temp;
			}
		}
	}
}