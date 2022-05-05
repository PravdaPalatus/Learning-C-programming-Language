//code to find the geometric center of a polygon
#include <stdio.h>
#define NMAX 100

typedef struct Point_{
    float x;
    float y;
} point;

void scanPoint(point *p);
void initializeArrPoints(point *arr, int size);
void printPoint(point p);
void geometricCenter(point *arr, point *geoCenter, int size);

int main(){
    int num;
    puts("Enter the number of points that constitute the polygon.");
    scanf("%d", &num);
    point arr[num];

    initializeArrPoints(arr, num);

    puts("We have the folowwing points: ");

    for(int i = 0; i < num; i++){
        printPoint(arr[i]);
    }

    printf("\n");

    point geoCenter;
    geometricCenter(arr, &geoCenter, num);
    printf("The geometric center of the polygon is:\n");
    printPoint(geoCenter);
    printf("\n");

    return 0;
}

void scanPoint(point *p){
    scanf("%f %f", &(p->x), &(p->y));
}

void initializeArrPoints(point *arr, int size){
    for(int i = 0; i < size; i++){
        printf("Enter the coordinates of the point %d: ", i);
        scanPoint(&arr[i]);
    }
}

void printPoint(point p){
    printf("(%g, %g)", p.x, p.y);
}

void geometricCenter(point *arr, point *geoCenter, int size){
    float sumX = 0.0;
    float sumY = 0.0;
    for(int i = 0; i < size; i++){
        sumX += arr[i].x;
        sumY += arr[i].y;
    }
    geoCenter->x = sumX/size; 
    geoCenter->y =sumY/size;
}