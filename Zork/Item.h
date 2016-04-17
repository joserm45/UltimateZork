#ifndef Zork_Item
#define Zork_Item

#include "Entity.h"
#include "Vector.h"





enum item_type{sword, gun, chest};

class Item : public Entity{

public:
	
	Vector <Item*> items;
	
	void Look()const;

	Item();
	Item(const char* name, const char* desc);
	~Item();
};

#endif