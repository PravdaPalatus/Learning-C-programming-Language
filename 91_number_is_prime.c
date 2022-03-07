#include <stdio.h>
#include <math.h>

//prototype

int isPrime(int);
int printPrime(int, int);

int main(){
    
    int num;

    printf("Enter a number:");
    scanf("%d", &num);

    if(num == 0 || num == 1) printf("Invalid number\n");
    if(num == 2) printf("This is not a prime number\n");
    else{
        if(isPrime(num) == 1) printf("This is a prime number\n"); //if(isPrime(num))
        else printf("This is not a prime number\n");
    }

    printPrime(1, 100);

    return 0;
}

//definitian

int isPrime(int num){
    int count;
    for(count = 2; count < num; count++){ //sqrt(num) reduces the number of interactions
        int res = num % count;
        if(res == 0) break;
        if(count == num - 1) return 1;
    }
    return (num == 2)? 1:0;
    //return (num==1 || num==0)? 0:1;

}

int printPrime(int a, int b){

    for(int count = a; count <= b; count++){

        if(isPrime(count) == 1) printf("%d * ", count);
    
    }
    printf("\n");
    return 0;
}
