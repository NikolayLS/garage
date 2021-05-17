#include "Garage.h"

Garage::Garage(const size_t& sz) :vehicleArray(nullptr), carCount(0), freeSpaces(sz), maxSpace(sz)
{
	if (sz)
	{
		this->vehicleArray = new Vehicle * [sz];
	}
}

Garage::Garage(const Garage& other)
	: vehicleArray(nullptr), carCount(other.carCount), freeSpaces(other.freeSpaces), maxSpace(other.maxSpace)
{
	if (other.maxSpace)
	{
		this->vehicleArray = new Vehicle * [other.maxSpace];
		for (size_t i = 0; i < other.maxSpace && other.carCount;i++)
			this->vehicleArray[i] = new Vehicle(*(other.vehicleArray[i]));
	}
}

Garage::Garage(Garage&& other)noexcept
	: vehicleArray(other.vehicleArray), carCount(other.carCount), freeSpaces(other.freeSpaces), maxSpace(other.maxSpace)
{
	other.carCount = 0;
	other.vehicleArray = nullptr;
	other.freeSpaces = 0;
	other.maxSpace = 0;
}
void Garage::freeMemory()
{
	if (this->vehicleArray != nullptr)
	{
		for (size_t i = 0;i < carCount;i++)
			delete vehicleArray[i];
		delete[] vehicleArray;
		this->vehicleArray = nullptr;
	}
}

Garage& Garage::operator=(const Garage& other)
{
	if (this != &other)
	{
		if (other.vehicleArray == nullptr)
		{
			this->vehicleArray = nullptr;
			this->freeSpaces = 0;
			this->maxSpace = 0;
			this->carCount = 0;
		}
		else
		{
			//strong exception guarantee
			auto** temp = new Vehicle * [other.maxSpace];
			for (size_t i = 0;i < other.maxSpace && i < other.carCount;i++)
				temp[i] = new Vehicle(*(other.vehicleArray[i]));

			freeMemory();
			this->vehicleArray = temp;
			this->freeSpaces = other.freeSpaces;
			this->maxSpace = other.maxSpace;
			this->carCount = other.carCount;
		}
	}
	return *this;
}
Garage& Garage::operator=(Garage&& other)noexcept
{
	if (this != &other)
	{
		this->carCount = other.carCount;
		this->freeSpaces = other.freeSpaces;
		this->maxSpace = other.maxSpace;
		this->vehicleArray = other.vehicleArray;

		other.carCount = 0;
		other.vehicleArray = nullptr;
		other.freeSpaces = 0;
		other.maxSpace = 0;
	}
	return *this;
}

Garage::~Garage()
{
	this->freeMemory();
}

void Garage::insert(const Vehicle& v)
{
	//strong exception guarantee
	if (this->freeSpaces < v.getSize()) throw std::out_of_range("not enough space");

	auto* temp = new Vehicle(v);
	//if upper line does not throw exception
	this->vehicleArray[carCount] = temp;
	this->carCount++;
	this->freeSpaces -= v.getSize();
}

void Garage::erase(const String& registration)
{
	if (this->vehicleArray == nullptr) return;
	
	for (size_t i = 0;i < this->carCount;i++)
	{
		if (this->vehicleArray[i]->getRegistration() == registration)
		{
			//can change the order
			this->freeSpaces += vehicleArray[i]->getSize();
			this->carCount -= 1;
			delete this->vehicleArray[i];
			this->vehicleArray[i] = vehicleArray[carCount];
			this->vehicleArray[carCount] = nullptr;
		}
	}
}

size_t Garage::carNum()const
{
	return this->carCount;
}

const Vehicle& Garage::operator[](const size_t& pos) const
{
	//assume that operator[] will be called with correct parameter
	return *(this->vehicleArray[pos]);
}

const Vehicle& Garage::at(const size_t& pos) const
{
	if (pos >= this->carCount) throw std::out_of_range("no car at this position");
	return *(this->vehicleArray[pos]);
}

bool Garage::empty() const
{
	return !(this->carCount);
}

void Garage::clear()
{
	this->freeMemory();
	this->carCount = 0;
	this->freeSpaces = this->maxSpace;
}

const Vehicle* Garage::find(const char* registration) const
{
	for (size_t i = 0;i < this->carCount;i++)
	{
		if ((this->vehicleArray[i]->getRegistration()) == registration)
			return this->vehicleArray[i];
	}
	return nullptr;
}

