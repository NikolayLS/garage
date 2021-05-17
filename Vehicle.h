#pragma once
#include "String.h"
#include <iostream>
class Vehicle
{
	String registration;
	String description;
	size_t size;

public:
	
	Vehicle(const char* registration, const char* description, std::size_t space);
	Vehicle(const Vehicle&);
	Vehicle& operator=(const Vehicle&);
	bool operator==(const Vehicle&)const;
	~Vehicle();
	const String& getRegistration() const;
	String getDescription() const;
	size_t getSize()const;

};

