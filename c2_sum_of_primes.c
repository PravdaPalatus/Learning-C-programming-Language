// sum of primes

#include <stdio.h>

int is_prime(int num);
int sum_of_primes(int a, int b);

int main(){

    int a, b, sum;
    printf("***Sum of Primes***\n");
    printf("Enter the range (a, b) to calculate the sum of primes (a must be less than b): \n");
    scanf("%d %d", &a, &b);
    sum = sum_of_primes(a, b);
    printf("The sum of primes of this range is: %d\n", sum);

    return 0;
}

int is_prime(int num){
    int count;
    for(count = 2; count < num; count++){
        int res = num % count;
        if(res == 0) break;
        if(count == num -1) return 1;
    }
    return (num == 2)? 1:0;
}

int sum_of_primes(int a, int b){
    int sum = 0;
    for(int i = a; i <= b; i++){
        if(is_prime(i) == 1) sum += i;
    }
    return sum;

}

