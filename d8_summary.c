//program to input text in different paragraphs, prints out the entire text showing the number of lines entered and the number of words in the text
#include <stdio.h>
#include <string.h>
#define MMAX 10000

int inputtext(char* text);
int isChar(int letter);
int countWords(char* msg, int len);
void printStr(char* str);

int main(){

    char text[MMAX]; text[MMAX - 1] = '\0';
    int n_lines = 0;
    int n_words = 0;
    int lenght;

    puts("Enter your text (hit enter two times to finish):");

    n_lines = inputtext(text);
    lenght = strlen(text);
    n_words = countWords(text, lenght);

    printStr(text);
    printf("The number of lines is: %d\n", n_lines);
    printf("The number of words is: %d\n", n_words);

    return 0;
}

int inputtext(char* text){
    int n_lines = 0;
    int lenght = 1;
    int aux = 0;
    while(lenght != 0){
        char arr_aux[MMAX] = {};
        fgets(arr_aux, MMAX, stdin); arr_aux[strlen(arr_aux) -1] = '\0';
        for(int i = 0; i < MMAX; i++){
            if(arr_aux[i] == '\0'){
                text[aux] = '\n';
                aux++;
                break;
            }
            text[aux] = arr_aux[i];
            aux++;
        }
        n_lines++;
        lenght = strlen(arr_aux);
    }
    return n_lines - 1;
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

void printStr(char* str){
    int len = strlen(str);
    for(int i = 0; i < len ; i++){
        printf("%c", str[i]);
    }
    printf("\n");
}
