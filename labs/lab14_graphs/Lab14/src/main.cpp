#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

// Lab 14
// TODO: реализуйте решение по заданию в labs/lab14_graphs/README.md
//
// Рекомендация по выводу:
// - без лишнего текста
// - числа через пробел
// - если несколько строк — в фиксированном порядке

int main() {
    ifstream infile("ingraf.txt");
    ofstream outfile("outgraf.txt");
    if (!infile.is_open()) {
        outfile << "Ошибка открытия входного файла input.txt" << endl;
        return 1;
    }        
    if (!outfile.is_open()) {
        outfile << "Ошибка открытия выходного файла output.txt" << endl;
        return 1;
    }

    int** M, i, j, n, m, k;

    infile >> n;
    M = new int* [n];
    for (i = 0; i < n; i++) {
        M[i] = new int[n];
        for (j = 0; j < n; j++) M[i][j] = 0;
    }
    infile >> m;
    for (k = 0; k < m; k++) {
        infile >> i >> j;
        M[i-1][j-1] = 1; M[j-1][i-1] = 1;
    }
    printf("\n");
    printf("матрицa смежности: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) { printf("%d ", M[i][j]); }
        printf("\n");
    }

    //int* v1, * v2, * D, * S, * L, * U;
    //int i, n, m, k;
    //scanf("%d%d", &n, &m);
    //v1 = new int[m]; v2 = new int[m];
    //for (i = 0; i < m; i++)
    //    scanf("%d%d", &v1[i], &v2[i]);
    //D = new int[m + m]; S = new int[n];
    //L = new int[n]; U = new int[n];
    //for (j = 0; j < n; j++) L[j] = 0;//обнуление длин списков 
    //for (i = 0; i < m; i++)
    //    //вычисление длин списков 
    //{
    //    L[v1[i]]++; L[v2[i]]++;
    //}
    //S[0] = 0; //вычисление начальных индексов на списки в массиве D 
    //for (j = 1; j < n; j++) S[j] = S[j - 1] + L[j - 1];
    //for (j = 0; j < n; j++) U[j] = S[j];
    ////дублирование начальных индексов       
    //for (i = 0; i < m; i++)  //распределение смежных вершин 
    //    //по спискам массива D 
    //{
    //    k = v1[i]; D[U[k]] = v2[i]; U[k]++;
    //    k = v2[i]; D[U[k]] = v1[i]; U[k]++;
    //}
}
