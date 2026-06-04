
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
// 
//+ scanf(), printf() - форматированный консольный ввод/вывод. 
// могут вводить/выводить данные в различных форматах и управлять ими
// 
//+ gets(), puts(); - консольные ввод/вывод. только строки, нельзя преобразовать формат.
// занимает меньше места и работает быстрее (scanf(), printf())
// нет способа указать, где находится граница массива
// (fgets() позволяет указать максимальную длину-сохраняет символ новой строки)
// 
//+ fopen(), fclose() - возвращает дескриптор файла для управления внешними ресурсами в процессе работы
// 
//+ fscanf(), fprintf() - буферизированный ввод/вывод. 
// как scanf(), printf() только работает с дисковыми файлами, а не консолью
// 
// Пр. где важна скорость и прямой контроль, а не удобство форматирования
// (системное программирование, работа с сетями, устройствами)
//read(), write() - низкоуровневые системные функции ввода/вывода
// для чтения байтов из файла в буфер памяти и записи из буфера в файл
// работают с файловыми дескрипторами, а не с объектами потоков
// обеспечивают высокую производительность, но требуют ручного управления буферами
// напрямую взаимодействует с операционной системой,
// минует буферизацию библиотек с++
// 
// 
//+ feof();

//trunc- у вещественных переменных отбрасывает дробную часть не округляя
// оставляет только целую часть и формат int
//-удаляет содержимое существующего файла, размер становится нулевым

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
#include <fcntl.h>
#include <unistd.h>
//#include "../../../../../../../../../../Program Files/Microsoft Visual Studio/18/Community/VC/Tools/MSVC/14.44.35207/include/__msvc_ostream.hpp"
using namespace std;
int main() {
    system("chcp 65001 > nul");
    string name;

    int a;
    cout << "Input A integer number: ";
    cin >> a;
    cout << "We scored in your number A: "<< a<<endl;

    int b;
    cout << "Please input your authentication password: ";
    scanf_s("%d", &b);
    printf_s("\nWe don't have a dataset...\nSorry, we will cheak it in future and save your new password: %d\n", b);
    char ch[5]={'e','r','y','j','f'};
    char* str1 = new char[50];
    //gets(str1);
    cout << ch;
    puts("hello");

    //create object of class with name "fout" 
    // and merge/conjuction with name in "";
    ofstream fout("first.txt", ios::trunc);
    fout << "We are plenty\nAnd can do all in the world if believe in it";
    fout.close();

    ifstream fin("first.txt");
    if (!fin.is_open()) cout << "File cannot open\n";
    else {
        char c;
        while (fin.get(c)) cout << c;
    }


    FILE *fp;
    int c=4,e;
    if ((int fp = fopen("first", "w")) != NULL) {
        for (int i = 0; i < 6; i++) {
            e = fscanf(fp, "%d\n", i);
        }
        int fp = fopen("first", "w");
        string text = "Solo";
        write(fp, text, 4);
        read(fp, text, 2);
    }
    while (!feof(fp)) {
        fprintf(fp, "%d", c);
    }
    fclose(fp);
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
//        file* f0, * f1, * f2; int n, i, k, s;
//
//        char* s0 = "in.txt", * s1 = "out.txt", * s2 = "out.txt";
//        if ((f0 = fopen(s0, "r")) == null ||
//            (f1 = fopen(s1, "w")) == null ||
//            (f2 = fopen(s2, "w")) == null) puts("ошибка!\n");
//        else
//        {
//            цикл
//            n = 0; s = 0;
//            while (feof(f0) == 0)
//            {
//                fscanf(f0, "%s", &k); s += k; n++;
//            }
//            fprintf(f2, "%d   %8.3f\n", n);
//        }
//
//    fclose(f0); fclose(f1); fclose(f2);
//    return 0;
//}
