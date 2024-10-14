#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int number;
	
	printf("Enter an integer: ");
	scanf("%d",&number);
	
	if(number<0)
	{
		printf("%d",-number);
	}
	else
	{
		printf("%d",number);
	}
	return 0;

}
