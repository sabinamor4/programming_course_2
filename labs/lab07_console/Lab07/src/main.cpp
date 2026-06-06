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
//
//#include <iostream>
//#include <stdio.h>
////#include <clocale>
//#include <math.h>
//#include <stdlib.h>
//using namespace std;
//
//
//void task1() {
//    double x_start;
//    cout << "Введите начальную точку интервала (0, 4]: ";
//    cin >> x_start;
//
//    //if (x_start <= 0 || x_start > 4) {
//    //    printf_s("Ошибка: начальная точка должна быть в интервале (0, 4]\n");
//    //    return;
//    //}
//
//    double step = (4.0 - x_start) / 9.0;
//
//    cout << "y = sin(x)/x:" << endl;
//
//    for (int i = 0, doulbe x = x_start; i < 10; i++, x += step)
//    {
//        double y = sin(x) / x;
//        cout << i + 1 << ")" << " x " << x << endl << "   y " << y << endl;
//    }
//}
//
//
//void task2() {
//    long long MAX;
//    printf_s("MAX: ");
//    scanf_s("%lld", &MAX);
//
//    //if (MAX <= 0) {
//    //    printf_s("Ошибка: MAX должно быть положительным числом\n");
//    //    return;
//    //}
//
//    long long a = 1, b = 1, S = 0;
//    int n = 0;
//
//
//    if (a <= MAX)
//    {
//        S += a;
//        n++;
//
//        if (b <= MAX && S <= MAX)
//        {
//            S += b;
//            n++;
//        }
//    }
//
//    while (S <= MAX)
//    {
//        long long next = a + b;
//        if (next > MAX) break;
//
//        if (S + next > MAX) break;
//
//        S += next;
//        n++;
//
//        a = b;
//        b = next;
//    }
//    printf_s("(N) = %d\n", n);
//    printf_s("(S) = %lld\n\n", S);
//}
//
//void task3() {
//    double credit_amount, rate;
//    int months;
//
//    printf_s("Сумма (руб.) - ");
//    scanf_s("%lf", &credit_amount);
//    printf_s("Срок (мес.) - ");
//    scanf_s("%d", &months);
//    printf_s("Процентная ставка (годовых) - ");
//    scanf_s("%lf", &rate);
//
//    //if (credit_amount <= 0 months <= 0 rate <= 0) {
//    //    printf_s("Ошибка: все значения должны быть положительными\n");
//    //    return;
//    //}
//
//    double monthly_rate = rate / 12 / 100;
//    double monthly_payment = credit_amount / months;
//    double remaining_debt = credit_amount, high = 0;
//
//    printf_s("-----------------------------------------------------------\n");
//    printf_s("    Долг   Процент   Платеж\n");
//    printf_s("-----------------------------------------------------------\n");
//
//    for (int month = 1; month <= months; month++)
//    {
//        double interest = remaining_debt * monthly_rate;
//        double total_payment = monthly_payment + interest;
//
//        printf_s("  %2d    %10.2f       %8.2f       %7.2f\n",
//            month, remaining_debt, interest, total_payment);
//        high += interest;
//
//        remaining_debt -= monthly_payment;
//    }
//    printf_s("-----------------------------------------------------------\n");
//    printf_s("Всего процентов: %.2lf\n", high);
//}
//
//int main()
//{
//    setlocale(LC_ALL, "Russian");
//    int choice;
//
//    do {
//        printf_s("1 - Вычисление значений функции\n 2 - Числа Фибоначчи\n 3 - Кредитные платежи\n Выберите задание (1-3): ");
//        scanf_s("%d", &choice);
//
//        switch (choice) {
//        case 1:
//            task1(); break;
//        case 2:
//            task2(); break;
//        case 3:
//            task3(); break;
//            //default:
//            //    printf_s("Ошибка: неверный выбор. Пожалуйста, выберите 0-3.\n");
//        }
//    } while (choice != 0);
//}
