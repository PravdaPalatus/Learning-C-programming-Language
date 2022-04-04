#include <stdio.h>
#include <string.h>
#define MMAX 1000

void printStr(char* msg, int len);
void reverseStr(char* msg, int len);
void upperStr(char* msg, int len);

int main(){
    char msg[MMAX];
    puts("Enter a one line message: ");
    fgets(msg, MMAX, stdin); msg[strlen(msg) -1] = '\0';
    int len = strlen(msg);
    printf("You enter the following message: ");
    printStr(msg, len);
    printf("The reverse version of the message is: ");
    reverseStr(msg, len);
    printStr(msg, len);
    printf("The reverse and uppercase verison of the message is: ");
    upperStr(msg, len);
    printStr(msg, len);

    return 0;
}

void printStr(char* msg, int len){
    for(int i = 0; i < len; i++){
        printf("%c", msg[i]);
    }
    printf("\n");
}

void reverseStr(char* msg, int len){
    for(int i = 0; i < len/2; i++){
        char holder = msg[i];
        msg[i] = msg[len-(i+1)];
        msg[len-(i+1)] = holder;
    }
}

void upperStr(char* msg, int len){
    for(int i = 0; i < len; i++){
        if(msg[i] >= 97 && msg[i] <= 122) msg[i] = msg[i] - ('a' - 'A');
    }
}
