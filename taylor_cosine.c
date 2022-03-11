// truncated taylor series for cosine(xpi)

#include <stdio.h>
#include <math.h>

int factorial(int num);
double taylor_cosine(int n, double x);

int main(){
    int n;
    double x;

    printf("Enter a integer number: \n");
    scanf("%d", &n);
    printf("Enter a double number: \n");
    scanf("%lf", &x);

    printf("%lf\n", taylor_cosine(n, x));


    return 0;
}

int factorial(int num){
    int fac = 1;
    for(int i = 2; i <= num; i++){
        fac *= i;
    }
    return fac;
}


double taylor_cosine(int n, double x){
    double cos, res;
    for(int i = 0; i <= n; i++){
       cos = pow(-1, i) * (pow(x * M_PI, 2 * i)/factorial(2 * i));
       res += cos;
    }
    return res;
}
