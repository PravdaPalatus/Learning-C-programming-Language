//calculates differences between adjacent elements of X along the first array dimension
#include <stdio.h>
#define MMAX 250

void printArr(float* arr, int num);
void arrOfDiff(float* arr, float* arr2, int num);

int main(){
    int num;
    float arr[MMAX];
    float arr2[MMAX];

    puts("Enter the numbers of elements of a array: ");
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        printf("Enter the element n. %d: ", i);
        scanf("%f", &arr[i]);
    }
    puts("We have the array:");
    printArr(arr, num);
    arrOfDiff(arr, arr2, num);
    puts("\nThe array of differences is:");
    printArr(arr2, num - 1);
    float max = arr2[0];
    float min = arr2[0];
    for(int i = 1; i < num - 1; i++){
        if(arr2[i] > max) max = arr2[i];
        else if(arr2[i] < min) min = arr2[i];
    }
    printf("The max element of the second array is: %.2f\n", max);
    printf("The min element of the second array is: %.2f\n", min);
    return 0;
}

void arrOfDiff(float* arr, float* arr2, int num){ 
    for(int i = 0; i < num - 1; i++){
        arr2[i] = arr[i + 1] - arr[i];
    }
}

void printArr(float* arr, int num){
    for(int i = 0; i < num; i++){
        if(i == num - 1) printf("%.2f", arr[i]);
        else printf("%.2f, ", arr[i]);
    }
    printf("\n");
}