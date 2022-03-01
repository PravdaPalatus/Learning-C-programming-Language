//verify sides of a triangle
#include <stdio.h>
#include <math.h>
int main() {
    float a; //pergunta os valores dos lados
    float b;
    float c;
    printf("Valor do lado 1: \n");
    scanf("%f", &a);
    printf("Valor do lado 2: \n");
    scanf("%f", &b);
    printf("Valor do lado 3: \n");
    scanf("%f", &c);
    float peri;
    peri = (a + b + c);
    if( a + b > c && a + c > b && c + b > a) {
        float s;
        s = peri/2;
        float area;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
        printf("O Perímetro é %0.1f e a área é %0.1f\n", peri, area);
    } else {
        printf("Invalid side lengths for a triangle\n");
    }  
    //calcula o perímetro
    printf("Temos os lados %0.1f %0.1f %0.2f e o perímetro %0.1f\n", a, b, c, peri);
    return 0;
}