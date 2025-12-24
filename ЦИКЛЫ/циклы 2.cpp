#include <iostream>
#include <clocale>

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    std::cout << "Введите количество часов n: ";
    std::cin >> n;

    long long bacteria = 1;

    for (int i = 3; i <= n; i += 3) {
        bacteria *= 2;
    }

    std::cout << "Количество бактерий через "
        << n << " часов: "
        << bacteria << std::endl;

    return 0;
}
