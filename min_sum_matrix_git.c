// find the minimum sum of N elements of a matrix where each element should be in unique row and column
#include <stdio.h>
#define SIZE 5

int globalSum;
int finalRowIdx[SIZE];
int finalColIdx[SIZE];

void print2DArr(int arr[SIZE][SIZE]);
void minSum(int* arr, int* rowsIdxAux, int* colIdxAux, int step, int* sum);
int existIdx(int* arr, int idx);
void copyToPath(int* finalRowIdx, int* finalColIdx);
void printPath(int* finalRowIdx, int* finalColIdx);


int main(){

    int arr[SIZE][SIZE];
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            printf("Enter element (%d, %d): ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("The square matrix:\n");
    print2DArr(arr);

    //int arr[SIZE][SIZE] = {{5,4,4,1,6}, {1,3,2,4,6}, {3,2,3,2,6}, {0,4,5,4,6}, {6,6,6,6,6}};
    print2DArr(arr);
    int rowsIdxAux[SIZE];
    for(int i = 0; i < SIZE ; i++) rowsIdxAux[SIZE] = -1;
    int colsIdxAux[SIZE];
    for(int i = 0; i < SIZE ; i++) colsIdxAux[SIZE] = -1;
    int step = 0;
    int sum = 0;
    globalSum = 100;

    minSum((int*) arr, rowsIdxAux, colsIdxAux, step, &sum);

    printf("The minimun sum is: %d\n", globalSum);
    printPath(finalRowIdx, finalColIdx);
    

    return 0;
}

void print2DArr(int arr[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
}

int existIdx(int* arr, int idx){
    for(int i = 0; i < SIZE; i++){
        if(arr[i] == idx) return 1;
    }
    return 0;
}

void minSum(int* arr, int* rowsIdxAux, int* colsIdxAux, int step, int* sum){
    if(step == SIZE){
        if(*sum < globalSum){
            globalSum = *sum;
            copyToPath(rowsIdxAux, colsIdxAux);
        }
        return;
    }

    for(int rowIdx = 0; rowIdx < SIZE; rowIdx++){
        if(existIdx(rowsIdxAux, rowIdx)) continue; //é o mesmo rowidx e colidx que estava antes durante o step?? Sim, é o mesmo anteiror.
        for(int colIdx = 0; colIdx < SIZE; colIdx++){
            if(existIdx(colsIdxAux, colIdx)) continue;
            
            rowsIdxAux[step] = rowIdx; // no retorno, nesse momento se muda do row e col usando um step maior (primeira mudança: step 4, row 3 col 4)
            colsIdxAux[step] = colIdx;

            *sum += arr[rowIdx * SIZE + colIdx];

            minSum(arr, rowsIdxAux, colsIdxAux, step + 1, sum);

            *sum -= arr[rowIdx * SIZE + colIdx];
            rowsIdxAux[step] = -1;
            colsIdxAux[step] = -1;
        }
    }
}

void copyToPath(int* rowsIdxAux, int* colsIdxAux){
    for(int i = 0; i < SIZE; i++){
        finalRowIdx[i] = rowsIdxAux[i];
    }
    for(int i = 0; i < SIZE; i++){
        finalColIdx[i] = colsIdxAux[i];
    }
}

void printPath(int* finalRowIdx, int* finalColIdx){
    for(int i = 0; i < SIZE; i++){
        printf("(%d, %d) ", finalRowIdx[i], finalColIdx[i]);
    }
}
