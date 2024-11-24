#include <stdio.h>

/*
void main(void) 
{
    FILE *fp = NULL;
    char c;
    fp = fopen("sample.txt", "r");
    if (fp == NULL)
        printf("파일을 못열음\n");

    while ((c = fgetc(fp)) != EOF) 
        putchar(c); 

    fclose(fp);
}
*/
void main(void) 
{
	FILE * fp = NULL;
	char word[100];

	fp = fopen("sample.txt","r");
	if(fp == NULL)
		printf("Error opening file.\n");

	while(fscanf(fp,"%s",word) != EOF)
	{
		printf("%s\n",word);
	}

	fclose(fp);
}


