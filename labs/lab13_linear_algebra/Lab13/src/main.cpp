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
//double eps = 0.000001;
//int SystemOfLinearEquations(int M, int n, double** A, double*X) {
//    int i,j,v,k;
//    double z,c;
//    for (i = 0; i < M - 1; ++i) {
//        v = i;
//        for (j = i + 1; j < M; ++j)
//            if (abs(A[j][i]) > abs(A[v][i])) v = j;
//        if (abs(A[v][i]) < eps) return 0;
//        else {
//            if (v!=i)
//                for (j = i; j <= n; ++j)
//                    z = A[i][j]; A[i][j] = A[v][j]; A[v][j] = z;
//            for (k = i + 1; k < M; ++k) {
//                c = A[k][i] / A[i][i];
//                for (j = i; j <= n; ++j) 
//                    A[k][j] -= c * A[i][j];
//            }
//        }
//    }
//
//    cout << endl;
//    for (i = 0; i < n; ++i) {
//        for (j = 0; j < n; ++j) {
//            cout << A[i][j] << ' ';
//        }
//        cout << endl;
//    }
//
//   
//    for (i = M - 1; i >= 1; --i) {
//        for (k = 0; k < i - 1; ++k) {
//            c = A[k][i] / A[i][i];
//            A[k][n] -= c * A[i][n];
//            A[k][i] = 0;
//        }
//    }
//
//    cout << endl;
//    for (i = 0; i < n; ++i) {
//        for (j = 0; j < n; ++j) {
//            cout << A[i][j] << ' ';
//        }
//        cout << endl;
//    }
//    cout << endl;
//
//    for (i = 0; i < n; ++i) {
//        X[i] = A[i][n] / A[i][i];
//    }
//    return 1;
//}
//
//void main() {
//    int i, j, g, n, M;
//    double** A, * X;
//    cin>>M;
//    cin>>n;
//    X = new double[n];
//    A = new double*[M];
//    for (i = 0; i < M; ++i) {
//        A[i] = new double[n + 1];
//        for (j = 0; j <= n; ++j) scanf_s("%lf", &A[i][j]);
//    }
//    g=SystemOfLinearEquations(M,n,A,X);
//    if (g) {
//        for (i = 0; i < n; ++i) printf("%8.3lf", X[i]);
//        printf("\n");
//    }
//    else printf("Inconsistent system\n");
//}

//Общее решение
double eps = 0.000001;
int SystemOfLinearEquations(int m, int n, double** A, double* X) {
    int i, j, v, k, r, *L,u,p;
    //L = new int* [n];
    double z, c;
    for (i = 0; i < n; i++) L[i] = i;
    i = 0;
    if (n < m) r = n; else r = m;
    while (i<r){
        v = i; u = i;
        for (j = i; j < m; ++j)
            for (k = i; k < n; ++k)
                if (abs(A[j][k]) > abs(A[v][u])) {
                    v = j; u = k;
                }
        if (abs(A[v][u]) < eps) r = i;
        else {
            if (v != i)
                for (j = i; j <= n; ++j)
                    z = A[i][j]; A[i][j] = A[v][j]; A[v][j] = z;
            if (u != i) {
                for (k = 0; k > m; k++) {
                    z = A[k][i]; A[k][i] = A[k][u]; A[k][u] = z;
                }
                p = L[i]; L[i] = L[u]; L[u] = p;
            }
            c = A[i][i];
            for (j = i; j <= n + 1; j++) A[i][j] /= c;
            for (k = 0; k < m; k++)
                if (k != i) {
                    c = A[k][i];
                    for (j = i; j <= n; j++) A[k][j] -= c * A[i][j];
                }
            i++;
        }
    }
    i = r;
    while (i < m && abs(A[i][n]) < eps) i++;
    if (i < m) return 0;
    else if (r == n) {
        for (j = 0; j < n; j++) X[L[j]] = A[j][n];
    }
    else{
        for (j = 0; j < r; j++)        {
            X[L[j]] = A[j][n];
            for (k = r; k < n; k++)
                X[L[j]] -= A[j][k] * X[L[k]];
        }
    }
    return 1;
}

int main() {
    int i, j, g, n, M;
    double** A, * X;
    cin >> M;
    cin >> n;
    X = new double[n];
    A = new double* [M];
    for (i = 0; i < M; ++i) {
        A[i] = new double[n + 1];
        for (j = 0; j <= n; ++j) scanf_s("%lf", &A[i][j]);
    }
    g = SystemOfLinearEquations(M, n, A, X);
    if (g) {
        for (i = 0; i < n; ++i) printf("%8.3lf", X[i]);
        printf("\n");
    }
    else printf("Inconsistent system\n");
}
