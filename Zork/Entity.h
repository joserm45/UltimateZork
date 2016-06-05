#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <stdio.h>

#include "String.h"

enum dir{ north, south, east, west };
enum entity_type { PLAYER, ZOMBIE, NPC, ROOM, EXIT, ITEM };
class Entity{

public:
	entity_type type;
    mString name;
	mString description;
//	Vector <Item*> items;

public:

	Entity();
	Entity(const char* name, const char* desc);
	~Entity();
//	Entity(const char*name, const char* description);
	//my_name(name), my_destiny(description);

};
#endif
