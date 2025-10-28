#pragma once

class AActor;

class IInterface
{
public:
	virtual void Tick() = 0;
};

//추상클래스
class UComponent
{
public:
	UComponent();
	virtual ~UComponent();

	virtual void Tick() = 0; //순수가상함수->interface

	AActor* GetOwner() const;
	void SetOwner(AActor* InOwner);

protected:
	AActor* Owner;
};

