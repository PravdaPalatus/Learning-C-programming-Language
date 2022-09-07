#include <stdio.h>
#include <stdlib.h>

long int howManyInt (FILE * filename);

int main(){
    long int *arrayTotal;
    long int *array;
    FILE * myfile;
    
    //open file
    myfile = fopen("golomb.txt", "rb");

    //how many integers the file has
    long int N;
    N = howManyInt(myfile);

    //asking the user
    long int firstIdx;
    long int lastIdx;
    puts("What is the first index that should be read?");
    scanf("%ld", &firstIdx);
    puts("What is the last index that should be read?");
    scanf("%ld", &lastIdx);

    //allocating memory
    arrayTotal = (long int *) calloc(N, sizeof(long int));
    long int aux = (lastIdx - firstIdx) + 1;
    array = (long int *) calloc(aux, sizeof(long int));

    //filling the array
    for(int i = 0; i < N; i++){
        fscanf(myfile, "%ld", arrayTotal + i);
    }
    
    for(int i = 0; i < aux; i++){
        array[i] = arrayTotal[firstIdx + i];
    }

    //calculating the average of numbers
    long int sum = 0;
    for(int k = 0; k < aux; k++){
        sum += array[k];
    }
    double average = (double) sum / (double) aux;

    //printing
    printf("The file golomb.txt has %ld integers\n", N);
    printf("The first element of the resulting array is: %ld\n", array[0]);
    printf("The last element of the resulting array is: %ld\n", array[aux - 1]);
    printf("The average of the resulting array is: %lg\n", average);
    
    //closing file
    fclose(myfile);

    return EXIT_SUCCESS;
}

long int howManyInt (FILE * filename){
    FILE * myfile;
    long int count = 0; int aux;
    myfile = fopen("golomb.txt", "r");
    if(myfile != NULL){
        while(!feof(myfile)){
            if(fscanf(myfile, "%d", &aux) >= 0) count++; //fscanf returns -1 when fails
        }
    }
    fclose(myfile);
    return count;
}