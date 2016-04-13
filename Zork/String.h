#ifndef _STRING_H_

#define _STRING_H_
#include <string.h>
#include <stdio.h>


class mString{

private:
	char* buffer = nullptr;
	unsigned int capacity;

public:

	mString();

	mString(char *str);//constructor


	mString(const mString& str);//copy constructor
	

	const char* c_str()const;


	bool empty()const;
	

	unsigned int lenght() const;
	
	//Operators
	void operator = (const  mString& other);
	
	void operator = (const char* other);

	void operator +=(const  mString& other);

	bool operator == (const mString& other) const;
	
	bool operator == (const char* other) const;

	~mString();

};
#endif