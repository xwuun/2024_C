#include <stdio.h>

int main(void) 
{
	FILE *fp; 
    char word[100];
	int i=0;
	fp = fopen("sample.txt","w");

	for (i=0; i<3; i++) 
	{
        printf("input a word: ");
        scanf("%s", word); 
        fprintf(fp, "%s\n", word);
	}
	
	fclose(fp);
	
	return 0;
}
