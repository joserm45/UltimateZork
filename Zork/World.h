#ifndef Zork_World
#define Zork_World


class World {
private:
	Room* rooms = nullptr;
public:
	void CreateWorld();

	World();
	
	~World();
	
};

#endif

