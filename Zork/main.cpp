#include <stdio.h>
#include <stdlib.h>
#include "World.h"



int main(){
	
	World* world = new World;
	world->CreateWorld();
	bool final = true;
	printf("Welcome to my Zork!!\n%s \n ", world->rooms[0].name);
	printf("%s \n ", world->rooms[0].description);
	printf(" Write a comand to move(n/s/e/w):");
	
	do{
		
		final = world->Command();
	}

	while (final == true);
	
	
	
		
	delete world;
	system("pause");
	return 0;
}