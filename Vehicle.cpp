#include "Vehicle.h"
Vehicle::Vehicle(const char* registration, const char* description, std::size_t space) :
	registration(registration), description(description), size(space)
{
	if (!space) throw std::invalid_argument("wrong size");
}

Vehicle::Vehicle(const Vehicle& other) :
	registration(other.registration), description(other.description), size(other.size) {}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
	if (this != &other)
	{
		this->registration = other.registration;
		this->description = other.description;
		this->size = other.size;
	}
	return *this;
}
Vehicle::~Vehicle() {}

const String& Vehicle::getRegistration() const
{
	return this->registration;
}

String Vehicle::getDescription() const
{
	return this->description;
}

size_t Vehicle::getSize()const
{
	return this->size;
}

bool Vehicle::operator==(const Vehicle& other)const
{
	return (this->description == other.description) && (this->size == other.size)
		&& (this->registration == other.registration);
}