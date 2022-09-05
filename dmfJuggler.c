//NUMBER THEORY: Juggler Sequence

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int *array;
    int num;
    int startNum;

    //asking the number of elements
    puts("How many elements in the array?");
    scanf("%d%*c", &num);

    //memory allocation
    array = (int *) calloc(num, sizeof(int));

    //asking the starting number
    puts("What is the starting number?");
    scanf("%d%*c", &startNum);

    //filling the array
    for(int i; i < num; i++){
        if(i == 0) array[i] = startNum;
        else{
            if(array[i - 1] % 2 == 0) array [i] = floor(sqrt(array[i -1]));
            else array [i] = floor(sqrt(pow(array[i -1], 3)));
        }
    }

    // max and min
    int max = startNum;
    int min = startNum;
    int sum = startNum;
    for(int i = 1; i < num; i++){
        if(array[i] < min) min = array[i];
        else if(array[i] > max) max = array[i];
        sum += array[i];
    }
    double aver = (double) sum / (double) num;
    //printing

    printf("The minimum number is %d\n", min);
    printf("The maximum number is %d\n", max);
    printf("The average is %lg\n", aver);

    free(array);
    return EXIT_SUCCESS;
}

