#include <stdio.h>
#include <stdlib.h>
#include "Rooms.h"
#include "Exits.h"
#include "Player.h"
#include "World.h"

void Player::MovePlayer(char word){

	switch (word){

	case 'n':

		if (world->exits[i].source == posPlayer && world->exits[i].source == direction){

		}
			break;

	}

}
void Player ::Look()const{
	printf("%s\n", history->description);

}