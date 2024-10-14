#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int number;
	
	printf("Enter an integer: ");
	scanf("%d",&number);
	
	if(number>0)
	{
		printf("This is positive number.");
	}
	else if(number<0)
	{
		printf("THis is negative number.");
	}
	else
	{
		printf("This is 0.");
	}
	
	return 0;
}
