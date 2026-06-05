#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

// Lab 14
// TODO: реализуйте решение по заданию в labs/lab14_graphs/README.md
//
// Рекомендация по выводу:
// - без лишнего текста
// - числа через пробел
// - если несколько строк — в фиксированном порядке
// 
int working_with_files(int n,ifstream &infile, ofstream &outfile) {
    system("chcp 65001 > nul");
    string infilename, outfilename;

    if (n == 1) {
        infilename = "infile1.txt";
        outfilename = "outfile1.txt";
    }
    else if (n == 2) {
        infilename = "infile1.txt";
        outfilename = "outfile2.txt";
    }
    else {
        infilename = "outfile2.txt";
        outfilename = "outfile3.txt";
    }

    infile.open(infilename);
    outfile.open(outfilename);

    if (!infile.is_open()) {
        printf("Ошибка открытия выходного файла %s \n", infilename.c_str());
        //outfile << "Ошибка открытия входного файла %s \n", infilename.c_str();
        return 1;
    }
    if (!outfile.is_open()) {
        printf("Ошибка открытия выходного файла %s \n", outfilename.c_str());
        //outfile << "Ошибка открытия выходного файла %s \n", outfilename.c_str();
        return 1;
    }
    return 0;
}

void adjacency_matrix() {
    int** M, i, j, n, m, k;
    ifstream infile;
    ofstream outfile;

    working_with_files(1,infile,outfile);

    infile >> n;
    M = new int* [n];
    for (i = 0; i < n; i++) {
        M[i] = new int[n];
        for (j = 0; j < n; j++) M[i][j] = 0;
    }
    infile >> m;
    for (k = 0; k < m; k++) {
        infile >> i >> j;
        M[i - 1][j - 1] = 1; M[j - 1][i - 1] = 1;
    }

    printf("матрицa смежности: \n");
    outfile << "матрицa смежности: \n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", M[i][j]);
            outfile << M[i][j] << ' ';
        }
        printf("\n");
        outfile << "\n";
    }

    for (i = 0; i < n; i++) delete[] M[i];
    delete[] M;
    infile.close();
    outfile.close();
}

void adjacency_list() {
    int* v1, * v2, * D, * S, * L, * U;
    int i, j,n, m,k;

    ifstream infile;
    ofstream outfile;

    working_with_files(2, infile, outfile);

    infile>> n >>m;

    v1 = new int[m]; v2 = new int[m];
    for (i = 0; i < m; i++){
        infile >> v1[i]>> v2[i];
    }
    D = new int[m + m]; S = new int[n];
    L = new int[n]; U = new int[n];

    for (j = 0; j < n; j++) L[j] = 0;
    for (i = 0; i < m; i++){
        L[v1[i]-1]++; L[v2[i]-1]++;
    }

    S[0] = 0;
    for (j = 1; j < n; j++) S[j] = S[j - 1] + L[j - 1];
    for (j = 0; j < n; j++) U[j] = S[j];
    for (i = 0; i < m; i++) {
        k = v1[i]-1; D[U[k]] = v2[i]; U[k]++;
        k = v2[i]-1; D[U[k]] = v1[i]; U[k]++;
    }
    printf("\n массив номеров смежных вершин: \n");
    outfile << n<< "\n массив номеров смежных вершин: \n";

    for (i = 0; i < n; i++) {
        printf("%d: ", i + 1);
        outfile << i + 1 << ": ";
        for (j = S[i]; j < S[i] + L[i]; j++) {
            printf("%d ", D[j]);
            outfile << D[j] << " ";
        }
        printf("\n");
        outfile << "\n";
    }

    delete[] v1;
    delete[] v2;
    delete[] D;
    delete[] S;
    delete[] L;
    delete[] U;

    infile.close();
    outfile.close();

}

void edge_list() {
    ifstream infile;
    ofstream outfile;
    int n, m, i, j, k, count;
    int* D, * S, * L;

    working_with_files(3, infile, outfile);

    infile >> n;

    // Пропускаем заголовок "массив номеров смежных вершин:"
    string header;
    getline(infile, header);
    getline(infile, header);

    // Пропускаем двоеточие
    char colon;
    infile >> colon;

    // Выделяем память
    S = new int[n];
    L = new int[n];
    int* tempD = new int[n * n]; // временный массив для хранения смежных вершин

    // Читаем списки смежности
    for (i = 0; i < n; i++) {
        S[i] = 0;
        L[i] = 0;
        int vertex;
        infile >> vertex; // номер вершины (должен быть i+1)
        infile >> colon;
        int val;
        int pos = 0;
        int temp[100]; // временный массив для хранения смежных вершин одной вершины

        while (infile.peek() != '\n' && infile.peek() != EOF) {
            infile >> val;
            if (val > 0) {
                temp[pos++] = val;
                L[i]++;
            }
        }

        // Сохраняем смежные вершины во временный массив D
        for (j = 0; j < pos; j++) {
            tempD[S[i] + j] = temp[j];
        }
        if (i < n - 1) S[i + 1] = S[i] + L[i];
    }

    // Формируем массив D
    m = 0;
    for (i = 0; i < n; i++) m += L[i];
    m = m / 2; // так как каждое ребро учтено дважды

    D = new int[m * 2];
    int* D_ptr = D;

    // Формируем список ребер (без дублирования)
    printf("\n");
    printf("последовательность ребер: \n");
    outfile << "последовательность ребер: \n";
    outfile << n << " " << m << "\n";

    for (i = 0; i < n; i++) {
        for (j = 0; j < L[i]; j++) {
            int neighbor = tempD[S[i] + j];
            // Добавляем ребро только если i+1 < neighbor (избегаем дублирования)
            if (i + 1 < neighbor) {
                printf("%d %d\n", i + 1, neighbor);
                outfile << i + 1 << " " << neighbor << "\n";
                *D_ptr++ = i + 1;
                *D_ptr++ = neighbor;
            }
        }
    }

    delete[] D;
    delete[] S;
    delete[] L;
    delete[] tempD;

    infile.close();
    outfile.close();
}

int main() {
    adjacency_matrix();
    adjacency_list();
    edge_list();
}
