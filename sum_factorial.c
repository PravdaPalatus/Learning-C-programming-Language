//sum of factorial

#include <stdio.h>

int fac(int n);
int sum_fac(int n);

int main(){

    printf("%d\n", fac(5));
    printf("%d\n", sum_fac(5));

    return 0;
}

int fac(int n){                     //n! = n * (n-1)!   //1! = 1 and 0! = 0
    if(n == 1 || n == 0) return 1;  //base case
    else{
        return n * fac(n-1);        //recursive step
    }
}

int sum_fac(int n){
    if(n == 1) return 1;
    else{
        return fac(n) + sum_fac(n-1);
    }
}