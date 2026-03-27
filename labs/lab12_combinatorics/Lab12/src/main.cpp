#include <iostream>
#include <cstdio>
using namespace std;

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
//в массиве Р[n] содержатся элементы н-р 1 2 3, 1 3 2, 2 1 3...
//массив R[n] вспомогательный со значениями 0/1
//
//#include <iostream>
//using namespace std;
//
//void per(int k, int n, int *P, int *R) 
//{
    //	for (int i = 1; i < n; i++) 
    //  {
    //		if (R[i] == 0) 
    //      {
    //			P[k] = i; R[i] = 1;
    //			if (k == n) return;
    //			else per(k + 1, n, P, R);
    //			R[i] = 0;
    //		}
    //	}
    //	return;
//}
//
//
//int main() {
//	int n = 3, *R= new int [n+1], *P = new int[n+1];
//	for (int i = 1; i <= n; i++)	
// {
//		R[i] = 0;
//		P[i] = 0;
//	}
//
//	per(1,n,P,R);
//	delete[] P;
//	delete[] R;
//	return 0;
//}


//2
//генерация перестановок ферзей
//2 способа:
//
//1) в лоб с использованием матрицы
int n, cous=0;
int P[21][21] = {};
bool flag;/*глобальные описания*/
//P = Position (перестановка, выводимая на экран)

void queenArr(int k)
{
    int i, j;
    if (k > n)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++) printf("%2d ", P[i][j]);
            printf("\n");
        }
        printf("\n");
        cous ++;
    }
    
    for (i = 1; i <= n; i++)
    {
        flag=true;
        for (j = 1; j < k; j++)
        {
            if (P[i][j] == 1 || (P[i + (k - j)][j] == 1 && (i + (k - j) <= n)))
            {
                flag = false;
                break;
            }

            if (P[i - (k - j)][j] == 1 && (i - (k - j) >= 1))
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            P[i][k] = 1;
            queenArr(k + 1);
            P[i][k] = 0;
        }
    }
}



//2)
int Pos[21], H[21], R[41], L[41];/*глобальные описания*/
/*P = Position (перестановка, выводимая на экран)
H=Horizontal (0/1 занят ли горизонт на этой строке)
R=Right Diagonal (занята ли диагональ на диагонали идущая в правый верхний угол)
L=Left Diagonal (занята ли диагональ на диагонали идущая в левый верхний угол)
*/
void queen(int k)      
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        if (H[i] == 0 && R[i - k + 21] == 0 && L[i + k] == 0)
        {
            Pos[k] = i; H[i] = 1; R[i - k + 21] = 1; L[i + k] = 1;
            if (k == n)      
            {
                for (j = 1; j <= n; j++) printf("%2d ", Pos[j]);
                printf("\n");
                cous ++;
            }
            else queen(k + 1);
            H[i] = 0; R[i - k + 21] = 0; L[i + k] = 0;
        }
    }

}

int main()
{
    int i;
    scanf_s("%d", &n);
    for (i = 1; i <= n; i++) H[i] = 0;
    for (i = 2; i <= n + n; i++)
    {
        R[i] = 0; L[i] = 0;
    }
    queen(1);
    cout << cous<< endl;

    queenArr(1);
    cout << "Количество решений: " << cous << endl;
}
