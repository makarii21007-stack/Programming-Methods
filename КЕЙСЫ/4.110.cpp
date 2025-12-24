#include <iostream>
using namespace std;
int main()
{
    int m, n;
    setlocale(LC_ALL, "Russian");
    cout << "Введите номер масти и номер карты" << "\n";
    cin >> m >> n;
    switch (n) {
    case 6:
        cout << "Шестерка ";
        break;
    case 7:
        cout << "Семерка ";
        break;
    case 8:
        cout << "Восьмерка ";
        break;
    case 9:
        cout << "Девятка ";
        break;
    case 10:
        cout << "Десятка ";
        break;
    case 11:
        cout << "Валет ";
        break;
    case 12:
        cout << "Дама ";
        break;
    case 13:
        cout << "Король ";
        break;
    case 14:
        cout << "Туз ";
        break;
    default:
        cout << "Номер карты введен не правильно ";

    }
    switch (m) {
    case 1:
        cout << "пик";
        break;
    case 2:
        cout << "треф";
        break;
    case 3:
        cout << "бубен";
        break;
    case 4:
        cout << "черви";
        break;
    default:
        cout << "Номер масти введен не правильно";
    }


}