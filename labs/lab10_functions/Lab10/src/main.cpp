//#include <iostream>
////#include <stdlib.h>
//using namespace std;

//// Lab 10
// II.2. УПРАЖНЕНИЕ 2 («Гармошка»). Задан упорядоченный целочисленный массив 
// длины N>>1000. Значения элементов массива находятся в числовом интервале [0, 17].
//
//А.Напишите функцию с параметрами, которая «упаковывает» данные, 
//т.е.размещает информацию о числах из массива, используя как можно меньше памяти.
//
//Б.Напишите функцию с параметрами, которая «распаковывает» данные, 
//т.е.по информации, полученной при выполнении задания А, восстанавливает исходное 
//состояние массива.

//// TODO: реализуйте решение по заданию в labs/lab10_functions/README.md
////
//// Рекомендация по выводу:
//// - без лишнего текста
//// - числа через пробел
//// - если несколько строк — в фиксированном порядке


////void sort(int b, int e, int* A, int* B)
////{
////    if (b < e)
////    {
////        int c = (b + e) / 2;
////        sort(b, c, A, B); sort(c + 1, e, A, B);
////        int i1 = b, i2 = c + 1, j = b;
////        while (i1 <= c && i2 <= e)
////            if (A[i1] <= A[i2]) 
////            {   
////                B[j] = A[i1]; i1++; j++; 
////            }
////            else 
////            { 
////                B[j] = A[i2]; i2++; j++; 
////            }
////        while (i1 <= c)
////        {   
////            B[j] = A[i1]; i1++; j++; 
////        }
////        while (i2 <= e) 
////        { 
////            B[j] = A[i2]; i2++; j++; 
////        }
////        for (j = b; j <= e; j++) A[j] = B[j];
////    }
////}

////int pack(int *A, int n)
////{
////    int m = 1, *C;
////    C = new int[n];
////    C[1] = A[1];
////    for (int i = 2; i < n; i++, m++)
////    {
////        if (C[m] < A[i])  C[m] = A[i];
////    }
////    for (int i = 0; i < n; i++) printf("%d ", C[i]);
////    printf("\n");
////    //C[1] = 6;
////    //return C[1];
////}

////int unpack()
////{
////
////}

//int main() 
//{
//    int n, * A, i;
//    cout << "input N>>1000 = ";
//    cin >> n;
//    A = new int[n]; 
//
//    //fill the array values with rand()
//    for (int i = 0; i < n; i++)
//    {
//        int k = rand() % 18;
//        if (i == 0) A[i] = k;
//        for (int i = 0; i < n && A[i] < k; i++);
//        for (int j = n; j > i; j--)
//        {
//            A[j] = A[j - 1];
//        }
//        A[i] = k;
//    }
//
//    //to cheak array values
//    for (i = 0; i < n; i++) printf("%d ", A[i]);
//    printf("\n");
//
//    //pack(A,n);
//    
//
//    
//    //cout << "arr = ";
//    //for (i = 0; i < n; i++) printf("%d ", [i]);
//    //cout << "pack = ";
//    //for (i = 0; i < n; i++) printf("%d ", [i]);
//    //unpack();
//}

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define r  18;

void pack(int* A, int N, int* key, int* count) {
    int* count = new int[r];

    // Подсчитываем количество повторений каждого числа
    for (int i = 0; i < N; i++) 
    {
        count[A[i]]++;
    }

    
}

int main() 
{
    system("chcp 65001 > nul");

    // key - массив для сжатия с уникальными значениями
    int* key = new int[ r ];
    for (int i = 0; i < r; i++) 
    {
        key[i] = i;
        cout << key[i] << " ";
    }
    cout << endl;

    // создание упорядоченного массива с элементами в диапазоне 0-17
    int n;
    cout << "введите n >> 1000: ";
    cin >> n;

    int* a = new int[n];
    int size = 0; // текущий размер заполненной части массива

    srand(time(0)); 
    // позволяет каждый раз без исключений получать новое значения

    for (int i = 0; i < n; i++) 
    {
        int k = 0 + rand() % r, x = 0;
               
        while (x < size && a[x] < k) 
        {
            x++;
        }

        for (int j = size; j > x; j--) 
        {
            a[j] = a[j - 1];
        }

        a[x] = k;
        size++;
    }
    cout << endl;

    // выводим элементов для проверки
    cout << "первые n элементов отсортированного массива:\n";
    for (int i = 0; i < n; i++) 
    {
        cout << a[i] << " ";
    }
    cout << endl;

    delete[] a;
    return 0;
}
