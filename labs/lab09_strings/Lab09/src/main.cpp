#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Lab 09
// TODO: реализуйте решение по заданию в labs/lab09_strings/README.md
//
// Рекомендация по выводу:
// - без лишнего текста
// - числа через пробел
// - если несколько строк — в фиксированном порядке
int main() {
    // Упражнения 1–3: демонстрация/анализ строковых функций (без ввода).
    // TODO: добавьте примеры и вывод результатов.

    // Упражнение 4: ввод количества слов и самих слов.
    //int word_count = 0;
    //if (!(cin >> word_count)) return 0;

    //vector<string> words;
    //words.reserve(word_count);
    //for (int i = 0; i < word_count; ++i) {
    //    string word;
    //    cin >> word;
    //    words.push_back(word);
    //}


    int n;
    cout << "Введите количество слов (max 20): ";
    cin >> n;
    if (n > 20) n = 20;

    char words[20][11];

    cout << "Введите слова:" << endl;
    for (int i = 0; i < n; ++i) cin >> words[i];

    cout << "Слова с четными номерами (2, 4, ...):" << endl;
    for (int i = 1; i < n; i += 2) cout << words[i] << endl;


    // TODO: выведите слова с четными номерами (2, 4, 6, ...), по одному в строке.


    return 0;

    //cout << "Char represented by \\101: " << '\101' << endl;
}
