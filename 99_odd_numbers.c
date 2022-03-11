//print all odd numbers within that range

#include <stdio.h>

void print_odds(int a, int b);

int main(){

    int a, b;
    printf("Enter the range (a -> b) that you want to print the odds between (PS:a < b): \n");
    scanf("%d %d", &a, &b);
    print_odds(a, b);
    return 0;
}

void print_odds(int a, int b){
    for(int i = 0; i <= (b - a); i++){
        if((a + i) % 2 != 0){
            if(i == 0 || i == 1) printf("%d", a + i);
            else{
                printf(", %d", a + i);
            }
        }
    }
    printf("\n");
}
