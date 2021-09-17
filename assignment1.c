#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
gcc project1.c -o assignment1.exe
./assignment1.exe
*/
void store_print(int *a); 
char *theGame(int ChosenNumber)
{
	int result = 0;
	char *string = malloc(7);
	int upper = 100;
	int lower = 0;
	int middle;

	printf("%d :", ChosenNumber);

	while (1)
	{

		middle = (upper + lower) / 2;
		if (upper - 1 == lower)
		{
			break;
		}
		if (ChosenNumber > middle)
		{
			string[result] = '1';
			lower = middle;
		}
		else //if (ChosenNumber <= middle)
		{
			string[result] = '0';
			upper = middle;
		}
		result++;
	}
	
	printf("%s", string);
	
	
	printf("\n");
	return string;
}
void playGames()
{
	srand(time(NULL)); //resetting the random numbers.
	int total1 = 0; //counting number of 6 questions are asked
	int total2 = 0; // counting number of 7 questions are asked
	double average = 0; // average of 6,7 questions are asked	
	int arr[101]={};
	int i;
	for (i = 0; i < 1000; i++)
	{
		
		int num; // random number
		int upper = 100;
		int lower = 1;
		int middle;
		int result = 0;
		num = rand() % 100 + 1;
		
		arr[num]++;
		
		while (1)
		{
			middle = (upper + lower) / 2;
			if (upper - 1 == lower)
			{
				break;
			}
			if (num > middle)
			{
				lower = middle;
			}
			else //if (ChosenNumber <= middle)
			{
				upper = middle;
			}
			result++;
		}
	if (result == 6)
	{
		total1++;
	}
	else if (result == 7)
	{
		total2++;
	}

	}
	store_print(arr);

	printf("number of 6 questions are asked: %d\n",total1);
	printf("number of 7 questions are asked: %d\n",total2);
	average = (double)((total1 * 6) + (total2 * 7)) / 1000;
	printf("Average numbers of questions asked: %f",average);
}
void store_print(int *a) 
{
	int i;
	for (i = 1; i < 101; i++)
	{
		printf("%d : " ,i);
			int j;
			for(j=0; j<a[i]; j++)
				{
					printf("*");
				}
				printf("\n");
	}
}



int main()
{
	int i;
	for (i = 1; i <= 100; i++)
	{
		theGame(i);
	}
	
	playGames();
	
	
	
	return 0;
}
