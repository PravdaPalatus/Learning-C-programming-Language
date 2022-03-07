//is prime number?
#include <stdio.h>
#include <math.h>

//prototype

int isPrime(int);
int printPrime(int, int);

int main(){
    
    int num;

    printf("Digite um número:");
    scanf("%d", &num);

    if(num == 0 || num == 1) printf("Num não válido\n");
    if(num == 2) printf("Num é Primo\n");
    else{
        if(isPrime(num) == 1) printf("Num é Primo\n"); //aqui poderia ser: if(isPrime(num))
        else printf("Num não é primo\n");
    }

    printPrime(1, 100);

    return 0;
}

//definitian

int isPrime(int num){
    int count;
    for(count = 2; count < num; count++){ //num = 1000 n-2 >>>>998 interações, já com: sqrt(1000) = 31  31-2 >>> 29
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