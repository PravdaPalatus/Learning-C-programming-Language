//creating the Golomb.txt

#include <stdio.h>
#include <stdlib.h>

int main() {
    long int *array;
    long int N = 10000002;
    FILE * golomb;

    //reserving memory
    array = (long int *) calloc(N, sizeof(long int));

    //filling the array

    for(int i = 0; i < N; i++){
        if(i == 0) array[0] = 1;
        else array[i] = 1 + array[i - array[array[i -1] - 1]];
    }

    //creating txt
    golomb = fopen("golomb.txt", "w");

    //writing file
        if(golomb != NULL){
            for(int j = 0; j < N; j++){
                fprintf(golomb, "%ld\n", array[j]);
            }
        }

    //closing the file
    fclose(golomb);

    //liberating memory
    free(array);
    return EXIT_SUCCESS;
}
