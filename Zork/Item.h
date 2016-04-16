#ifndef Zork_Item
#define Zork_Item

#include "Entity.h"
#include "Rooms.h"




enum items{sword, gun, bag};

class Item : public Entity{

public:

	items item;
	void Look()const;

	Item();
	Item(const char* name, const char* desc);
	~Item();
};

#endif