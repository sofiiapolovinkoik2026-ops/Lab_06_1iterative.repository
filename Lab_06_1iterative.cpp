#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. Функція для створення масиву випадковими числами від Low до High
void createArray(int* p, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        p[i] = Low + rand() % (High - Low + 1);
    }
}

// 2. Функція для гарного форматованого виведення масиву
void printArray(const int* p, const int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(5) << p[i];
    }
    cout << endl;
}

// Перевірка критерію: число додатне (p[i] > 0) АБО парний індекс (i % 2 == 0)
bool criterion(int value, int index) {
    return (value > 0) || (index % 2 == 0);
}

// 3. Функція для обчислення кількості елементів за критерієм
int countElements(const int* p, const int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (criterion(p[i], i)) {
            count++;
        }
    }
    return count;
}

// 4. Функція для обчислення суми елементів за критерієм
int sumElements(const int* p, const int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (criterion(p[i], i)) {
            sum += p[i];
        }
    }
    return sum;
}

// 5. Функція для заміни потрібних елементів нулями
void modifyArray(int* p, const int size) {
    for (int i = 0; i < size; i++) {
        if (criterion(p[i], i)) {
            p[i] = 0;
        }
    }
}

int main() {
    srand((unsigned)time(0)); // Ініціалізація генератора випадкових чисел

    const int SIZE = 24;
    int p[SIZE];

    int Low = -10;
    int High = 14;

    // 1. Формуємо масив
    createArray(p, SIZE, Low, High);

    // 2. Виводимо початковий масив
    cout << "Pochatkovyi masiv:" << endl;
    printArray(p, SIZE);

    // 3. Обчислюємо кількість та суму
    int count = countElements(p, SIZE);
    int sum = sumElements(p, SIZE);

    // 4. Замінюємо елементи нулями
    modifyArray(p, SIZE);

    // 5. Виводимо результати
    cout << "\nKilkist elementiv: " << count << endl;
    cout << "Suma elementiv:    " << sum << endl;

    // 6. Виводимо модифікований масив
    cout << "\nModifikovanyi masiv:" << endl;
    printArray(p, SIZE);

    return 0;
}