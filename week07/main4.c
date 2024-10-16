#include <stdio.h>
#include <stdlib.h>




int factorial(int n)
{
	int res=1;
	int i;
	for(i=1 ; i<=n ;i++)
		res=res*i;
	return res;
}

int combination(int n, int r)
{
	return (factorial(n)/(factorial(n-r)*factorial(r)));
}

int get_integer()
{
	int value;
	
	printf("Enter the value: ");
	scanf("%d",&value);
	return value;
}

int main(void)
{
	int n,r,comb;
	
	n=get_integer();
	r=get_integer();
	
	comb = combination(n,r);
	
	printf("The result of C(%d, %d) is %d",n,r,comb);
	
	return 0;
}
