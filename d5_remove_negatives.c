//remove negative numbers from a arrayof integers
#include <stdio.h>
#define MMAX 250

void printArr(int* arr, int num);
void removeElem(int* arr, int num, int n1);
void removeNegative(int* arr, int num);
void reverseArr(int* arr, int num);

int main(){

    int num;
    int arr[MMAX];

    puts("Enter the number of elements of the array: ");
    scanf("%d", &num);
    for(int i = 0; i < num;i++){
        printf("Enter the element %d (positive and negative integers): ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("We have the following array:\n");
    printArr(arr, num);
    removeNegative(arr, num);

    return 0;
}

void printArr(int* arr, int num){
    for(int i = 0; i < num; i++){
        if((i + 1) == num) printf("%d\n", arr[i]);
        else printf("%d, ", arr[i]);
    }
}

void removeElem(int* arr, int num, int n1){
    for(int i = n1; i < num; i++){
        arr[i] = arr[i + 1];
    }
}

void removeNegative(int* arr, int num){
    int acc = num;
    for(int i = 0; i < acc;){
        if(arr[i] < 0){
            removeElem(arr, num, i);
            acc--;
        }
        else i++;
    }
    num = acc;
    if(num == 0){
        printf("All the numbers were negatives, so the array is empty.\n");
    }
    else{
        printf("This is the array without negative numbers:\n");
        printArr(arr, num);
        printf("This is the reverse array:\n");
        reverseArr(arr, num);
        printArr(arr, num);
    }
}

void reverseArr(int* arr, int num){
    int holder;
    for(int i = 0; i < num/2; i++){
        holder = arr[i];
        arr[i] = arr[num-(i + 1)];
        arr[num - (i + 1)] = holder;
    }
}
