//Right Triangle
#include <stdio.h>
//para incluir a biblioteca de matemática
#include <math.h>
int main(){
    float a;
    // o a e o b são float e não int como estávamos usando
    float b;
    printf("Valor de a: ");
    scanf("%f", &a);
    printf("Valor de b: ");
    scanf("%f", &b);
    printf("O valor da hypotenusa é: %0.3f\n", sqrt(a*a + b*b)); //sqrt() está na biblio de math
    return 0;
}