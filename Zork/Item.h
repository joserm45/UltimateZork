#ifndef Zork_Item
#define Zork_Item

#include "Entity.h"
#include "Vector.h"





enum item_type{sword, gun, chest};

class Item : public Entity{

public:
	
	Vector <Item*> items;
	int atackweapon = 4;
	int price = 0;
	void Look()const;

	Item();
	Item(const char* name, const char* desc,int price);
	~Item();
};

#endif