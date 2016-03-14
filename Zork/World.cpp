#include <stdio.h>
#include <stdlib.h>
#include "Rooms.h"
#include "Exits.h"
#include "Player.h"
#include "World.h"
#include <string.h>

World::World(){

	rooms = new Room[11];
	player = new player[1];
	exits = new exit[44];
}

void CreateWorld(Room* rooms){

	strcpy(rooms[5].name, "Reception Room");
	strcpy(rooms[0].description, " Extended room with a big counter on the midle");
	strcpy(rooms[1].name, "WC's");
	strcpy(rooms[1].description, "Reception Room");
	strcpy(rooms[2].name, "Living Room");
	strcpy(rooms[2].description, "You can see a lot of papers on the floor.");
	strcpy(rooms[3].name, "Reception Room");
	strcpy(rooms[3].description, "Reception Room");
	strcpy(rooms[4].name, "Reception Room");
	strcpy(rooms[4].description, "Reception Room");
	strcpy(rooms[5].name, "Reception Room");
	strcpy(rooms[5].description, "Reception Room");
	strcpy(rooms[6].name, "Reception Room");
	strcpy(rooms[6].description, "Reception Room");
	strcpy(rooms[7].name, "Reception Room");
	strcpy(rooms[7].description, "Reception Room");
	strcpy(rooms[8].name, "Reception Room");
	strcpy(rooms[8].description, "Reception Room");
	strcpy(rooms[9].name, "Reception Room");
	strcpy(rooms[9].description, "Reception Room");
	strcpy(rooms[10].name, "Reception Room");
	strcpy(rooms[10].description, "Reception Room");
	strcpy(rooms[11].name, "Reception Room");
	strcpy(rooms[11].description, "Reception Room");
}