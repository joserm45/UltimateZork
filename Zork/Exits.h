#ifndef Zork_Exit
#define Zork_Exit

enum dir{ North, South, East, West };

class Exit{
	Exit* exits;
	char name[30];
	char description[300];
	Room* source;
	Room* destiny;
	bool open;

};

#endif