#include <stdlib.h>
#include <stdio.h>

int main() {

	int countX = 0, countY = 0;
	char pos;
	while (pos != 'q') {
		printf("You are on the dinning room \n ");
		printf("Which direction you want to go (n/s/e/w or q)? ");
		scanf_s("%c", &pos);
		fflush(stdin);

		switch (pos) {

		case 'n':
			countY++;
			break;

		case 's':
			countY--;
			break;

		case 'e':
			countX++;
			break;

		case 'w':
			countX--;
			break;
		default:
			return 0;
			break;
		}

		if (countX == 0 && countY == 0) {
			printf("You are in the dinning room.\n");
		}
		if (countX == 0 && countY == 1) {
			printf("You are in the kitchen.\n");
		}
		if (countX == 1 && countY == 1) {
			printf("You are in the pantry.\n");
		}
		if (countX == 1 && countY == 0) {
			printf("You are in the bathroom.\n");
		}
		if (countX == 0 && countY == -1) {
			printf("You are in the bedroom.\n");
		}
		else {
			printf("You can't pass, there is a wall near");
		}
	}
	return 0;
	system("pause");

}