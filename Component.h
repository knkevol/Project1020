#pragma once

class AActor;

class Interface
{

};

//�߻�Ŭ����
class UComponent
{
public:
	UComponent();
	virtual ~UComponent();

	virtual void Tick() = 0; //���������Լ�->interface

	AActor* GetOwner() const;
	void SetOwner(AActor* InOwner);

protected:
	AActor* Owner;
};

