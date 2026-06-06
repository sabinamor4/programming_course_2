#include <iostream>
#include <math.h>
#include <windows.h>
using namespace std;

//#include <bits/stdc++.h>

int main()
{
    //float a = 0, b = 4, x, d = (b - a) / 9;
    //double  radians, f;
    //system("chcp 65001 > nul");
    //cout << "введите начальную точку интервала возможных значений аргумента " << endl
    //    << "x" << " " << "f" << endl;
    ////cin >> x;
    //for (int i = 0; i < 10; i++)
    //{
    //    x = a + i * d;
    //    radians = x * 3.1415926535 / 180;
    //    f=sinl(radians) / x;
    //    cout << x << " " << f << endl;// << a << b << d;
    //}

    system("chcp 65001 > nul");
    int S = 0, N = 1, n, n0 = 0, n1 = 1, MAX;
    cout << "введите MAX: ";
    cin >> MAX;

    for (int i = 1; n0 <= MAX; i++)
    {
        n = n0 + n1; n0 = n1; n1 = n;
        if (n0 <= MAX)
        {
            cout << n0 << endl;
            N = 1 + i;
            S = S + n0;
        }
    }
    cout << N << " " << S;

    //system("chcp 65001 > nul");
    //float S, months, y, payment, mpayment, allper;

    //printf("%u %4s %f", );
    //scanf("% f", &S);
    //printf(" %4 %f", );
    //scanf("% f", &months);
    //printf(" %4 %f", );
    //scanf("% f", &y);

    //printf(" %4 %f", );
    //printf("  Долг Процент Платеж");
    //printf(" %4 %f", );

    //for (int i = 0; i <= months; i++)
    //{
    //    mpayment = S * y / (months * 100);
    //    payment = S - mpayment;
    //    printf(i \t S, mpayment, payment);
    //    S = S - payment;
    //    allper= allper+ mpayment;
    //}

    //printf(" %f /n", allper);


}