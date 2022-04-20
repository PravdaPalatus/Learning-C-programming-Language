#include <stdio.h>

void printArr(int* arr, int num);
int findNumber(int* arr, int num, int number);

int main(){
    int num;
    puts("Enter the number of elements of the array: ");
    scanf("%d", &num);
    
    int arr[num];
    for(int i = 0; i < num; i++){
        printf("Enter element %d:", i + 1);
        scanf("%d", &arr[i]);
    }
    puts("We have the following ARRAY: ");
    printArr(arr, num);

    int number;
    puts("Enter a number to find in the array: ");
    scanf("%d", &number);

    if(findNumber(arr, num, number) == -1) printf("FAIL!! I can't find the number in the array.\n");
    else printf("The number is in the index: %d\n", findNumber(arr, num, number));

    return 0;
}

void printArr(int* arr, int num){
    for(int i = 0; i < num; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int findNumber(int* arr, int num, int number){
    for (int i = 0; i < num; i++){
        if(arr[i] == number) return i;
    }
    return -1;
}
