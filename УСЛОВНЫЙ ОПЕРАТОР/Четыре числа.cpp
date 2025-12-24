#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int a, b, c, d;
    cout << "Введите четыре числа:" << "\n";
    cin >> a >> b >> c >> d;

    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    if (a > c) {
        int temp = a;
        a = c;
        c = temp;
    }
    if (a > d) {
        int temp = a;
        a = d;
        d = temp;
    }
    if (b > c) {
        int temp = b;
        b = c;
        c = temp;
    }
    if (b > d) {
        int temp = b;
        b = d;
        d = temp;
    }
    if (c > d) {
        int temp = c;
        c = d;
        d = temp;
    }

    cout << "Числа по возрастанию: " << a << " " << b << " " << c << " " << d << endl;
}
