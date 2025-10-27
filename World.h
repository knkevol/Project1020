#pragma once

#include <vector>
class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	std::vector<AActor*> GetAllActors(std::vector<AActor*>& OutActors) const;
	AActor* SpawnActor(AActor* NewActor);

	virtual void Tick();
	virtual void Render();

	virtual void SetSimulatePhysics();

	void SortActor();

protected:
	std::vector<AActor*> Actors;
};

