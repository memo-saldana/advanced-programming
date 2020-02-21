//
// Author: José Guillermo Saldaña Cárdenas
// ID: A01039888
// Date: 18/02/2020
// Asks for 2 2x2 matrices and calculates its addition,
// substraction, and multiplication
#include <stdio.h>


void printMatrix(int matrix[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }  
}

void sumMatrices(int matrixA[2][2], int matrixB[2][2]) {
    int result[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
        
    }

    printMatrix(result);
}

void subtractMatrices(int matrixA[2][2], int matrixB[2][2]) {
    int result[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
        
    }

    printMatrix(result);
}

void multiplyMatrices(int matrixA[2][2], int matrixB[2][2]) {
    int result[2][2], sum;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            sum = 0;
            for (int k = 0; k < 2; k++) {
                sum += matrixA[i][k] * matrixB[k][j];
            }
            result[i][j] = sum;
        }  
    }
    
    printMatrix(result);
}


int main() {
    int matrixA[2][2], matrixB[2][2];

    printf("Input the values of the first matrix, one by one, rows first.\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d",&matrixA[i][j]);
        }
    }

    printf("Input the values of the second matrix, one by one, rows first.\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d",&matrixB[i][j]);
        }
    }

    sumMatrices(matrixA, matrixB);
    subtractMatrices(matrixA, matrixB);
    multiplyMatrices(matrixA, matrixB);

   return 0;
}