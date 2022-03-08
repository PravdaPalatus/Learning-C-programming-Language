//digits of a number (positive numbers only)

#include <stdio.h>

void printDigits(int);

int main(){

    int num;
    puts("Digite um número:");
    scanf("%d", &num);

    printDigits(num);

    printDigits(0);         //printig the digits of 0 ----problem we need to solve

    printDigits(1);         //fix this (watch out the value of local time variable)----problem

    printDigits(-1234);     //modify your function to solve the problem for negative values as well

    return 0;
}


//solução do professor
void printDigits(int n){
    static int time = 0;
    if(n == 0){
        if(time == 0){
            printf("\'%d\'\n", n);
            return;
        }
        time--;
        return;                  //!n pode usar //base case: n == 0 -> return
    }

    if(n < 0){
        n = -1 * n;
    }
    
    time++;
    printDigits(n/10);                  //inductive step: printDigits(n/10)

    //printf("\t -> %d\n", time);

    printf("\'%d\'", n%10);

    if(time != 0){
        time--;
    }else{
        puts(" ");
    }
    


}