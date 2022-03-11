//area Right Triangle

#include <stdio.h>
#include <math.h>

float distance_two_points(float x1, float y1, float x2, float y2);
float area_of_triangle(float ax, float ay, float bx, float by, float cx, float cy);

int main(){
    float ax, ay, bx, by, cx, cy;
    float area;
    puts("***Calculus of the area of a right triangle***\n");
    printf("Enter de coordinates of A(x,y): ");
    scanf("%f %f", &ax, &ay);
    printf("Enter de coordinates of B(x,y): ");
    scanf("%f %f", &bx, &by);
    printf("I got for A(%.2f, %.2f) and B(%.2f, %.2f).\n", ax, ay, bx, by);
    cx = bx;
    cy = ay;
    area = area_of_triangle(ax, ay, bx, by, cx, cy);
    printf("The area of triangle is: %.2f\n", area);
    return 0;
}

float distance_two_points(float x1, float y1, float x2, float y2){
    float dist;
    dist = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return (float) dist;
}

float area_of_triangle(float ax, float ay, float bx, float by, float cx, float cy){
    float area;
    float b = distance_two_points(bx, by, cx, cy);
    float c = distance_two_points(ax, ay, cx, cy);
    area = (b * c)/2;
    return area;
}