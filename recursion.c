//recursion

#include <stdio.h>

int sum1(int);
int sum2(int);
int sumRec(int);

int main(){
    int n = 5;

    int s1 = sum1(n);
    int s2 = sum2(n);

    printf("Sum of integers from "
    "1 to %d is equal to (v1)%d and (v2)%d\n",
    n, s1, s2);

    printf("Sum in recursion mode is equal to %d\n", sumRec(n));

return 0;
}

int sum1(int n){
    int sum = 0;

    for(int i = 1; i <= n; i++){
        sum += i;
    }
return sum;

}

int sum2(int n){
    int sum = 0;

    for(int i = n; i >= 1; i--){
        sum += i;
    }
return sum;
}

int sumRec(int n){
    if(n > 1) return (n + sumRec(n - 1));   //inductive step
    else return 1;                          //base case

}