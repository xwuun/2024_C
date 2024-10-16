
#include <stdio.h>
#include <stdlib.h>


int sumTwo(int a,int b)
{
	return a+b;
}

int square (int n)
{
	return n*n;
}

int get_max (int x,int y)
{
	if (x>y) return x;
	else return y;
}


int main() 
{
	
	int num1,num2;
	
	printf("Enter the integers: ");
	scanf("%d %d",&num1,&num2);
	
	printf("Result - Sum: %d, Square: %d, Max: %d",sumTwo(num1,num2),square(num1),get_max(num1,num2));
	
	
	return 0;
}
