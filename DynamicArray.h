#pragma once
#include <iostream>
#include <stdio.h>

//언리얼형식 네이밍
template<typename T>
class TDynamicArray //Template (TArray) 언리얼식벡터
{
public:
	TDynamicArray() {}
	virtual ~TDynamicArray() 
	{
		if (Data)
		{
			delete[] Data;
		}
	}

protected:
	T* Data = nullptr; // 실제 사용하는 데이터의 크기
	size_t Size = 0;
	size_t Capacity = 0; // 사용하지 않는 공간. 자료의 크기
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
		return Data[_Idx]; //복사하지말고 위치값을 줘야 메모리성능
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

