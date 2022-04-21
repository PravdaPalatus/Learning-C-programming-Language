//Code to find a path of successive numbers throughout all elements of the matrix
//Valid directions: up, down, left and right. Skipping numbers or walking diagonally is forbidden
#include <stdio.h>
#define M 5

void printMatrix(int arr[M][M]);
//void printArr(int* arr, int lenght);
int findRow(int arr[M][M], int number);
int findCol(int arr[M][M], int number);
void sortArray(int* arr, int* sortedArr, int lenght);
int findPath(int arr[M][M], int* sortedArr, int* arrRows, int* arrCols);


int main(){

    int arr[M][M];
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            printf("Enter the element (%d, %d): ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");
    printf("We have the following matrix:\n");
    printMatrix(arr);

    //int arr[M][M] = {{1,2,3,4,5},{10,9,8,7,6},{11,12,13,14,15},{20,19,18,17,16},{21,22,23,24,25}};

    //printMatrix(arr);

    //int row;
    //row = findRow(arr, 5);
    //printf("The row is: %d\n", row);
//
    //int col;
    //col = findCol(arr, 5);
    //printf("The column is: %d\n", col);

    printf("\n");
    int sortedArr[25];
    sortArray(*arr, sortedArr, 25);
    //printArr(sortedArr, 25);

    int arrRows[25];
    int arrCols[25];
    int path = findPath(arr, sortedArr, arrRows, arrCols);
    
    if(path == 25){
        printf("The path is:\n");
        for(int i = 0; i < 25; i++){
            printf("(%d, %d)", arrRows[i], arrCols[i]);
        }
        printf("\nIt was done in %d steps.\n", path);
    } else{
        printf("Sorry! There is no path throughout all elements of the matrix according the game's rules. It was done only %d steps\n", path);
    }

    return 0;
}

void printMatrix(int arr[M][M]){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

}

int findRow(int arr[M][M], int number){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            if(arr[i][j] == number) return i;
        }
    }
    return -1;
}

int findCol(int arr[M][M], int number){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            if(arr[i][j] == number) return j;
        }
    }
    return -1;
}

void sortArray(int* arr, int* sortedArr, int lenght){
    for(int i = 0; i < lenght; i++) sortedArr[i] = arr[i];
    int acc = 1;
    while(acc < lenght){
        for(int j = acc; j < lenght; j++){
            if(sortedArr[acc - 1] > sortedArr[j]){
                int aux = sortedArr[acc - 1];
                sortedArr[acc - 1] = sortedArr[j];
                sortedArr[j] = aux;
            }
        }
        acc++;
    }
}

//void printArr(int* arr, int lenght){
//    for(int i = 0; i < lenght; i++){
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}

int findPath(int arr[M][M], int* sortedArr, int* arrRows, int* arrCols){
    int nextnumber, rowIdx, colIdx, rowNext, colNext;
    static int steps;
    for(int i = 0; i < 25; i++){
        if(i == 0){
            nextnumber = sortedArr[i];
            rowIdx = findRow(arr, nextnumber);
            colIdx = findCol(arr, nextnumber);
            arrRows[i] = rowIdx;
            arrCols[i] = colIdx;
            steps++;
        }
        else{
            nextnumber = sortedArr[i];
            rowNext = findRow(arr, nextnumber);
            colNext = findCol(arr, nextnumber);
            if((rowNext == rowIdx + 1 && colNext == colIdx) || (rowNext == rowIdx - 1 && colNext == colIdx) || (colNext == colIdx + 1 && rowNext == rowIdx) || (colNext == colIdx - 1 && rowNext == rowIdx)){
                rowIdx = rowNext;
                colIdx = colNext;
                arrRows[i] = rowIdx;
                arrCols[i] = colIdx;
                steps++;
            }
            else{
                return steps;
            }
        }
    }
    return steps;
}
