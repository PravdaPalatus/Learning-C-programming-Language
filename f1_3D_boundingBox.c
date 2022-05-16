//code to find two points that defines the 3D bounding box
#include <stdio.h>

typedef struct Point3D{
    float x, y, z;
} point3D;

void scanPoints3D(point3D *p, int size);
void printPoints3D(point3D p[], int size);
void print3DPoint(point3D p);
point3D minBounding3DPoint(point3D p[], int size);
point3D maxBounding3DPoint(point3D p[], int size);

int main(){
    int num;
    puts("Enter the number of points to be considered: ");
    scanf("%d", &num);

    point3D arr[num];
    scanPoints3D(arr, num);
    puts("We have the following points: ");
    printPoints3D(arr, num);

    point3D min = minBounding3DPoint(arr, num);
    point3D max = maxBounding3DPoint(arr, num);
    puts("The two points that defines the 3D bounding box are: ");
    print3DPoint(min);
    print3DPoint(max);
    printf("\n");
    return 0;
}

void scanPoints3D(point3D *p, int size){
    for(int i = 0; i < size; i++){
        printf("Enter coordinate of the point %d: ", i);
        scanf("%f %f %f", &(p[i].x), &(p[i].y), &(p[i].z));
    }
}

void printPoints3D(point3D p[], int size){
    for(int i = 0; i < size; i++){
        printf("(%.2f, %.2f, %.2f) ", p[i].x, p[i].y, p[i].z);
    }
    printf("\n");
}

void print3DPoint(point3D p){
    printf("(%g, %g, %g) ", p.x, p.y, p.z);
}

point3D minBounding3DPoint(point3D p[], int size){
    point3D minp = {p[0].x, p[0].y, p[0].z};
    for(int i = 1; i < size; i++){
        if(p[i].x < minp.x) minp.x = p[i].x;
        if(p[i].y < minp.y) minp.y = p[i].y;
        if(p[i].z < minp.z) minp.z = p[i].z;
    }
    return minp;
}

point3D maxBounding3DPoint(point3D p[], int size){
    point3D maxp = {p[0].x, p[0].y, p[0].z};
    for(int i = 1; i < size; i++){
        if(p[i].x > maxp.x) maxp.x = p[i].x;
        if(p[i].y > maxp.y) maxp.y = p[i].y;
        if(p[i].z > maxp.z) maxp.z = p[i].z;
    }
    return maxp;
}
