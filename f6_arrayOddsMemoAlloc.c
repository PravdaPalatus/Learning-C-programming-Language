//memory allocation - basic

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    long int num;
    int s;
    long int sum;
    double aver;
    
    //ask how many array elements
    puts("How many elements do you want on the array of integers?");
    scanf("%ld%*c", &num);
    
    //ask the initial number of the array (only odd numbers will be considered to fill the array)   
    puts("Which number would you like to start with?");
    scanf("%d%*c", &s);
    
    //dynamic memory allocation
    array = (int *) calloc(num, sizeof(int));
    
    //adjusting the s
    if(s % 2 != 0) s = s - 1;
    
    //filling the array
    for(int i = 0; i < num; i++){
            if(i > 0) array[i] = array[i - 1] + 2;
            else array[i] = s + 1;
            sum += array[i];
    }
    //calculating the average of the numbers
    aver = (double) sum / (double) num;  
    
    //printing
    printf("The last number of the array is %d\n", array[num - 1]);
    printf("The average of the numbers of the array is %lg\n", aver);
    
    //free the memory
    free(array);
    return EXIT_SUCCESS;
}
