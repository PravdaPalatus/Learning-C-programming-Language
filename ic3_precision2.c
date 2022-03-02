#include <stdio.h>

int main(){
    int i;
    double n;
    float count1;
    double count2;
    count1 = count2 = 0.0;
    puts("Enter a number:");
    scanf("%lf", &n);
    printf("The number is: %0.0lf\n", n);
    for(i=1; i<=729; i++){
        count1 = count1 + (1/n);
        count2 = count2 + (1/n);
    }
    printf("Count1 = %0.15f and Count2 = %0.15lf\n", count1, count2);
    return 0;
}