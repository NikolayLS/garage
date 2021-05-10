#pragma once
#include "Vehicle.h"
#include <iostream>

class Garage
{
	Vehicle** vehicleArray;
	size_t carCount;
	size_t freeSpaces;
	size_t maxSpace;
	void freeMemory();
public:
	Garage(const size_t&);
	Garage(const Garage&);
	Garage(Garage&&)noexcept;
	Garage& operator=(const Garage&);
	Garage& operator=(Garage&&)noexcept;
	~Garage();
	void insert(const Vehicle& v);
	void erase(const String&);
	size_t carNum()const;
	const Vehicle& operator[](std::size_t pos) const;
	const Vehicle& at(std::size_t pos) const;
	bool empty() const;
	void clear();
	const Vehicle* find(const char* registration) const;
};

