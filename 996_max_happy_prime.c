//max happy prime
#include <stdio.h>
#include <math.h>

int next_number(int num);
int is_prime(int num);
int is_happy(int num);
int max_happy_prime(int num);


int main(){

    int num, max;
    printf("Enter a positive integer greater than zero (num > 0): ");
    scanf("%d", &num);

    max = max_happy_prime(num);
    if(max == 0) printf("There is no happy and prime number equal or under this number\n");
    else printf("The maximun happy and prime number is: %d\n", max);

    return 0;
}

int next_number(int num){     
    int x = 1;
    int sum = 0;
    for(int i = 10; (num > 0); i *= 10){
        x = num % 10;
        sum += pow(x, 2);
        num = num / 10;
    }
    return sum;
}

int is_prime(int num){
    for(int i = 2; i < num; i++){
        if(num % i == 0) break;
        if(i == num - 1) return 1;
    }
    return (num == 2)? 1:0;
}

int is_happy(int num){
    if(next_number(num) == 1) return 1;
    if(next_number(num) == 4) return 0;
    return is_happy(next_number(num));
}

int max_happy_prime(int num){
    int max = 0;
    for(int i = num; i > 0; i--){
        if(is_happy(i)){
            if(is_prime(i)){
                if(i > max) max = i;
            }
        }
    }
    return max;
}
