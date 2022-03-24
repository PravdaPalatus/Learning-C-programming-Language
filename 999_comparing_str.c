//comparing strings in a indice

#include <stdio.h>
#include <string.h> //strcmp(str1, str2) string compare (just to check)
#include <stdlib.h>
#define MAX 100

void lower_case(char *str, int length); //We will not considere the differtent between lower and upper case
int compare_str(char *str1, char *str2, int length);

int main(){

    char first_msg[MAX] = "abc"; first_msg[MAX - 1] = '\0';
    char second_msg[MAX] = "AbC"; second_msg[MAX - 1] = '\0';
    int first_length = strlen(first_msg);
    int second_length = strlen(second_msg);
    int length = first_length;
    if(first_length < second_length) length = second_length;
    printf("%s\n", first_msg);
    lower_case(first_msg, first_length);
    printf("%s\n", first_msg);
    printf("%s\n", second_msg);
    lower_case(second_msg, second_length);
    printf("%s\n", second_msg); 
    
    int score = compare_str(first_msg, second_msg, length);
    if(score == 0) printf("They are the same.\n");
    else if(score == 1) printf("Second msg is greater (first)\n");
    else if(score == -1) printf("first msg is greater\n");

    return 0;
}

void lower_case(char *str, int length){
    for(int i = 0; i < length; i++){
        if(str[i] < 'a' && str[i] != ' '){
            str[i] = str[i] + ('a' - 'A');
        } 
        if(str[i] == ' '){
            str[i] = ' ';
        }
    }
    return;
}

int compare_str(char *str1, char *str2, int length){
    int same = 0;
    for(int i = 0; i < length; i++){
        if(str1[i] == str2[i]){
            same += 1;
        }
        else{
            if(str1[i] < str2[i] ) return 1; //second is greater
            else{
                return -1; //first is greater
            }
        }
    }
    
    return 0; //same
}


//short version and considering upper and lower case
//int my_cmp(char * str1, char * str2){
    //int i = 0;
    //while(str[i]){
        //if(str1[i] > str2[i]) return 1;
        //if(str1[i] < str2[i]) return -1;
        //i++;
    //}
    //if(str2[i]) return -1;
    //return 0;
