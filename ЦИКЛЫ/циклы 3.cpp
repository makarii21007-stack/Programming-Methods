#include <iostream>
#include <clocale>
#include <cmath>

int main() {
    setlocale(LC_ALL, "Russian");

    int x1, y1, x2, y2;

    std::cout << "Введите x1 y1: ";
    std::cin >> x1 >> y1;

    std::cout << "Введите x2 y2: ";
    std::cin >> x2 >> y2;


    if (x1 < 1 || x1 > 8 || y1 < 1 || y1 > 8 ||
        x2 < 1 || x2 > 8 || y2 < 1 || y2 > 8) {
        std::cout << "Ошибка: координаты должны быть от 1 до 8" << std::endl;
        return 0;
    }


    if (std::abs(x2 - x1) <= 1 &&
        std::abs(y2 - y1) <= 1 &&
        !(x1 == x2 && y1 == y2)) {
        std::cout << "Король может попасть за один ход" << std::endl;
    }
    else {
        std::cout << "Король не может попасть за один ход" << std::endl;
    }

    return 0;
}
