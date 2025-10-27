#pragma once
#include <iostream>
#include <stdio.h>

//�𸮾����� ���̹�
template<typename T>
class TDynamicArray //Template (TArray) �𸮾�ĺ���
{
public:
	//basic constructor
	TDynamicArray() {}
	//copy constructor
	TDynamicArray(const TDynamicArray<T>& RHS)
	{
		this->Size = RHS.Size;
		this->Capacity = RHS.Capacity;
		this->CurIdx = RHS.CurIdx;

		this->Data = new T[Capacity];
		memcpy(this->Data, RHS.Data, Size * sizeof(T));
	}
	virtual ~TDynamicArray() 
	{
		if (Data)
		{
			delete[] Data;
		}
	}

	//���Կ�����
	TDynamicArray<T>& operator=(const TDynamicArray<T>& RHS)
	{
		this->Size = RHS.Size;
		this->Capacity = RHS.Capacity;
		this->CurIdx = RHS.CurIdx;

		this->Data = new T[Capacity];
		memcpy(this->Data, RHS.Data, Size * sizeof(T));

		return *this;
	}

protected:
	T* Data = nullptr; // real data size
	size_t Size = 0; // use space
	size_t Capacity = 0; // not use space
	size_t CurIdx = 0;

public:
	size_t GetSize()
	{
		return Size;
	}

	size_t GetCapacity()
	{
		return Capacity;
	}

	T& operator[](size_t _Idx)
	{
		return Data[_Idx]; //deliver position = high memory performance
	}

	void PushBack(T Value)
	{
		if (CurIdx < Capacity)
		{
			Data[CurIdx] = Value;
			CurIdx++;
			Size++;
		}
		else
		{
			if (Capacity == 0)
			{
				Capacity = 1;
			}
			int* IncreaseData = new int[Capacity * 2];


			//memory copy
			//for (size_t i = 0; i < Size; ++i)
			//{
			//	IncreaseData[i] = Data[i];
			//}

			memcpy(IncreaseData, Data, Size * sizeof(T));
			//memmove(IncreaseData, Data, Size * sizeof(int));

			if (Data)
			{
				delete[] Data;
			}

			Data = IncreaseData;
			Capacity = Capacity * 2;
			Size++;
			Data[CurIdx] = Value;
			CurIdx++;

		}
	}
};

