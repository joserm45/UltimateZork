#include <stdio.h>


#include "Player.h"
#include "World.h"


void Player::Look()const{
	printf("%s \n %s", posPlayer->name.c_str(), posPlayer->description.c_str());

}




void Player::MovePlayer(World* world, dir adress){

	int i = 0;
	bool exitFound;

	for (i = 0; i < 21; i++)
	{
		if (world->exits[i].source == posPlayer && world->exits[i].direction == adress)
		{
			exitFound = true;

			if (world->exits[i].openDoor == true)
			{
				printf("%s \n %s", world->exits[i].destiny->name.c_str(), world->exits[i].destiny->description.c_str());
				posPlayer = world->exits[i].destiny;
			}
			else
				printf("The door is closed...\n");
			break;
		}
		
		exitFound = false;
	}
	if (exitFound == false)
		printf("You can't go there...\n");
}


		void Player::LookCommand(World* world, dir adress)
		{
			int i = 0;
			bool look_dir=false;
			for (i = 0; i < 21; i++){
				if (world->exits[i].source == posPlayer && world->exits[i].direction == adress)
				{

					look_dir = true;


					printf("%s \n %s \n ", world->exits[i].name.c_str(), world->exits[i].description.c_str());

				}
				
				}
			if (look_dir=false)
			printf("There is a wall there.\n");
		}
		
		
		

		void Player::OpenDoor(World* world, dir adress){
			int i = 0;
			for (i = 0; i < 21; i++){
				if (world->exits[i].source == posPlayer && world->exits[i].direction == adress){
					if (world->exits[i].openDoor==false){
						world->exits[i].openDoor = true;
						printf("You opened the door.\n");
					}
					else{
						printf("The door is already opened.\n");
					}
				}
			}
		}

		void Player::CloseDoor(World* world, dir adress){
			int i = 0;
			for (i = 0; i < 21; i++){
				if (world->exits[i].source == posPlayer && world->exits[i].direction == adress){
					if (world->exits[i].openDoor == true){
						world->exits[i].openDoor = false;
						printf("The door is closed.\n");

					}
					else{
						printf("The door is already closed.\n");
					}
				}
			}
		}
		void Player::Help()const{
			printf("You can move around the room with the keyboard keys (n/s/w/e) or with the words north, south, east , west. Also you can write go and the words north,south,east,west. If you write look you can see our room, but if you write look north you will see the north room.\n To finish the commands you can close and open the doors with the same method of the command look, and quit the game pressing the 'q'.\n ");
		}