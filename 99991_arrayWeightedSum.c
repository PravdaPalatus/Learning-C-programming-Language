//weighted sum of the elements of a array considering their respective weights
#include <stdio.h>

void weightsArray(float* arr, int num);
void printArray(float* arr, int num);
void elementArray(float* arr, int num);
float weightedSum(float* arrWeights, float* arrElements, int num);

int main(){
    int num;
    puts("Enter the number of elements of the array: ");
    scanf("%d", &num);

    float arrWeights[num];
    weightsArray(arrWeights, num);
    puts("The array of weights is:");
    printArray(arrWeights, num);

    float arr[num];
    elementArray(arr, num);
    puts("The array of elements is:\n");
    printArray(arr, num);
    printf("The weighted sum of the element of the array is: %g", weightedSum(arrWeights, arr, num));
    
    puts("\n");
    return 0;
}

void weightsArray(float* arr, int num){
    for(int i = 0; i < num; i++){
        printf("Enter the weight of the element %d: ", i + 1);
        scanf("%f", &arr[i]);
    }
}

void printArray(float* arr, int num){
    for(int i = 0; i < num; i++){
        printf("%g ", arr[i]);
    }
    printf("\n");
}

void elementArray(float* arr, int num){
        for(int i = 0; i < num; i++){
            printf("Enter the element %d: ", i + 1);
            scanf("%f", &arr[i]);
    }
}

float weightedSum(float* arrWeights, float* arrElements, int num){
    float sum = 0.0;
    for(int i = 0; i < num; i++) sum = sum + (arrWeights[i]*arrElements[i]);
    return sum;
}
