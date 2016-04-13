#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <stdio.h>

#include "String.h"

class Entity{

public:

    mString name;
	mString description;

public:

	Entity();
	~Entity();
//	Entity(const char*name, const char* description);
	//my_name(name), my_destiny(description);

};
#endif
