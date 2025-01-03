#pragma once

#include <iostream>
#include <algorithm>

constexpr int INCREASE_CAPACITY = 5;

template<typename T>
class SimpleVector
{
public :
	SimpleVector();
	SimpleVector(int capacity);
	SimpleVector(const SimpleVector& other);
	T getData(int num) { return data[num]; }
private :
	void resize(int capacity);

public:
	void push_back(const T& value);
	void pop_back();
	int size();
	int capacity();
	void sortData();
	~SimpleVector();
private:
	T* data;
	int currentSize;
	int currentCapacity;

};

template<typename T>
inline SimpleVector<T>::SimpleVector()
{
	currentSize = 0;
	currentCapacity = 10;

	data = new T[currentCapacity];

	std::cout << "기본 생성자 생성" << std::endl;
}

template<typename T>
inline SimpleVector<T>::SimpleVector(int capacity)
{
	currentSize = 0;
	currentCapacity = capacity;

	data = new T[currentCapacity];

	std::cout << "생성자 생성 크기 : " << capacity << std::endl;
}

template<typename T>
inline SimpleVector<T>::SimpleVector(const SimpleVector& other)
{
	currentSize = other.currentSize;
	currentCapacity = other.currentSize + INCREASE_CAPACITY;

	data = new T[currentCapacity];

	for (int i = 0; i < currentSize; i++)
	{
		data[i] = other.data[i];
	}


	std::cout << "생성자 복사" << std::endl;
}

template<typename T>
inline void SimpleVector<T>::resize(int capacity)
{
	if (capacity <= currentCapacity)
	{
		std::cout << "Resize return" << std::endl;
		return;
	}

	T* resizeData = new T[capacity];
	
	for (int i = 0; i < currentSize; i++)
	{
		resizeData[i] = data[i];
	}
	delete[] data;
	
	currentCapacity = capacity;

	data = resizeData;
}

template<typename T>
inline void SimpleVector<T>::push_back(const T& value)
{
	if (currentSize == currentCapacity)
	{
		resize(currentCapacity + INCREASE_CAPACITY);
	}

	data[currentSize] = value;
	std::cout << "Push Value : " << data[currentSize] << std::endl;
	currentSize++;
}

template<typename T>
inline void SimpleVector<T>::pop_back()
{
	if (currentSize < 0)
	{
		currentSize = 0;
		return;
	}

	std::cout << "Pop Value : " << data[currentSize] << std::endl;
	currentSize--;
}

template<typename T>
inline int SimpleVector<T>::size()
{
	return currentSize;
}

template<typename T>
inline int SimpleVector<T>::capacity()
{
	return currentCapacity;
}

template<typename T>
inline void SimpleVector<T>::sortData()
{
	std::sort(data, data + currentSize);
}

template<typename T>
inline SimpleVector<T>::~SimpleVector()
{
	if (data != NULL)
		delete[] data;

	std::cout << "소멸자 호출" << std::endl;
}
