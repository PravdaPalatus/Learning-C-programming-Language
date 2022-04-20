//Sort the uppercase version of all letters in the lexicographical order
#include <stdio.h>
#include <string.h>
#define MMAX 250

void printWord(char* arr, int lenght);
void uppercaseVersion(char* arr, int lenght);
void lexicolOrder(char* arr, int lenght);

int main(){

    char word[MMAX]; word[MMAX - 1] = '\0';
    puts("Enter a word: ");
    scanf("%s", &word[0]);

    int len = strlen(word);

    uppercaseVersion(word, len);
    
    lexicolOrder(word, len);
    printf("The letters of the word (uppercase version) sorted according to lexicographical order:\n");
    printWord(word, len);

    return 0;
}

void printWord(char* arr, int lenght){
    for(int i = 0; i < lenght; i++){
        printf("%c", arr[i]);
    }
    printf("\n");
}

void uppercaseVersion(char* arr, int lenght){
    for(int i = 0; i < lenght; i++){
        if(arr[i] >= 97) arr[i] = arr[i] - 32;
    }
}

void lexicolOrder(char* arr, int lenght){
    for(int i = 0; i < lenght;i++){
        for(int j = i + 1; j < lenght;j++){
            if(arr[i] > arr[j]){
                char aux;
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}