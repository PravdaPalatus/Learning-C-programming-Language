//CODE to: build a original square matrix (5x5)
//transpose of a matrix
//Matrix of the multiplication between the original matrix and the transposed matrix 
#include <stdio.h>
#define M 5
#define N 5

void printMatrix(int arr[M][N]);
void transposeMatrix(int arr[M][N], int arrt[M][N]);
void multiplyingMatrix(int *arr, int *arrt, int result[M][N], int lenght);

int main(){

    int arr[M][N];
    int arrt[M][N];
    int result[M][N] = {};

    //int arr[M][N] = {{1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}, {-1, 0, -1, 2, 3}, {9, -8, 7, 6, 5}, {1, 1, 1, 1, 1}};
    //int arrt[M][N];
    //int result[M][N] = {};

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            printf("Enter the element (%d, %d):", i, j);
            scanf("%d", &arr[i][j]);
        }

    }
    printf("The original matrix:\n");
    printMatrix(arr);
    printf("\n");
    
    printf("The transpose of the original matrix:\n");
    transposeMatrix(arr, arrt);
    printMatrix(arrt);
    printf("\n");

    int len = M * N;
    printf("The multiplying matrix:\n");
    multiplyingMatrix(*arr, *arrt, result, len);
    printMatrix(result);
    printf("\n");
    
    return 0;
}

void printMatrix(int arr[M][N]){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int arr[M][N], int arrt[M][N]){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            arrt[i][j] = arr[j][i];
        }
    }
}

//void multiplyingMatrix(int *arr, int *arrt, int result[M][N], int lenght){
//    int rowresult, colresult = 0;
//    while(rowresult < 5){
//        for(int i = 0; i < lenght;){
//            for(int j = 0; j < N; j++){
//                result[rowresult][colresult] = arr[i] * arrt[j] + arr[i + 1] * arrt[j + (1*N)] + arr[i + 2] * arrt[j + (2*N)] +  arr[i + 3] * arrt[j + (3*N)] +  arr[i + 4] * arrt[j + (4*N)];
//                colresult++;
//            }
//            i = i + (N);
//            rowresult++;
//            colresult = 0;
//        }
//    }
//}

void multiplyingMatrix(int *arr, int *arrt, int result[M][N], int lenght){
    int rowresult, colresult = 0;
    while(rowresult < 5){
        for(int i = 0; i < lenght;){
            for(int j = 0; j < N; j++){
                for(int x = 0; x < N;x++){
                    result[rowresult][colresult] = result[rowresult][colresult] + (arr[i + x] * arrt[j + (x*N)]);
                }
                colresult++;
            }
            i = i + N;
            rowresult++;
            colresult = 0;
        }
    }
}