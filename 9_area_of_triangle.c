//area of triangle

//header
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//prototypes
double distanceOf(double, double, double, double);
double areaOfTriangle(double, double, double, double, double, double);


int main(){

    double x1, y1, x2, y2, x3, y3; 
                                    
    printf("Digite as coordenadas x1 y1 x2 y2 x3 y3: ");
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    printf("%lf, %lf, %lf\n", distanceOf(x1, y1, x2, y2), distanceOf(x2, y2, x3, y3), distanceOf(x1, y1, x3, y3));
    printf("The area of triangle is: %lf\n", areaOfTriangle(x1, y1, x2, y2, x3, y3));

    return 0;
}

//definitions

double distanceOf(double x1, double y1, double x2, double y2){
    double dist, h, w;
    h = y2 - y1;
    w = x2 - x1;
    dist = sqrt(pow(h, 2)+ pow(w, 2));  //double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); sendo d = dist
    return dist;
}

double areaOfTriangle(double x1, double y1, double x2, double y2, double x3, double y3){
    double a, b, c;
    a = distanceOf(x1, y1, x2, y2);
    b = distanceOf(x2, y2, x3, y3);
    c = distanceOf(x1, y1, x3, y3);
    //the condition for the triangular structure to exist
    if(a >= b + c || b >= a + c || c >= b + a){
        printf("This is not a triangle!\n");
        exit(1);
    }
    else{
        double peri, area; //conta da area
        peri = (a + b +c)/2;
        area = sqrt(peri*(peri - a)*(peri - b)*(peri - c));
        return area;
    }
    return 0;
}
