//Count the number of words within a message
#include <stdio.h>
#include <string.h>
#define MMAX 1000

int isChar(int letter);
int countWords(char* msg, int len);

int main(){

    char msg[MMAX]; msg[MMAX - 1] = '\0';
    int len;

    puts("Enter a one line message:");
    fgets(msg, MMAX, stdin);
    len = strlen(msg);
    printf("%s", msg);

    printf("The message has %d words.\n", countWords(msg, len));

    return 0;
}

int isChar(int letter){
    if(letter > 47 && letter < 58) return 1;
    else if(letter > 64 && letter < 91) return 1;
    else if(letter > 96 && letter < 123) return 1;
    else if(letter == 45) return 1;
    else return 0;
}

int countWords(char* msg, int len){
    int state = 0;
    int acc = 0;
    
    for(int i = 0; i < len; i++){
        if(isChar(msg[i]) == 1 && state == 0){
            acc++;
            state = 1;
        }
        else if(isChar(msg[i]) == 0 && state == 1){
            state = 0;
        }
    }
    return acc;
}
