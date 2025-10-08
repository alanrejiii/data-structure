#include<stdio.h>
#define MAX 100

void readMatrix(int mat[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);
}

void printMatrix(int mat[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void convertToTuple(int mat[MAX][MAX], int r, int c, int tuple[MAX][3]) {
    int k = 1;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (mat[i][j] != 0) {
                tuple[k][0] = i;
                tuple[k][1] = j;
                tuple[k][2] = mat[i][j];
                k++;
            }
    tuple[0][0] = r;
    tuple[0][1] = c;
    tuple[0][2] = k - 1;
}

void printTuple(int tuple[MAX][3]) {
    int n = tuple[0][2] + 1;
    for (int i = 0; i < n; i++)
        printf("%d %d %d\n", tuple[i][0], tuple[i][1], tuple[i][2]);
}

void addTuples(int t1[MAX][3], int t2[MAX][3], int tSum[MAX][3]) {
    int r1 = t1[0][0], c1 = t1[0][1];
    int n1 = t1[0][2], n2 = t2[0][2];
    int i = 1, j = 1, k = 1;

    tSum[0][0] = r1;
    tSum[0][1] = c1;

    while (i <= n1 && j <= n2) {
        if (t1[i][0] < t2[j][0] || (t1[i][0] == t2[j][0] && t1[i][1] < t2[j][1])) {
            tSum[k][0] = t1[i][0];
            tSum[k][1] = t1[i][1];
            tSum[k][2] = t1[i][2];
            i++;
        } else if (t2[j][0] < t1[i][0] || (t1[i][0] == t2[j][0] && t2[j][1] < t1[i][1])) {
            tSum[k][0] = t2[j][0];
            tSum[k][1] = t2[j][1];
            tSum[k][2] = t2[j][2];
            j++;
        } else {
            tSum[k][0] = t1[i][0];
            tSum[k][1] = t1[i][1];
            tSum[k][2] = t1[i][2] + t2[j][2];
            i++;
            j++;
        }
        k++;
    }

    while (i <= n1) {
        tSum[k][0] = t1[i][0];
        tSum[k][1] = t1[i][1];
        tSum[k][2] = t1[i][2];
        i++;
        k++;
    }

    while (j <= n2) {
        tSum[k][0] = t2[j][0];
        tSum[k][1] = t2[j][1];
        tSum[k][2] = t2[j][2];
        j++;
        k++;
    }

    tSum[0][2] = k - 1;
}

void tupleToMatrix(int tuple[MAX][3], int mat[MAX][MAX]) {
    int r = tuple[0][0], c = tuple[0][1];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            mat[i][j] = 0;
    for (int i = 1; i <= tuple[0][2]; i++)
        mat[tuple[i][0]][tuple[i][1]] = tuple[i][2];
}

void transposeTuple(int t[MAX][3], int tT[MAX][3]) {
    int rows = t[0][0], cols = t[0][1], num = t[0][2];
    tT[0][0] = cols;
    tT[0][1] = rows;
    tT[0][2] = num;

    int k = 1;
    for (int col = 0; col < cols; col++)
        for (int i = 1; i <= num; i++)
            if (t[i][1] == col) {
                tT[k][0] = t[i][1];
                tT[k][1] = t[i][0];
                tT[k][2] = t[i][2];
                k++;
            }
}

int main() {
    int r, c;
    int mat1[MAX][MAX], mat2[MAX][MAX];
    int t1[MAX][3], t2[MAX][3], tSum[MAX][3], tTrans[MAX][3];
    int sumMat[MAX][MAX], transMat[MAX][MAX];

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix A (%d x %d):\n", r, c);
    readMatrix(mat1, r, c);
    printf("Enter matrix B (%d x %d):\n", r, c);
    readMatrix(mat2, r, c);

    convertToTuple(mat1, r, c, t1);
    convertToTuple(mat2, r, c, t2);

    printf("\nMatrix A (Sparse Form):\n");
    printMatrix(mat1, r, c);
    printf("Matrix A (Tuple Form):\n");
    printTuple(t1);

    printf("\nMatrix B (Sparse Form):\n");
    printMatrix(mat2, r, c);
    printf("Matrix B (Tuple Form):\n");
    printTuple(t2);

    addTuples(t1, t2, tSum);
    tupleToMatrix(tSum, sumMat);

    printf("\nSum Matrix (Sparse Form):\n");
    printMatrix(sumMat, r, c);
    printf("Sum Matrix (Tuple Form):\n");
    printTuple(tSum);

    transposeTuple(tSum, tTrans);
    tupleToMatrix(tTrans, transMat);

    printf("\nTranspose of Sum (Sparse Form):\n");
    printMatrix(transMat, tTrans[0][0], tTrans[0][1]);
    printf("Transpose of Sum (Tuple Form):\n");
    printTuple(tTrans);

    return 0;
}


    





	
