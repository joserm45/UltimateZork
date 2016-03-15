#ifndef Zork_World
#define Zork_World


class World {
private:
	Room* rooms = nullptr;
	Exit* exits;
public:
	void CreateWorld();

	World();
	
	~World();
	
};

#endif

