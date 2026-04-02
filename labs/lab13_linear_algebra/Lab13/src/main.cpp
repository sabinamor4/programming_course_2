//#include <iostream>
//#include <cmath>
//#include <cstdio>
//using namespace std;
//
//// Lab 13
//// TODO: реализуйте решение по заданию в labs/lab13_linear_algebra/README.md
////
//// Рекомендация по выводу:
//// - без лишнего текста
//// - числа через пробел
//// - если несколько строк — в фиксированном порядке
////asadasdasd
//double eps = 0.000001;
//int SystemOfLinearEquations(int M, int n, double** A, double*X) {
//    int i,j,v,k;
//    double z=0,c;
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
//    for (i = 0; i < M; ++i) {
//        for (j = 0; j < n+1; ++j) {
//            cout << A[i][j] << ' ';
//        }
//        cout << endl;
//    }
//
//   
//    //i используется для вычитания из строки k
//    for (i = n - 1; i >= 1; --i) {
//        //у Костюка не правильно т.к k < i - 1 пропускает решение одной строки  k - (i - 1)
//        for (k = 0; k <= i-1; ++k) {
//            if (abs(A[i][i]) < eps) return 0;
//            c = A[k][i] / A[i][i];
//            A[k][n] -= c * A[i][n];
//            A[k][i] = 0;
//            }
//        }
//    
//
//
//    cout << endl;
//    for (i = 0; i <M; ++i) {
//        for (j = 0; j < n+1; ++j) {
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
//int main() {
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
//
//    delete[] A;
//    delete[] X;
//}




//
//working
//
//#include <iostream>
//#include <cmath>
//#include <cstdio>
//#include <iomanip>
//#include <algorithm>
//
//using namespace std;
//
//int SystemOfLinearEquations(int M, int n, double** A, double* X) {
//    double eps = 1e-9;
//    int pivot_row = 0;
//    for (int j = 0; j < n && pivot_row < M; ++j) {
//        int max_row = pivot_row;
//        for (int i = pivot_row + 1; i < M; ++i) {
//            if (abs(A[i][j]) > abs(A[max_row][j])) {
//                max_row = i;
//            }
//        }
//
//        if (abs(A[max_row][j]) < eps) {
//            continue;
//        }
//
//        if (pivot_row != max_row) {
//            swap(A[pivot_row], A[max_row]);
//        }
//
//        double pivot_element = A[pivot_row][j];
//        for (int k = j; k <= n; ++k) {
//            A[pivot_row][k] /= pivot_element;
//        }
//
//        for (int i = 0; i < M; ++i) {
//            if (i != pivot_row) {
//                double factor = A[i][j];
//                for (int k = j; k <= n; ++k) {
//                    A[i][k] -= factor * A[pivot_row][k];
//                }
//            }
//        }
//        pivot_row++;
//    }
//
//    int rank = 0;
//    for (int i = 0; i < M; ++i) {
//        bool non_zero_row = false;
//        for (int j = 0; j < n; ++j) {
//            if (abs(A[i][j]) > eps) {
//                non_zero_row = true;
//                break;
//            }
//        }
//        if (non_zero_row) {
//            rank++;
//        }
//        else {
//            if (abs(A[i][n]) > eps) {
//                return 0;
//            }
//        }
//    }
//
//    if (rank < n) {
//        return 0;
//    }
//
//    for (int i = n - 1; i >= 0; --i) {
//        if (abs(A[i][i]) < eps) {
//            return 0;
//        }
//        X[i] = A[i][n] / A[i][i];
//    }
//
//    return 1;
//}
//
//int main() {
//    int i, j, g, n, M;
//    double** A, * X;
//
//    cout << fixed << setprecision(9);
//
//    if (!(cin >> M >> n)) {
//        cerr << "Error reading system dimensions (M N)." << endl;
//        return 1;
//    }
//
//    X = new double[n];
//    A = new double* [M];
//    for (i = 0; i < M; ++i) {
//        A[i] = new double[n + 1];
//    }
//
//    for (i = 0; i < M; ++i) {
//        for (j = 0; j <= n; ++j) {
//            if (scanf_s("%lf", &A[i][j]) != 1) {
//                cerr << "Error reading matrix coefficients." << endl;
//                for (int row = 0; row < i; ++row) delete[] A[row];
//                delete[] A;
//                delete[] X;
//                return 1;
//            }
//        }
//    }
//
//    g = SystemOfLinearEquations(M, n, A, X);
//
//    if (g) {
//        for (i = 0; i < n; ++i) {
//            printf("%8.4f ", X[i]);
//        }
//        printf("\n");
//    }
//    else {
//        printf("Inconsistent system\n");
//    }
//
//    for (int i = 0; i < M; ++i) {
//        delete[] A[i];
//    }
//    delete[] A;
//    delete[] X;
//
//    return 0;
//}


