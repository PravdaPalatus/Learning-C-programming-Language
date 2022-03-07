//distance of
#include <stdio.h>
#include <math.h>


double distanceOf(double, double, double, double);
//area of rectangle
double areaOfRect(double, double, double, double);


int main(){
    
    
    printf("Distância = %lf\n", distanceOf(0, 3, 5, 0));
    
    printf("A área do retángulo é: %lf\n", areaOfRect(0, 3, 5, 0));

    printf("A área do retángulo é: %lf\n", areaOfRect(3, 2, 9, 6));
    
    
    return 0;

}


double distanceOf(double x1, double y1, double x2, double y2){
    double dist, h, w;
    h = y2 - y1;
    w = x2 - x1;
    dist = sqrt(pow(h, 2)+ pow(w, 2));
    return dist;
}

//area of rectangle

double areaOfRect(double tlx, double tly, double brx, double bry){
    
    double w = distanceOf(tlx, tly, brx, tly);
    double h = distanceOf(brx, bry, brx, tly);
    double area = w * h;

    return area;  

}
