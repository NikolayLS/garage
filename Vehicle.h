#pragma once
#include "MyString.h"
class Vehicle
{
private:
	MyString regisrationNum;
	MyString description;
	size_t size;
public:
	Vehicle(const char* registration, const char* description, std::size_t space);
	Vehicle(const Vehicle&);
	Vehicle& operator=(const Vehicle&);
	~Vehicle();
	const MyString& registration() const;
	const MyString& getDescription() const;
	size_t getSize()const;

};

