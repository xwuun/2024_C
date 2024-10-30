#include <stdio.h>
int all_files;

extern void sub();

int main(void)
{
	sub();
	printf("%d\n",all_files);
	return 0;
}


/*static int sum = 1;
int main(void)
{
	int sum = 0;
	
	printf("sum = %d\n",sum);
	
	return 0;
}

static int all_files;

extern void sub();

int main(void)
{
	sub();
	printf("%d\n",all_files);
	return 0;
}*/
