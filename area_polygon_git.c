//code to calculate the area of a polygon
#include <stdio.h>
#include <math.h>

typedef struct Point_{
    float x;
    float y;
} point;


void scanPoint(point *p);
void initializePolygon(point *p, int size);
void printPoint(point p);
float areaPolygon(point *p, int size);

int main(){
    int num;
    puts("Enter the number of points that constitute the polygon.");
    scanf("%d", &num);
    point poly[num];
    initializePolygon(poly, num);
    puts("We have the following points:");
    for(int i = 0; i < num; i++){
        printPoint(poly[i]);
    }
    puts("\n");
    printf("The area of the polygon is: %g", areaPolygon(poly, num));

    puts("\n");
    return 0;
}

void scanPoint(point *p){
    scanf("%f %f", &(p->x), &(p->y));
}

void initializePolygon(point *p, int size){
    for(int i = 0; i < size; i++){
        printf("Enter the coordinates of the point %d:", i);
        scanPoint(&p[i]);
    }
}

void printPoint(point p){
    printf("(%g, %g)", p.x, p.y);
}

float areaPolygon(point *p, int size){
    float area = 0.0;
    float aux = 0.0;
    for(int i = 0; i < size - 1; i++){
        aux += (p[i].x * p[i+1].y) - (p[i+1].x * p[i].y);
    }
    area = fabs(aux)/2;
    return area;
}