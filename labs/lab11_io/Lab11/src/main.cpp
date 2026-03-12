

// Lab 11
// TODO: реализуйте решение по заданию в labs/lab11_io/README.md
//
// Рекомендация по выводу:
// - без лишнего текста
// - числа через пробел
// - если несколько строк — в фиксированном порядке

//II.1.ВАРИАНТЫ ВВОДА - ВЫВОДА
// 
//   Операторы и функции:
//+ cin, cout;
//+ scanf(), printf();
//+ gets(), puts();
//fopen(), fclose();
//fscanf(), fprintf()
//read(), write()
//feof();

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main() {
    string name;

    int a;
    cout << "Input A integer number: ";
    cin >> a;
    cout << "We scored in your number A: "<< a<<endl;

    int b;
    cout << "Please input your authentication password: ";
    scanf_s("%d", &b);
    printf_s("\nWe don't have a dataset...\nSorry, we will cheak it in future and save your new password: %d\n", b);
    char ch;
    ch = getc(stdin);
    cout << ch;
    puts("hello");

    //FILE* fin, * fout;
    //int e;
    //if ((fout = fopen(filename, "w")) != NULL) {
    //    for (int i = 0; i < 6; i++) {
    //        if ((e = fprintf(fout, "%d\n", i)) > 0)
    //            printf("%d", i+1);

    //fscanf();
    //read();
    //write();
    //feof();

    //fclose(filename);
}

//II.2.	КОРНЕВЫЕ СЛОВА
// 
//трудоемкость n**2 - последовательно проверять каждое с каждым;
//трудоемкость n*k ("i*j") - цикл сразу запоминать информацию 
//    является ли i-ое слово корневым для j-того и наоборот;
// Kак организовать структуру хранения информации ?
//
//Task :
//    Слов в наборе не более 50, самое длинное слово содержит 25 букв;
// Kорневым слово - совпадает с началом одного или нескольких других слов из набора;
// Входные данные : file;
// Результаты: 2 file:
//    1) самое длинное корневое слово и все слова, для которых оно является корневым, 
//    или слово NO, если корневых слов нет;
//    2) самое важное слово и количество слов, для которых оно является корневым,
//    или слово NO, если корневых слов нет;

//открытие файла, 
//считывание в цикле 
//    сравнение 
//    запоминание (вывод в созданные файлы, 
//закрытие
// 
//структура с 1 или 2 мерным массивом для запоминания корневого слова 

//#include <iostream>
//using namespace std;
//
//int main() {
//        FILE* F0, * F1, * F2; int n, i, k, s;
//
//        char* S0 = "in.txt", * S1 = "out.txt", * S2 = "out.txt";
//        if ((F0 = fopen(S0, "r")) == NULL ||
//            (F1 = fopen(S1, "w")) == NULL ||
//            (F2 = fopen(S2, "w")) == NULL) puts("Ошибка!\n");
//        else
//        {
//            цикл
//            n = 0; s = 0;
//            while (feof(F0) == 0)
//            {
//                fscanf(F0, "%s", &k); s += k; n++;
//            }
//            fprintf(F2, "%d   %8.3f\n", n);
//        }
//
//    fclose(F0); fclose(F1); fclose(F2);
//    return 0;
//}
