#include <iostream>
#include <stdio.h>
using namespace std;

// Lab 13
// TODO: реализуйте решение по заданию в labs/lab13_linear_algebra/README.md
//
// Рекомендация по выводу:
// - без лишнего текста
// - числа через пробел
// - если несколько строк — в фиксированном порядке
//asadasdasd
double eps = 0.000001;
int SystemOfLinearEquations(int M, int n, double** A, double*X) {
    int i,j,v,k;
    double z,c;
    for (i = 0; i < M - 1; ++i) {
        v = i;
        for (j = i + 1; j < M; ++j)
            if (abs(A[j][i]) > abs(A[v][i])) v = j;
        if (abs(A[v][i]) < eps) return 0;
        else {
            if (v!=i)
                for (j = i; j <= n; ++j)
                    z = A[i][j]; A[i][j] = A[v][j]; A[v][j] = z;
            for (k = i + 1; k < M; ++k) {
                c = A[k][i] / A[i][i];
                for (j = i; j <= n; ++j) 
                    A[k][j] -= c * A[i][j];
            }
        }
    }

    cout << endl;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }

   
    for (i = M - 1; i >= 1; --i) {
        for (k = 0; k < i - 1; ++k) {
            c = A[k][i] / A[i][i];
            A[k][n] -= c * A[i][n];
            A[k][i] = 0;
        }
    }

    cout << endl;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for (i = 0; i < n; ++i) {
        X[i] = A[i][n] / A[i][i];
    }
    return 1;
}

void main() {
    int i, j, g, n, M;
    double** A, * X;
    cin>>M;
    cin>>n;
    X = new double[n];
    A = new double*[M];
    for (i = 0; i < M; ++i) {
        A[i] = new double[n + 1];
        for (j = 0; j <= n; ++j) scanf_s("%lf", &A[i][j]);
    }
    g=SystemOfLinearEquations(M,n,A,X);
    if (g) {
        for (i = 0; i < n; ++i) printf("%8.3lf", X[i]);
        printf("\n");
    }
    else printf("Inconsistent system\n");
}
