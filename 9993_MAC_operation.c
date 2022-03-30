#include <stdio.h>
#define MAXN 250

void printArray(int* array, int num);
int sumOfArray(int* array2, int num);
void functMac(int* array, int* array2, int num, int multConst, int addConst);

int main(){

    int arr[MAXN];
    int arr2[MAXN];
    int n, mult, add;

    printf("Enter the number of elements of the array: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Enter element number %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    puts("I have the follow array:");
    printArray(arr, n);

    puts("Enter the multiply constant: ");
    scanf("%d", &mult);
    puts("Enter the add constant: ");
    scanf("%d", &add);

    functMac(arr, arr2, n, mult, add);
    printf("After the MAC function I have the following array: \n");
    printArray(arr2, n);
    printf("The sum of the elements of the second array is: %d\n", sumOfArray(arr2, n));

    return 0;
}

void printArray(int* array, int num){
    for(int j = 0; j < num; j++){
        if((j + 1) == num){
            printf("%d\n", array[j]);
            break;
        }
        else printf("%d, ", array[j]);
    }
}

int sumOfArray(int* array2, int num){
    int sum = 0;
    for(int i = 0; i< num; i++){
        sum = sum + array2[i];
    }
    return sum;
}

void functMac(int* array, int* array2, int num, int multConst, int addConst){
    for(int i = 0; i < num; i++){
        array2[i] = array[i]*multConst + addConst;
    }
}
