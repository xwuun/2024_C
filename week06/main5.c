#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int x1,x2;
	char cal;
	
	printf("Enter the calculation: ");
	scanf("%d %c %d",&x1, &cal, &x2);
	
	if(cal == '+')
	{
		printf("= %d",x1+x2);
	}
	else if(cal == '-')
	{
		printf("= %d",x1-x2);
	}
	else if(cal == '*')
	{
		printf("= %d",x1*x2);
	}
	else if(cal == '/')
	{
		printf("= %d",x1/x2);
	}

	return 0;

}
