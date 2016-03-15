#ifndef Zork_Player
#define Zork_Player


#include "Rooms.h"
#include "Exits.h"


class Player{
	public:
		World* player;
		Room* posPlayer;
		Room *history;
public:
	void Look()const;
	void MovePlayer(char);
};


#endif