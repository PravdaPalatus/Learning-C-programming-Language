//sum of divisors
#include <stdio.h>

int sum_of_divisors(int num);

int main(){
    int num, sum;
    
    printf("Enter a positive integer: \n");
    scanf("%d", &num);

    sum = sum_of_divisors(num);
    printf("The sum of the divisors of the number %d is -> %d.\n", num, sum);

    return 0;
}

int sum_of_divisors(int num){
    int sum = 0;
    for(int i = 1; i <= num; i++){
        if(num % i == 0) sum += i;
    }
    return sum;
}