//sine with taylor series

//headers
#include <stdio.h>
#include <math.h> //give access to the pow function // M_PI é o pí //fabs() //sin
#include <stdlib.h>

//prototypes
double sineTaylor(double x, int n, double* error);
double factorial(unsigned long int fac);
void show_for(double rad, int n);

int main(){

    int n;
    puts("Enter with the term to truncate the series: ");
    scanf("%d", &n); //%d é o specifier
    show_for(M_PI/4, n);
    show_for(M_PI/3, n);
    show_for(M_PI/2, n);
    show_for(0, n);
    return 0;
}

//declarations
double sineTaylor(double x, int n, double* error){
    double acc = 0.0;
    int i;
    for(i = 0; i <= n; i++){
        acc += ((i%2)? -1.0 : 1.0) * pow(x, 2.0*i + 1.0)/factorial(2.0*i + 1.0); // trocou o pow(-1, i) 
    }                                                                               //pelo tenary operator
    
    //nesse ponto do programa o valor de i é n + 1 por conta da condição do for, ou seja, temos o i para o erro

    *error = pow(fabs(x), 2.0*i + 1.0)/factorial(2.0*i + 1.0);

    return acc;
}   

double factorial(unsigned long int fac){
    double score = 1.0;
    for(unsigned long int i = 2; i <= fac; i++){
        score *= i;
    }
    return score;
}

void show_for(double rad, int n){
    double approx_error;
    printf("> For %lf radians, and truncated at %d:\n", rad, n);
    printf("Sine (math.h): %.15lf\n", sin(rad));
    printf("Sine approx. : %.15lf\n", sineTaylor(rad, n, &approx_error));
    printf("Approx error : %lg\n\n", approx_error);

}