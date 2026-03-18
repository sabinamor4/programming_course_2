#include <iostream>

// Lab 12
// TODO: реализуйте решение по заданию в labs/lab12_combinatorics/README.md
//
// Рекомендация по выводу:
// - без лишнего текста
// - числа через пробел
// - если несколько строк — в фиксированном порядке.

//1
//презентация, поясняющая работу
//алгоритма генерации перестановок 
//мощность 3,
//123
//132
//213
//procedure per(k:integer);
//var i : integer;
//begin
//for i: = 1 to n do
//if R[i] = 0 then begin
//P[k] : = i; R[i]: = 1;
//if k = n then ВЫВОД
//else per(k + 1);
//R[i]: = 0
//end
//end;
//for i: = 1 to n do R[i] : = 0;
//per(1);


2
генерация перестановок ферзей
int n, P[21], H[21], R[41], L[41];/*глобальные описания */
void queen(int k)      /*функция генерации перестановок */
{
    int i, j;
    for (i = 1; i <= n; i++)
        if (H[i] == 0 && R[i - k + 21] == 0 && L[i + k] == 0)
        {
            P[k] = i; H[i] = 1; R[i - k + 21] = 1; L[i + k] = 1;
            if (k == n)        /*вывод сгенерированной перестановки*/
            {
                for (j = 1; j <= n; j++)printf("%2d ", P[j]);
                printf("\n");
            }
            else queen(k + 1);
            H[i] = 0; R[i - k + 21] = 0; L[i + k] = 0;
        }
}
int main() {
    // TODO
    int i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) H[i] = 0;
    for (i = 2; i <= n + n; i++)
    {
        R[i] = 0; L[i] = 0;
    }
    queen(1);
}