//Общее решение
//double eps = 0.000001;
//int SystemOfLinearEquations(int m, int n, double** A, double* X) {
//    int i, j, v, k, r, *L,u,p;
//    L = new int* [n];
//    double z, c;
//    for (i = 0; i < n; i++) L[i] = i;
//    i = 0;
//    if (n < m) r = n; else r = m;
//    while (i<r){
//        v = i; u = i;
//        for (j = i; j < m; ++j)
//            for (k = i; k < n; ++k)
//                if (abs(A[j][k]) > abs(A[v][u])) {
//                    v = j; u = k;
//                }
//        if (abs(A[v][u]) < eps) r = i;
//        else {
//            if (v != i)
//                for (j = i; j <= n; ++j)
//                    z = A[i][j]; A[i][j] = A[v][j]; A[v][j] = z;
//            if (u != i) {
//                for (k = 0; k > m; k++) {
//                    z = A[k][i]; A[k][i] = A[k][u]; A[k][u] = z;
//                }
//                p = L[i]; L[i] = L[u]; L[u] = p;
//            }
//            c = A[i][i];
//            for (j = i; j <= n + 1; j++) A[i][j] /= c;
//            for (k = 0; k < m; k++)
//                if (k != i) {
//                    c = A[k][i];
//                    for (j = i; j <= n; j++) A[k][j] -= c * A[i][j];
//                }
//            i++;
//        }
//    }
//    i = r;
//    while (i < m && abs(A[i][n]) < eps) i++;
//    if (i < m) return 0;
//    else if (r == n) {
//        for (j = 0; j < n; j++) X[L[j]] = A[j][n];
//    }
//    else{
//        for (j = 0; j < r; j++){
//            X[L[j]] = A[j][n];
//            for (k = r; k < n; k++)
//                X[L[j]] -= A[j][k] * X[L[k]];
//        }
//    }
//    return 1;
//}
//
//int main() {
//    int i, j, g, n, M;
//    double** A, * X;
//    cin >> M;
//    cin >> n;
//    X = new double[n];
//    A = new double* [M];
//    for (i = 0; i < M; ++i) {
//        A[i] = new double[n + 1];
//        for (j = 0; j <= n; ++j) scanf_s("%lf", &A[i][j]);
//    }
//    g = SystemOfLinearEquations(M, n, A, X);
//    if (g) {
//        for (i = 0; i < n; ++i) printf("%8.3lf", X[i]);
//        printf("\n");
//    }
//    else printf("Inconsistent system\n");
// 
// 
// 
// 
//1 working with file:
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

void gaussianJordan(double** matrix, int rows, int cols) {
    int pivot_row = 0;
    for (int j = 0; j < cols - 1 && pivot_row < rows; ++j) {
        int max_row = pivot_row;
        for (int i = pivot_row + 1; i < rows; ++i) {
            if (abs(matrix[i][j]) > abs(matrix[max_row][j])) {
                max_row = i;
            }
        }

        if (matrix[max_row][j] == 0) {
            continue;
        }

        if (pivot_row != max_row) {
            swap(matrix[pivot_row], matrix[max_row]);
        }

        double pivot_element = matrix[pivot_row][j];
        for (int k = j; k < cols; ++k) {
            matrix[pivot_row][k] /= pivot_element;
        }

        for (int i = 0; i < rows; ++i) {
            if (i != pivot_row) {
                double factor = matrix[i][j];
                for (int k = j; k < cols; ++k) {
                    matrix[i][k] -= factor * matrix[pivot_row][k];
                }
            }
        }

        pivot_row++;
    }
}

int main() {

    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    if (!infile.is_open()) {
        cerr << "Ошибка открытия входного файла input.txt" << endl;
        return 1;
    }

    if (!outfile.is_open()) {
        cerr << "Ошибка открытия выходного файла output.txt" << endl;
        return 1;
    }

    int m, n;
    infile >> m >> n;
    double** matrix = new double* [m];

    for (int i = 0; i < m; ++i) {
        matrix[i] = new double[n + 1];
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= n; ++j) {
            infile >> matrix[i][j];
        }
    }

    gaussianJordan(matrix, m, n + 1);
    outfile << "Матрица системы после приведения к ступенчатому виду (метод Гаусса-Жордана):\n\n";
    outfile << fixed << setprecision(4);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= n; ++j) {
            outfile << setw(10) << matrix[i][j] << " ";
        }

        outfile << "\n";
    }

    for (int i = 0; i < m; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;
    infile.close();
    outfile.close();

    cout << "Обработка завершена. Результат записан в output.txt" << endl;
    return 0;
}