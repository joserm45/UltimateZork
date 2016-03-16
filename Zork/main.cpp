#include <stdio.h>
#include <stdlib.h>
#include "World.h"


int main(){
	bool final = true;
	World* world = new World;
	world->CreateWorld();
	do{

		final = world->Command();
		
	} while ( final == true);
	
		
	delete world;
	system("pause");
	return 0;
}