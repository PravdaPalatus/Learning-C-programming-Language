#include <stdio.h> //scanf, printf, fopen, all file manipulation functions
#include <stdlib.h> //calloc, malloc, free

int main(){
    unsigned long int *array;
    int N;
    FILE * fibFile;

    //number of elements of the array
    puts("Enter the number of elements (1 - 94):");
    scanf("%d%*c", &N);

    //memory allocation array
    array = (unsigned long int *) calloc(N, sizeof(unsigned long int));

    //filling the fibonacci array
    for(int i = 0; i < N; i++){
        if(i == 0 ) array[i] = 0;
        else if(i == 1) array[i] = 1;
        else{
            array[i] = array[i - 1] + array[i - 2];
        }
    }

    //open FILE
    fibFile = fopen("fibonacci.txt", "w");

    //testing and writing in a file "fibonacci.txt"
    if(fibFile != NULL){
        for(int k = 0; k < N; k++){
            fprintf(fibFile, "%lu\n", array[k]);
        }
    }

    //closing the file
    fclose(fibFile);

    //printing the last element
    printf("The last element of the array is: %lu\n", array[N-1]);

    free(array);
    return EXIT_SUCCESS;
}
