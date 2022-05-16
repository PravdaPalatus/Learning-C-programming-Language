//finite state machine
//********two ways to calculate*******
#include <stdio.h>

int count_doors(int * data, int size);
int count_second(char * sensor);

int main(){
    int data[] = {1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1};
    //char data_string[] = "0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0"; //***second way

    long int size = sizeof(dados)/sizeof(data[0]);

    printf("Size of data: %ld\n", size);
    
    printf("The door closed %d times.\n", count_doors(data, size));

    //printf("The door closed (Second solution): %d times\n", count_second(data_string));

    return 0;
}

int count_doors(int * data, int size){
    int count = 0;
    for(int i = 0; i < size - 1; i++){
        if(data[i] == 1 && data[i+1] == 0) count++;
    }
    return count;
}

/*int count_second(char * sensor){ //second and short way - finite state machine
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
} */
