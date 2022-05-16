//five number summary

#include <stdio.h>
#define MAX_ELEMENTS 100

void get_elements(float *dataset, int size);
void order(float *dataset, int size);
void break_array(float *dataset,float *upSet, float *downSet, int size);
void five_summary(float *dataset, float *five, float *upSet, float *downSet, int size);

int main(){

    int size;
    float dataset[MAX_ELEMENTS], five[5], upSet[MAX_ELEMENTS], downSet[MAX_ELEMENTS];

    printf("What is the size of the dataset (>5)?\n");
    scanf("%d", &size);

    get_elements(dataset, size);
    printf("We have the following dataset: ");
    for(int i = 0; i < size; i++){
        printf("%.1f ", dataset[i]);
    }
    printf("\n");

    order(dataset, size);
    printf("We have the following sorted dataset: ");
    for(int i = 0; i < size; i++){
        printf("%.1f ", dataset[i]);
    }
    printf("\n");

    five_summary(dataset, five, upSet, downSet, size);
    printf("We have the following five number summary: ");
    for(int i = 0; i < 5; i++){
        printf("%.1f ", five[i]);
    }
    printf("\n");


    return 0;
}

void get_elements(float *dataset, int size){
    for(int i = 0; i < size; i++){
        printf("Element %d: ", i + 1);
        scanf("%f", dataset + i); //pode usar tb &dataset[i]
    }
}

void order(float *dataset, int size){
    for(int i = 0; i < size; i++){
        for(int y = 0; y < size; y++){
            if(dataset[i] < dataset[y]){
                float holder = dataset[y];
                dataset[y] = dataset[i];
                dataset[i] = holder;
            }
        }
    }
}

void break_array(float *dataset,float *upSet, float *downSet, int size){
    if(size % 2 != 0){
        for(int i = 0; i < size; i++){
            if(i < size/2){
                upSet[i] = dataset[i];
            }
        }
        for(int i = 0; i < size; i++){
            if(i > size/2){
                downSet[i - ((size/2) + 1)] = dataset[i];
            }
        }
    }
    if(size % 2 == 0){
        for(int i = 0; i < size; i++){
            if(i < size/2){
                upSet[i] = dataset[i];
            }
        }
        for(int i = 0; i < size; i++){
            if(i >= size/2){
                downSet[i - ((size/2))] = dataset[i];
            }
        }
    }
}


void five_summary(float *dataset, float *five, float *upSet, float *downSet, int size){
    int x = size/2;
    int y = (size/2)/2;
    five[0] = dataset[0];
    five[4] = dataset[size - 1];
    break_array(dataset, upSet, downSet, size);
    if(size % 2 == 0){
        five[2] = (dataset[x] + dataset[(x) - 1])/2;
        five[1] = (upSet[y] + upSet[(y) - 1])/2;
        five[3] = (downSet[y] + downSet[y - 1])/2;
    }
    else{
        five[2] = dataset[x];
        five[1] = upSet[y];
        five[3] = downSet[y];
    }
   
}
