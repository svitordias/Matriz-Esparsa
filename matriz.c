#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
    }
    return root;
}

int main() {
    int numRows, numCols, data;
    Node* root = NULL;

    printf("Digite o número de linhas desejado: ");
    scanf("%d", &numRows);

    printf("Digite o número de colunas desejado: ");
    scanf("%d", &numCols);

    int matrix[numRows][numCols];
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matrix[i][j] = 0;
        }
    }

    printf("Digite os valores da matriz:\n");
    for (int i = 1; i <= numRows; i++) {
        for (int j = 1; j <= numCols; j++) {
            printf("Valor da posição (%d, %d): ", i, j);
            scanf("%d", &data);
            matrix[i - 1][j - 1] = data;
            root = insertNode(root, data);
        }
    }

    printf("\nMatriz:\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}