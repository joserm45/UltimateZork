#include "String.h"
#include <stdlib.h>
#include <stdio.h>
mString::mString(char* str)
	{

		printf("\nConstructor");

		capacity = strlen(str);

		buffer = new char[capacity + 1];

		strcpy_s(buffer, capacity + 1, str);

	}
mString::mString(const mString& str) //copy constructor
{
	capacity = str.capacity;

	buffer = new char[capacity + 1];

	strcpy_s(buffer, capacity + 1, str.buffer);

}
const char* mString::c_str()const
{
	return buffer;
}
bool mString::empty()const
{
	return  (capacity == 0);
}

unsigned int mString::lenght() const
{
	return capacity;
}


void mString::operator = (const  mString& other)
{
	printf("\nCalling operaor =");

	if (capacity < other.capacity)
	{
		delete[] buffer;
		capacity = other.capacity;
		buffer = new char[capacity + 1];

	}
	strcpy_s(buffer, capacity + 1, other.buffer);

}

void mString::operator +=(const  mString& other)
{
	printf("\nCalling operaor +=");

	if (capacity < capacity + other.capacity)
	{
		int len = capacity;
		char* tmp = new char[capacity + 1];
		strcpy_s(tmp, capacity + 1, buffer);
		delete[] buffer;
		capacity = capacity + other.capacity;
		buffer = new char[capacity + 1];
		strcpy_s(buffer, len + 1, tmp);
	}

	strcat_s(buffer, capacity + 1, other.buffer);

}

bool mString::operator == (const mString& other) const
{

	return strcmp(buffer, other.buffer) == 0;
}

/*bool mString::operator == (const char* other) const
{

	return strcmp(buffer, other) == 0;
}*/
	/*mString string1("hello");
	mString string2("h");
	int i = string2.lenght();

	printf("\nstring 1: %s", string1.c_str());
	printf("\nstring 2: %s", string2.c_str());

	string1 = string2;
	printf("\noperator =:");
	printf("\nstring 1: %s", string1.c_str());
	printf("\nstring 2: %s", string2.c_str());

	string1 += string2;
	printf("\noperator =:");

	printf("\nstring 1: %s", string1.c_str());
	printf("\nlenght: %i", string1.lenght());
	if (string1 == "hello")
	{
		printf("\nAre equal: ");
	}
	if (string1 == string2){
		printf("Equal");
	}
	else{
		printf("Not equal");
	}*/
	mString::~mString()
	{
		printf("\nDestroyed");
		delete[]buffer;
	}
	//printf();
	
