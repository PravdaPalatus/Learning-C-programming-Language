//Right Triangle
#include <stdio.h>
#include <math.h>
int main(){
    float a;
    float b;
    printf("Valor de a: ");
    scanf("%f", &a);
    printf("Valor de b: ");
    scanf("%f", &b);
    printf("O valor da hypotenusa é: %0.3f\n", sqrt(a*a + b*b));
    return 0;
}
