#include <iostream>
using namespace std;

struct x {
    int data;
    x* back;   
    x* next;    
};

// Lab 08
// TODO: реализуйте решение по заданию в labs/lab08_pointers_arrays/README.md
//
// Рекомендация по выводу:
// - без лишнего текста
// - числа через пробел
// - если несколько строк — в фиксированном порядке
int main() {
    //+ Упражнение 1: объяснить использование типов/переменных в коде (без ввода).
    // TODO: при необходимости вывести пояснения/результаты.

    //+ Упражнение 2: найти ошибки в коде (без ввода).
    // TODO: при необходимости вывести пояснения/результаты.

    // Упражнение 3: заполнить массивы (10 элементов) разными способами.
    // TODO: реализуйте 4 варианта заполнения и выведите 10 значений для каждого.

    const int N = 10;

    //1. Статический массив, индексная адресация
    int arr1[N];
    for (int i = 0; i < N; ++i) {
        arr1[i] = i * i; 
    }
    for (int i = 0; i < N; ++i) {
        cout << arr1[i] << " ";
    }
    cout << "\n";

    //2. статический массив, адресация  с помощью указателя (косвенная адресация);
    int arr2[N];
    int *ptr2 = arr2;
    for (int i = 0; i < N; ++i) {
        *(ptr2 + i) = i * i;
        //разыменование- значение  i * i присваевается элементу массива 
        // по адресу *(ptr2 + i)
    }
    for (int i = 0; i < N; ++i) {
        cout << *(arr2 + i) << " ";
    }
    cout << "\n";

    //3. динамический массив, индексная адресация;
    int *dArr1;
    //объявление динамического массива=
    //объявление указателя массива на тип элементов массива
    dArr = new int[N];
    //определение- выделение памяти 
    for (int i = 0; i < N; i++) {
        dArr1[i] = i * i;
    }
    for (int i = 0; i < N; i++) {
        cout << dArr1[i] << " ";
    }
    cout << "\n";
    delete [] dArr1;
    //освобождение памяти



    // Упражнение 4: линейный самоадресуемый список из 10 элементов.
    // TODO: сформируйте список и выведите элементы по порядку.

    x* head = nullptr; x* tail = nullptr;

    for (int i = 0; i < 10; ++i) {
        x* xi = new x();
        xi->data = i;
        xi->next = nullptr;
        xi->back = nullptr;

        if (head == nullptr) {
            head = xi;
            tail = xi;
        }
        else {
            tail->next = xi;
            xi->back = tail;
            tail =xi;
        }
    }

    x* current = head;
    cout << "Элементы двусвязного списка: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout <<endl;

    current = head;
    while (current != nullptr) {
        x* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
