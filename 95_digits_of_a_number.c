//digits of a number

#include <stdio.h>

void printDigits(int);

int main(){

    int num;
    puts("Digite um número:");
    scanf("%d", &num);

    printDigits(num);

    printDigits(0);

    printDigits(1);

    printDigits(-1234);

    return 0;
}

void printDigits(int n){
    static int time = 0;
    if(n == 0){
        if(time == 0){
            printf("\'%d\'\n", n);
            return;
        }
        time--;
        return;
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
