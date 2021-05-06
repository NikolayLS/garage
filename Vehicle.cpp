#include "Vehicle.h"
Vehicle::Vehicle(const char* registration, const char* description, std::size_t space) :
	regisrationNum(registration), description(description) , size(space)
{}

Vehicle::Vehicle(const Vehicle& other):
	regisrationNum(other.regisrationNum), description(other.description), size(other.size){}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
	if(this!=&other)
	{
		this->regisrationNum = other.regisrationNum;
		this->description = other.description;
		this->size = other.size;
	}
	return *this;
}

Vehicle::~Vehicle(){}

const MyString& Vehicle::registration() const
{
	return this->regisrationNum;
}

const MyString& Vehicle::getDescription() const
{
	return this->description;
}

size_t Vehicle::getSize()const
{
	return this->size;
}