//finite state machine

#include <stdio.h>

int count_doors(int * data, int size);
int count_prof(char * sensor);

int main(){
    int dados[] = {1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1};
    char dados_string[] = "0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0";

    long int size = sizeof(dados)/sizeof(dados[0]);

    printf("Size of dados: %ld\n", size);
    
    printf("A porta fechou %d vezes.\n", count_doors(dados, size));

    printf("Igor's solution: %d\n", count_prof(dados_string));

    return 0;
}

int count_doors(int * data, int size){
    int count = 0;
    for(int i = 0; i < size - 1; i++){
        if(data[i] == 1 && data[i+1] == 0) count++;
    }
    return count;
}

int count_prof(char * sensor){ //essa é a verdadeira finite state machine
    int state = 1; //close state
    int acc = 0;
    for(int i = 0; sensor[i]; i++){
        if(state == 1 && sensor[i] == '0'){
            state = 0; //open state
            acc++;
        }
        if(state == 0 && sensor[i] == '1')
            state =1; //close state
    }
    return acc;
}