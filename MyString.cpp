#include "MyString.h"
MyString::MyString() :str(nullptr), length(0)
{}

MyString::MyString(const char* otherString) : length(0)
{
	if (otherString == nullptr)this->str = nullptr;
	else
	{
		while (otherString[length] != '\0')
		{
			length++;
		}
		this->str = new char[length];
		for (size_t i = 0;i < length;i++) str[i] = otherString[i];
	}
}

MyString::MyString(const MyString& otherString) : length(otherString.length)
{
	this->str = new char[this->length];
	for (size_t i = 0;i < length;i++) this->str[i] = otherString.str[i];
}

MyString::MyString(MyString&& otherString) noexcept :length(otherString.length), str(otherString.str)
{

	otherString.str = nullptr;
	otherString.length = 0;
}

MyString& MyString::operator=(const MyString& otherString)
{
	if (this != &otherString)
	{
		delete[] this->str;
		this->str = new char[otherString.length];
		for (size_t i = 0;i < otherString.length;i++)
			this->str[i] = otherString.str[i];
		this->length = otherString.length;
	}
	return *this;
}

MyString& MyString::operator=(MyString&& otherString) noexcept
{
	if (this != &otherString)
	{
		delete[]this->str;
		this->str = otherString.str;
		this->length = otherString.length;
		otherString.str = nullptr;
		otherString.length = 0;
	}
	return *this;
}

size_t MyString::size()const
{
	return this->length;
}
char& MyString::at(const std::size_t pos)
{
	if (pos >= this->length) throw std::out_of_range("array out of range");
	return this->str[pos];
}

const char& MyString::at(const std::size_t pos)const
{
	if (pos >= this->length) throw std::out_of_range("array out of range");
	return this->str[pos];
}

char& MyString::operator[](const std::size_t pos)
{
	return this->str[pos];
}

const char& MyString::operator[](const std::size_t pos) const
{
	return this->str[pos];
}

char& MyString::front()
{
	return this->str[0];
}

const char& MyString::front()const
{
	return this->str[0];
}

MyString::~MyString()
{
	delete[] str;
}

std::ostream& operator<<(std::ostream& os, const MyString& string)
{
	for (size_t i = 0; i < string.length;i++)
		os << string.str[i];
	return os;
}
void MyString::clear()
{
	delete[]str;
	str = nullptr;
	length = 0;
}
void MyString::push_back(const char element)
{
	try
	{
		const MyString temp = *this;
		this->clear();
		this->str = new char[temp.length + 1];
		for (size_t i = 0; i < temp.length;i++)
		{
			this->str[i] = temp.str[i];
		}
		this->str[temp.length] = element;
		this->length = temp.length + 1;
	}
	catch (...)
	{
		delete this->str;
		this->str = nullptr;
		this->length = 0;
	}
}
std::istream& operator>>(std::istream& is, MyString& string)
{
	std::istream::sentry s(is);
	if (!s) return is;
	string.clear();
	int ch = is.peek();
	while (ch != EOF && isspace((unsigned char)ch))
	{
		string.push_back(is.get());
		ch = is.peek();
	}
	return is;
}