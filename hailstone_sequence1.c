#include <stdio.h>

int hailstoneSeq(int number);

int main(){
    int number;
    puts("Enter a integer number:");
    scanf("%d", &number);
    hailstoneSeq(number);
    return 0;
}

int hailstoneSeq(int number){
    if(number == 1){
        printf("%d\n", number);
        return 1;
    }
    else{
        if(number % 2 != 0){
            printf("%d ", number);
            number = ((number*3)+1);
            return hailstoneSeq(number);

        } 
        else{
            printf("%d ", number);
            number = number / 2;
            return hailstoneSeq(number);
        }
    }
}