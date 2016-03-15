#include <stdio.h>
#include <stdlib.h>
#include "Rooms.h"
#include "Exits.h"
#include "Player.h"
#include "World.h"
#include <string.h>

World::World(){

	rooms = new Room[11];
	player = new Player[1];
	exits = new Exit[44];
	player->player = this;
}

void World::CreateWorld(){

	strcpy(rooms[0].name, "Reception Room");
	strcpy(rooms[0].description, " Extended room with a big counter on the midle");
	strcpy(rooms[1].name, "WC's");
	strcpy(rooms[1].description, "Reception Room");
	strcpy(rooms[2].name, "Living Room");
	strcpy(rooms[2].description, "You can see a lot of papers on the floor.");
	strcpy(rooms[3].name, "Control room");
	strcpy(rooms[3].description, "Reception Room");
	strcpy(rooms[4].name, "Window building");
	strcpy(rooms[4].description, "Reception Room");
	strcpy(rooms[5].name, "Secret room");
	strcpy(rooms[5].description, "Reception Room");
	strcpy(rooms[6].name, "Cave");
	strcpy(rooms[6].description, "Reception Room");
	strcpy(rooms[7].name, "Final boss");
	strcpy(rooms[7].description, "Reception Room");
	strcpy(rooms[8].name, "Disco room");
	strcpy(rooms[8].description, "Reception Room");
	strcpy(rooms[9].name, "Bunker");
	strcpy(rooms[9].description, "Reception Room");
	strcpy(rooms[10].name, "Terrace");
	strcpy(rooms[10].description, "Reception Room");

	

	player->pos = &rooms[0];

	exits[0].source = &rooms[0];
	exits[0].destiny = &rooms[1];
	exits[0].direction = East;
	strcpy_s(exits[0].name, "WC's");
	strcpy_s(exits[0].description, "ddddddd");


	exits[1].source = &rooms[0];
	exits[1].destiny = &rooms[2];
	exits[1].direction = West;
	strcpy_s(exits[1].name, "Living room");
	strcpy_s(exits[1].description, "kk");


	exits[19].source = &rooms[1];
	exits[19].destiny = &rooms[3];
	exits[19].direction = East;
	strcpy_s(exits[19].name, "Control Room");
	strcpy_s(exits[19].description, "pp");


	exits[2].source = &rooms[1];
	exits[2].destiny = &rooms[0];
	exits[2].direction = West;
	strcpy_s(exits[2].name, "Reception room");
	strcpy_s(exits[2].description, "fddd");


	exits[3].source = &rooms[3];
	exits[3].destiny = &rooms[1];
	exits[3].direction = South;
	strcpy_s(exits[3].name, "WC's");
	strcpy_s(exits[3].description, "jjjj");


	exits[4].source = &rooms[3];
	exits[4].destiny = &rooms[4];
	exits[4].direction = East;
	strcpy_s(exits[4].name, "Hotel");
	strcpy_s(exits[4].description, "gg");

	exits[5].source = &rooms[3];
	exits[5].destiny = &rooms[5];
	exits[5].direction = North;
	strcpy_s(exits[5].name, "Secret room");
	strcpy_s(exits[5].description, "ddfs");

	exits[6].source = &rooms[4];
	exits[6].destiny = &rooms[3];
	exits[6].direction = West;
	strcpy_s(exits[6].name, "Control room");
	strcpy_s(exits[6].description, "ddfs");


	exits[7].source = &rooms[5];
	exits[7].destiny = &rooms[3];
	exits[7].direction = East;
	strcpy_s(exits[7].name, "Control room");
	strcpy_s(exits[7].description, "yeee");


	exits[8].source = &rooms[5];
	exits[8].destiny = &rooms[6];
	exits[8].direction = South;
	strcpy_s(exits[8].name, "Cave");
	strcpy_s(exits[8].description, "ddfs");

	exits[9].source = &rooms[5];
	exits[9].destiny = &rooms[8];
	exits[9].direction = West;
	strcpy_s(exits[9].name, "Disco room");
	strcpy_s(exits[9].description, "ddfs");

	exits[10].source = &rooms[6];
	exits[10].destiny = &rooms[5];
	exits[10].direction = North;
	strcpy_s(exits[10].name, "Secret room");
	strcpy_s(exits[10].description, "ddfs");

	exits[11].source = &rooms[6];
	exits[11].destiny = &rooms[7];
	exits[11].direction = South;
	strcpy_s(exits[11].name, "Forest");
	strcpy_s(exits[11].description, "ddfs");

	exits[20].source = &rooms[7];
	exits[20].destiny = &rooms[6];
	exits[20].direction = North;
	strcpy_s(exits[20].name, "Cave");
	strcpy_s(exits[20].description, "ddfs");

	exits[12].source = &rooms[8];
	exits[12].destiny = &rooms[5];
	exits[12].direction = East;
	strcpy_s(exits[12].name, "Secret room");
	strcpy_s(exits[12].description, "ddfs");

	exits[13].source = &rooms[8];
	exits[13].destiny = &rooms[9];
	exits[13].direction = South;
	strcpy_s(exits[13].name, "Bunker");
	strcpy_s(exits[13].description, "ddfs");


	exits[14].source = &rooms[8];
	exits[14].destiny = &rooms[2];
	exits[14].direction = West;
	strcpy_s(exits[14].name, "Living room");
	strcpy_s(exits[14].description, "ddfs");


	exits[15].source = &rooms[9];
	exits[15].destiny = &rooms[8];
	exits[15].direction = North;
	strcpy_s(exits[15].name, "Disco room");
	strcpy_s(exits[15].description, "ddfs");


	exits[16].source = &rooms[2];
	exits[16].destiny = &rooms[0];
	exits[16].direction = East;
	strcpy_s(exits[16].name, "Reception room");
	strcpy_s(exits[16].description, "ddfs");


	exits[21].source = &rooms[2];
	exits[21].destiny = &rooms[8];
	exits[21].direction = North;
	strcpy_s(exits[21].name, "Disco room");
	strcpy_s(exits[21].description, "ddfs");


	exits[17].source = &rooms[2];
	exits[17].destiny = &rooms[10];
	exits[17].direction = West;
	strcpy_s(exits[17].name, "Terrace");
	strcpy_s(exits[17].description, "ddfs");


	exits[18].source = &rooms[10];
	exits[18].destiny = &rooms[2];
	exits[18].direction = South;
	strcpy_s(exits[18].name, "Living room");
	strcpy_s(exits[18].description, "ddfs");

	//21 Exits


	/*Reception Room -> (NULL, NULL, WC, Living room);
	WC->setExits(NULL, NULL, Control Room, Reception room);
	Control room->setExits(Secret room, WC, Dinning room Exit);
	Dinning room->setExits(NULL, NULL, NULL, NULL);
	Secret room->setExits(NULL, Cave, Control room, Disco room);
	Cave->setExits(Secret room, Final boss, NULL, NULL);
	Final boss->setExits(Cave, NULL, NULL, NULL);
	Disco room->setExits(NULL, Bunker, Secret room, Living room);
	Bunker->setExits(Disco room, NULL, NULL, NULL);
	Living room->setExits(Disco room, NULL, Reception room, Terrace);
	Terrace->setExits(NULL, Living Room, NULL, NULL);*/
}
World::~World(){

	delete [] rooms;
	delete [] player;
	delete [] exits;
}