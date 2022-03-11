//sum of hailstone sequence

#include <stdio.h>

int sum_hailstone_seq(int a);

int main(){

    int a, sum;
    printf("Enter a number to be the starting point of our Hailstone seq. (positive integer number): \n");
    scanf("%d", &a);
    printf("I got the %d as starting point.\n", a);

    sum = sum_hailstone_seq(a);
    printf("The sum of the Hailstone is: %d\n", sum);

    return 0;
}

int sum_hailstone_seq(int a){
    int sum = a;
    while(a != 1){
        if(a % 2 == 0){
            a = a / 2;
            sum += a;
            }
        else{
            a = (3 * a) + 1;
            sum += a;
        }
    }
    return sum;
}

