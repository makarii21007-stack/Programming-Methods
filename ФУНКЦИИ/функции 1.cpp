#include <iostream>
#include <clocale>


bool isValidN(int n) {
    return n > 0;
}


int arithmeticProgression(int a, int d, int n) {
    return a + (n - 1) * d;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int a, d, n;

    std::cout << "Введите первый член прогрессии a: ";
    std::cin >> a;

    std::cout << "Введите разность прогрессии d: ";
    std::cin >> d;

    std::cout << "Введите номер члена n: ";
    std::cin >> n;


    if (!isValidN(n)) {
        std::cout << "Ошибка: номер члена должен быть натуральным числом" << std::endl;
        return 0;
    }

    int result = arithmeticProgression(a, d, n);

    std::cout << "n-й член арифметической прогрессии: "
        << result << std::endl;

    return 0;
}
