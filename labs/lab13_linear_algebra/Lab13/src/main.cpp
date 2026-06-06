#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
//#include <algorithm>
#include <cstdio>
using namespace std;
//
//// Lab 13
//// TODO: реализуйте решение по заданию в labs/lab13_linear_algebra/README.md
////
//// Рекомендация по выводу:
//// - без лишнего текста
//// - числа через пробел
//// - если несколько строк — в фиксированном порядке
////asadasdasd
 
double eps = 0.000001;
int SystemOfLinearEquations(int M, int n, double** A, double*X) {
    int i,j,v,k;
    double z=0,c;
    for (i = 0; i < M - 1; ++i) {
        v = i;
        for (j = i + 1; j < M; ++j)
            if (abs(A[j][i]) > abs(A[v][i])) v = j;
        if (abs(A[v][i]) < eps) return 0;
        else {
            if (v!=i)
                for (j = i; j <= n; ++j) {
                    z = A[i][j]; A[i][j] = A[v][j]; A[v][j] = z;
                }
            for (k = i + 1; k < M; ++k) {
                c = A[k][i] / A[i][i];
                for (j = i; j <= n; ++j) 
                    A[k][j] -= c * A[i][j];
            }
        }
    }

    cout << endl;
    for (i = 0; i < M; ++i) {
        for (j = 0; j < n+1; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
   
    //i используется для вычитания из строки k строки i
    for (i = n - 1; i >= 1; --i) {
        //k < i - 1 пропускает решение одной строки  k - (i - 1)
        for (k = 0; k <= i-1; ++k) {
            if (abs(A[i][i]) < eps) return 0;
            c = A[k][i] / A[i][i];
            A[k][n] -= c * A[i][n];
            A[k][i] = 0;
        }
    
        
        cout << endl;
        for (int b = 0; b < M; ++b) {
            for (int j = 0; j < n + 1; ++j) {
                cout << A[b][j] << " ";
            }
            cout << endl;
        }
    }
 
    //cout << endl;
    //for (i = 0; i <M; ++i) {
    //    for (j = 0; j < n+1; ++j) {
    //        cout << A[i][j] << ' ';
    //    }
    //    cout << endl;
    //}
    //cout << endl;

    for (i = 0; i < n; ++i) {
        X[i] = A[i][n] / A[i][i];
    }
    return 1;
}
 

int main() {
    system("chcp 65001 > nul");
    int i, j, g, n, M;

    ifstream infile("input.txt");
    ofstream outfile("output.txt");//    
    if (!infile.is_open()) {
        outfile << "Ошибка открытия входного файла input.txt" << endl;
        return 1;
    }    
    if (!outfile.is_open()) {
        outfile << "Ошибка открытия выходного файла output.txt" << endl;
        return 1;
    }

    infile >> M >> n;

    double** A, * X;
    X = new double[n];
    A = new double* [M];
    
    for (i = 0; i < M; ++i) {
        A[i] = new double[n + 1];
        for (j = 0; j <= n; ++j) infile >> A[i][j];
    }
    g=SystemOfLinearEquations(M,n,A,X);

    outfile << "Матрица системы после приведения к ступенчатому виду (метод Гаусса-Жордана):\n\n";
    outfile << fixed << setprecision(4);
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j <= n; ++j) {
            outfile << setw(10) << A[i][j] << " ";
        }
    
        outfile << "\n";
    }
    
    if (g) {
        for (i = 0; i < n; ++i) {
            outfile << X[i]<<' ';
        }
        outfile << "\n";
    }
    else {
        outfile << "Inconsistent system\n";
    }
    
    for (int i = 0; i < M; ++i) {
        delete[] A[i];
    }
    cout << "Обработка завершена. Результат записан в output.txt" << endl;

    //cout << endl;
    //for (i = 0; i < M; ++i) {
    //    for (j = 0; j < n + 1; ++j) {
    //        cout << A[i][j] << ' ';
    //    }
    //    cout << endl;
    //}
    //cout << endl;

    delete[] A;
    delete[] X;

    infile.close();
    outfile.close();
}




