#include <stdio.h>
#include <stdlib.h>

// Função que coloca a matriz na tela
void freeTree(int** matrix, int numRows) {
    for (int i = 0; i < numRows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int numRows, numCols, data;
    int** matrix;

    // Usuário define o tamnho da matriz
    printf("Digite o número de linhas desejado: ");
    scanf("%d", &numRows);

    printf("Digite o número de colunas desejado: ");
    scanf("%d", &numCols);

    // Aloca a matriz
    matrix = (int**)malloc(numRows * sizeof(int*));
    if (matrix == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        return 1;
    }
    for (int i = 0; i < numRows; i++) {
        matrix[i] = (int*)malloc(numCols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Erro: falha na alocação de memória.\n");
            freeTree(matrix, i);
            return 1;
        }
    }

    printf("Digite os valores da matriz:\n");
    for (int i = 1; i <= numRows; i++) {
        for (int j = 1; j <= numCols; j++) {
            printf("Valor da posição (%d, %d): ", i, j);
            scanf("%d", &data);
            matrix[i - 1][j - 1] = data;
        }
    }

    printf("\nMatriz:\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    freeTree(matrix, numRows);

    return 0;
}