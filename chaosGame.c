#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

#define gotoxy(row, col) printf("\033[%d;%dH", (row), (col))

#define printStar(row, col)	gotoxy(row, col);\
						printf("*");

#define OFFSET 	(5)
#define rowA	(0 + OFFSET)
#define colA	(50)
#define rowB	(50 + OFFSET)
#define colB	(1)
#define rowC	(50 + OFFSET)
#define colC	(100)

int generateRandomNumber(int min, int max)
{
	if (min > max)
	{
		min ^= max;
		max ^= min;
		min ^= max;
	}

	return (rand() % (1 + max - min)) + min;
}

int main(int argc, char *argv[])
{
	char randomNumber = 0;
	char row, col;

	//row = (rowB - rowA)/2 + OFFSET;
	//col = (colA - colB)/2;
	row = generateRandomNumber(20, 50);
	col = generateRandomNumber(30, 60);

	printStar(rowA, colA);
	printStar(rowB, colB);
	printStar(rowC, colC);
	printStar(row, col);

	srand(time(NULL));
	for(int i = 0; i<100000; i++)
	{
		randomNumber = generateRandomNumber(1, 6);
		switch(randomNumber)
		{
			case 1:
			case 2:
				row = (row - ((row - rowA)/2));
				if(colA > col)
					col = col + ((colA - col)/2);
				else
					col = col - ((col - colA)/2);
				break;
			case 3:
			case 4:
				row = row + (rowB - row)/2;
				col = col - (col - colB)/2;
				break;
			case 5:
			case 6:
				row = row + (rowC - row)/2;
				col = col + (colC - col)/2;
				break;
			default:
				break;
		}
		printStar(row, col);
		//printf("n:%d::r:%d::c:%d.\n", randomNumber, row, col);
	}

	printStar(rowC, colC);
	printf("\n");
	return 0;
}