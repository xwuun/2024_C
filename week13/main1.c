#include <stdio.h>
#include <string.h>

struct student
{
	int id;
	char name[10];
	double grade;
	
};

int main(void)
{
	struct student s1 = {2413102,"Noonsong",4.5};
	
 	s1.id = 24;
    strcpy(s1.name, "Eunju");
    s1.grade = 4.3;
    
    printf("ID: %d\n", s1.id);
    printf("Name: %s\n", s1.name);
    printf("Grade: %.2f\n", s1.grade);
}
