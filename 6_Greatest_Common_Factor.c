#include <stdio.h>

int main(){
    int n1, n2, max, i;
    max = 0;
    puts("Enter the first number:");
    scanf("%d", &n1);
    puts("Enter the second number:");
    scanf("%d", &n2);
    printf("The numbers are: %d and %d.\n", n1, n2);
    if(n1>n2){
        i = n1;
    } else{
        i = n2;
    }
    while(max == 0){
        if(n1 % i == 0 && n2 % i == 0){
            max = i;
        }
        i = i - 1;
    }
    printf("The greatest common factor is: %d\n", max);
    return 0;
}
