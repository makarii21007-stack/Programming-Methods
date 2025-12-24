#include <iostream>
#include <clocale>

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    std::cout << "Введите натуральное число: ";
    std::cin >> n;

    int original = n;
    int reversed = 0;

    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    if (original == reversed) {
        std::cout << "Число является палиндромом" << std::endl;
    }
    else {
        std::cout << "Число не является палиндромом" << std::endl;
    }

    return 0;
}
