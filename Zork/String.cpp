#include "String.h"
#include <stdlib.h>


#include "Vector.h"

mString::mString()
{
	buffer = new char[10];
	capacity = 9;
}

mString::mString(char* str)
	{

		

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
void mString::operator=(const char* other)
{
	int	new_lenght = strlen(other);
	if (capacity < new_lenght)
	{
		capacity = new_lenght;
		delete[]buffer;
		buffer = new char[capacity + 1];
	}

	strcpy_s(buffer,capacity+1,other);
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

bool mString::operator == (const char* other) const
{

	return strcmp(buffer, other) == 0;
}
	
void mString::tokenize( Vector <mString>& vec)
{
	
	int size = strlen(buffer) + 1;
	char* dup = new char[size];
	char* safe;
	strcpy_s(dup, size, buffer);
	char* token = strtok_s(dup, " ", &safe);
	while (token != NULL)
	{
		vec.push_back(token);
		token = strtok_s(NULL, " ", &safe);
	}
	delete[]dup;

}


	mString::~mString()
	{
	
		delete[]buffer;
	}
	//printf();
	
