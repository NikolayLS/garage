#pragma once
#include <iostream>
#include <exception>

class MyString
{
private:
	std::size_t length;
	char* str;
public:
	MyString();
	MyString(const char*);
	MyString(const MyString&);
	MyString(MyString&&)noexcept;
	~MyString();
	void clear();
	MyString& operator=(const MyString&);
	MyString& operator=(MyString&&)noexcept;
	char& at(const std::size_t);
	const char& at(const std::size_t) const;
	char& operator[](const std::size_t);
	const char& operator[](const std::size_t) const;
	char& front();
	const char& front()const;
	size_t size()const;
	void push_back(const char);
	friend std::ostream& operator<<(std::ostream&, const MyString&);
	friend std::istream& operator>>(std::istream&, MyString&);
	
};

