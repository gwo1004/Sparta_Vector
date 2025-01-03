#include <iostream>
#include "SimpleVector.h"

int main() {
	
	SimpleVector<int>* pVec = new SimpleVector<int>();

	for(int i = 10; i > 0; i--)
	{
		pVec->push_back(i);
	}

	std::cout << "Size : " << pVec->size() << std::endl;
	std::cout << "Capacity : " << pVec->capacity() << std::endl;

	pVec->sortData();
	for (int i = 0; i < pVec->size(); i++)
	{
		std::cout << pVec->getData(i) << std::endl;
	}

	pVec->push_back(7);
	std::cout << "Size : " << pVec->size() << std::endl;
	std::cout << "Capacity : " << pVec->capacity() << std::endl;

	std::cout << "----------------------------------------------" << std::endl;
	SimpleVector<int>* pVec2 = new SimpleVector<int>(20);
	std::cout << "----------------------------------------------" << std::endl;

	std::cout << "----------------------------------------------" << std::endl;
	SimpleVector<int> pVec3 = *pVec; // 이상없음
	std::cout << "----------------------------------------------" << std::endl;


	return 0;
}