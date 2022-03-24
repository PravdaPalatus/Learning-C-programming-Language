//palindrome

#include <stdio.h>
#include <string.h> //função para calcular o length of a string(array): strlen(str)
#define MAX_S 1000

int string_length(char *msg);
void space_out(char *msg);
int is_polin(char *msg);

int main(){
    char msg[MAX_S]; msg[MAX_S - 1] = '\0';
    printf("Qual a frase: ");
    fgets(msg, MAX_S - 1, stdin); msg[strlen(msg) - 1] = '\0';
    space_out(msg);
    int res;
    res = is_polin(msg);
    printf("%d\n", res);
    printf("Sua msg é polindrome?\n");
    if(res == 1) printf("É um Polindrome!\n");
    else printf("Is is not a Polindrome\n");

    
    return 0;
}

int string_length(char *msg){
    int c = 0;
    while(msg[c] != '\0')
        c++;
    return c;
}

//remover os espaços do string
void space_out(char *msg){ //pode usar: for(i=0;msg[i]!='\0';i++){if(msg[i]!='\0')msg[b]=msg[i]}
    int c = 0;
    while(msg[c] != '\0'){
        if(msg[c] == ' '){
            int b = c;
            while(msg[b] != '\0'){
                msg[b] = msg[b + 1];
                b++;
            }
        c++;
        }
        else{
            c++;
        }
    }
    printf("Agora vai: %s\n", msg);
}

int is_polin(char *msg){
    int res = 1;
    int size = string_length(msg);
    printf("size: %d\n", size);
    for(int i = 0; i < size/2; i++){
        if(msg[i] == msg[size - (i + 1)]) res = 1;
        else return 0;
    }
    return res;
}