#include <stdio.h>
#include <stdlib.h>
#include "World.h"
#include "Rooms.h"
#include "Exits.h"
#include "Entity.h"
#include "Player.h"
#include <time.h>


int main(){
	
	World* world = new World;
	world->CreateWorld();
	bool final = true;

	printf("Welcome to my Zork!!\n%s \n ", world->entity_list[0]->name);
	printf("%s \n ", world->entity_list[0]->description);
	printf(" Write a comand to move(n/s/e/w):\n");
	srand(time(NULL));
	do
	{		
		final = world->Update();
	}
	while (final == true);
	
	
	
		
	delete world;
	system("pause");
	return 0;
}