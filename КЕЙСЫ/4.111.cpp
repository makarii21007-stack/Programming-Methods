#include <iostream>
#include <locale>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int d, k;
    cout << "Введите номер дня недели для 1 января (d: 1-Пн, 2-Вт, ..., 7-Вс): ";
    if ( d < 1 || d > 7) {
        cout << "Данные введены неверно (d должно быть от 1 до 7).";
        return 0;
    }

    cout << "Введите номер дня года k (1..365): ";
    if ( k < 1 || k > 365) {
        cout << "Данные введены неверно (k должно быть от 1 до 365).";
        return 0;
    }

    string days[] = { "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" };

    int index = ((d - 1) + (k - 1)) % 7;

    cout << "k-й день невисокосного года: " << days[index] << "\n";
    return 0;
}
