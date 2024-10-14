#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int answer = 50;
	int input;
	int attempts=0;
	
	do
	{
		printf("Guess a number: ");
		scanf("%d",&input);
		attempts++;
		
		if (input > answer)
		{
			printf("High!\n");
		}
		else if(input < answer)
			printf("Low!\n");
		
		else
		{
		printf(	"Congratulation! Trials: %d",attempts);
		}
	}
	while (input!=answer);
	
	return 0;
}
