#include <stdio.h>

/*
struct point {
    int x; 
    int y; 
};


int getArea(struct point p1, struct point p2) {
    int width = p2.x - p1.x;  
    int height = p2.y - p1.y; 

    if (width < 0) width = -width;
    if (height < 0) height = -height;

    return width * height;
}

int main() {
    struct point p1, p2; 
    int area;       

    printf("Input the coordinate p1 (x y): ");
    scanf("%d %d", &p1.x, &p1.y);


    printf("Input the coordinate p2 (x y): ");
    scanf("%d %d", &p2.x, &p2.y);


    area = getArea(p1, p2);


    printf("Area: %d\n", area);

    return 0;
}
*/


struct point
{
    int x;
    int y; 
};

int getArea(struct point *pPtr1, struct point *pPtr2) {
    int width = pPtr2->x - pPtr1->x;
    int height = pPtr2->y - pPtr1->y; 

    if (width < 0) width = -width;
    if (height < 0) height = -height;

    return width * height; 
}

int main() {
    struct point p1, p2;     
    struct point *pPtr1 = &p1; 
    struct point *pPtr2 = &p2; 
    int area; 


    printf("Input the coordinate p1 (x y): ");
    scanf("%d %d", &p1.x, &p1.y);

    printf("Input the coordinate p2 (x y): ");
    scanf("%d %d", &p2.x, &p2.y);

    area = getArea(pPtr1, pPtr2);

    printf("Area: %d\n", area);

    return 0;
}