////Общее решение и две прямые на плоскости
//#include <iostream>
//#include <fstream>
//#include <cstdlib>
//using namespace std;
//
//bool flag; int r, L[100];
//double eps = 0.000001;
//
//int SystemOfLinearEquations(int m, int n, double** A, double* X) {
//    int i, j, v, k, u, p;
//    //L = new int* [n];
//    double z, c;
//    for (i = 0; i < n; i++) L[i] = i;
//    i = 0;
//
//    if (n < m) r = n; 
//    else r = m;
//
//    while (i<r){
//        v = i; u = i;
//        for (j = i; j < m; ++j){
//            for (k = i; k < n; ++k){
//                if (abs(A[j][k]) > abs(A[v][u])) {
//                    v = j; u = k;
//                }
//            }
//        }
//        // перестановку как двух строк и двух столбцов
//        if (abs(A[v][u]) < eps) r = i;
//        else {
//            if (v != i) {
//                for (j = i; j <= n; ++j) {
//                    z = A[i][j]; A[i][j] = A[v][j]; A[v][j] = z;
//                }
//            }
//            if (u != i) {
//                for (k = 0; k < m; k++) {
//                    z = A[k][i]; A[k][i] = A[k][u]; A[k][u] = z;
//                }
//                p = L[i]; L[i] = L[u]; L[u] = p;
//            }
//            c = A[i][i];
//            for (j = i; j <= n + 1; j++) 
//            {
//                A[i][j] /= c;
//            }
//            for (k = 0; k < m; k++)
//            {
//                if (k != i) {
//                    c = A[k][i];
//                    for (j = i; j <= n; j++) A[k][j] -= c * A[i][j];
//                }
//            }
//            i++;
//        }
//    }
//
//
//    i = r;
//    while (i < m && abs(A[i][n]) < eps) i++;
//    //решение системы не существует
//    if (i < m) return 0;
//    //единственное решение r == n
//    else if (r == n) {
//        for (j = 0; j < n; j++) X[L[j]] = A[j][n];
//    }
//    // бесконечно много решений r < n
//    //L[j] ведущей в j - й строке.
//    else{
//        
//        //for free
//        for (k = r; k < n; k++) {
//            printf(" x%d", L[k] + 1);
//            if (k < n - 2) printf(", ");
//        }
//        if (n-r>1) printf(" are free\n");
//        else printf(" is free\n");
//
//        for (k = r; k < n; k++) {
//            printf("x%d ", L[k] + 1);
//            cin >> X[L[k]];
//        }
//
//        //for notfree with input free
//        for (j = 0; j < r; j++){
//            X[L[j]] = A[j][n];
//            for (k = r; k < n; k++) {
//                //b-koef free*free
//                X[L[j]] -= A[j][k] * X[L[k]];
//            }
//        }
//    }
//    return 1;
//}
//
////Общее решение
//int main() {
//    int i, j, g, n, M;
//    double** A, * X;
//    cin >> M;
//    cin >> n;
//    X = new double[n];
//    A = new double* [M];
//    for (i = 0; i < M; ++i){
//        A[i] = new double[n + 1];
//        for (j = 0; j <= n; ++j) scanf_s("%lf", &A[i][j]);
//    }
//    printf("\n\n");
//    g = SystemOfLinearEquations(M, n, A, X);
//    if (g) {
//        //n
//        for (i = 0; i < n; ++i) printf("%8.3lf ", X[i]);
//        printf("\n\n");
//    }
//    else printf("Inconsistent system\n");
//
//    printf("Запуск скрипта Python для рисования...\n");
//    int draw = system("python PythonDraw2Lines.py");
//    if (draw != 0) cerr << "Ошибка при выполнении скрипта!" << endl;
//}


//  Черновик попытки извлечения чисел из строки уравнения
//#include <sstream>
//#include <vector>
//#include <cctype>
//#include <string>
//
//using namespace std;
//
//// Функция для извлечения чисел из строки уравнения
//void parseEquation(const string& s, vector<double>& coeffs) {
//    coeffs.clear();
//    string temp = "";
//
//    for (int i = 0; i < s.size(); ++i) {
//        if (isdigit(s[i]) || s[i] == '-' || s[i] == '.') {
//            temp += s[i];
//        }
//        else {
//            if (!temp.empty()) {
//                try {
//                    coeffs.push_back(stod(temp));
//                }
//                catch (...) {}
//                temp = "";
//            }
//        }
//    }
//    if (!temp.empty()) {
//        try {
//            coeffs.push_back(stod(temp));
//        }
//        catch (...) {}
//    }
//}
//
////На плоскости заданы две прямые, найти координаты точки пересечения прямых:
//int main() {
//    int i, j, g, n, M;
//    double** A, * X;
//    n = 2; M = 2;
//    X = new double[n];
//    
//    
//    
//    //for (int i = 0; i < str.size(); ++i)
//    //    if (isdigit(str[i]) && (isdigit(str[i+1])==1)) // (isalpha(str[i + 1]) || ispunct(str[i + 1])))
//    //        A[i][n - (i + 1)]= str[i];
//    //    else s += tolower(str[i]);
//
//    //    s += toupper(str[i]);
//    //cout << s;
//
//    
//
//    string str;
//    vector<double> coeff;
//    cin.ignore();
//    getline(cin, str);
//
//    parseEquation(str, coeff);
//
//    A = new double* [M];
//    i = 0;
//    for (i = 0; i < n; ++i) {
//        A[i] = new double[n + 1];
//        printf("%8.3lf", coeff[i]);
//        for (int j = 0; j <= n; ++j) {
//            A[i][j] = coeff[i];
//        }
//    }
//    for (i = 0; i < n; ++i){
//        for (int j = 0; j <= n; ++j) printf("%8.3lf", A[i][j]);
//    }
//    printf("\n\n");
//
//    printf("\n\n");
//    g = SystemOfLinearEquations(M, n, A, X);
//    if (g) {
//        //n
//        for (i = 0; i < n; ++i) printf("%8.3lf", X[i]);
//        printf("\n\n");
//    }
//    else printf("Inconsistent system\n");
//}