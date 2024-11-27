#include <stdio.h>
#define STUDENTNUM 4

struct student
{
	int ID;
	int score;
};

void main(void)
{
	struct student s[STUDENTNUM];
	
	int highest_score = 0;
	int highest_ID = 0;
	int i;
	int sum = 0;
	
	for (i= 0; i < STUDENTNUM; i++) 
	{
        printf("Input the ID: ");
        scanf("%d", &s[i].ID);
        printf("Input the score: ");
        scanf("%d", &s[i].score);
    
        sum += s[i].score;
        
    if (s[i].score > highest_score) 
		{
        highest_score = s[i].score;
        highest_ID = i;    
		}
	}
	
	float average = sum / (float)STUDENTNUM;
	
	printf("The average of the score: %f\n",average);
	printf("The highest score - ID: %d, score: %d\n", s[highest_ID].ID, s[highest_ID].score);

}
