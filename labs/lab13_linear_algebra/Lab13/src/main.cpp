#include <iostream>
#include <stdio.h>

// Lab 13
// TODO: реализуйте решение по заданию в labs/lab13_linear_algebra/README.md
//
// Рекомендация по выводу:
// - без лишнего текста
// - числа через пробел
// - если несколько строк — в фиксированном порядке
//asadasdasd
double eps = 0.000001;
int SystemOfLinearEquations(int n, float** A, float *X) {
    int i,j,v,k;
    float z,c ;
    for (i = 0; i < n - 1; ++i) {
        v = i;
        for (j = i + 1; j < n; ++j)
            if (abs(A[j][i]) > abs(A[v][i])) v = j;
        if (abs(A[v][i]) < eps) return 0;
        else {
            for (j = i; j <= n; ++j) {
                z = A[i][j]; A[i][j] = A[v][j]; A[v][j] = z;
            }
            for (k = i + 1; k < n; ++k) {
                c = A[k][i] / A[i][i];
                for (j = i; j <= n; ++j) {
                    A[k][j] -= c * A[i][j];
                }
            }
        }
    }
    for (i = n - 1; i >= 1; --i) {
        for (k = 0; k < i - 1; ++k) {
            c = A[k][i] / A[i][i];
            A[k][n] -= c * A[i][n];
            A[k][i] = 0;
        }
    }
    for (i = 0; i < n; ++i) {
        X[i] = A[i][n] / A[i][i];
    }
    return 1;
}

int main() {
    int i, j, g, n; 
    float** A, * X;
    scanf_s("%d", &n);
    X = new float[n];
    A = new float*[n];
    for (i = 0; i < n; ++i) {
        A[i] = new float[n + 1];
        for (j = 0; j <= n; ++j) scanf_s("%f", &A[i][j]);
    }
    g=SystemOfLinearEquations(n,A,X);
    if (g) {
        for (i = 0; i < n; ++i) printf("%8.3f", X[i]);
        printf("\n");
    }
    else printf("ERROR\n");
}
