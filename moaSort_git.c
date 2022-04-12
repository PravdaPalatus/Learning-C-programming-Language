#include <stdio.h>

void buildArray(int* arr, int n);
void printArray(int* arr, int n);
void sortAscending (int* arr, int n);
void swap(int* a, int* b);
void sortDescending (int* arr, int n);


int main(){

    int num;
    puts("Enter the number of elements of the array:");
    scanf("%d", &num);
    int arr[num];
    buildArray(arr, num);
    printf("Unsorted Array:\n");
    printArray(arr, num);
    sortAscending(arr, num);
    printf("Sorted ascending array:\n");
    printArray(arr, num);
    sortDescending(arr, num);
    printf("Sorted descending array:\n");
    printArray(arr, num);

    return 0;
}

void buildArray(int* arr, int n){
    for(int i = 0; i < n; i++){
        printf("Element %d: \n", i);
        scanf("%d", &arr[i]);
    }
}

void printArray(int* arr, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sortAscending (int* arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]){
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void swap(int* a, int* b){
    int aux = *b;
    *b = *a;
    *a = aux;
}

void sortDescending (int* arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] < arr[j]){
                swap(&arr[i], &arr[j]);
            }
        }
    }
}