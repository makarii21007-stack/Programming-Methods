#include <iostream>
#include <clocale>
#include <cmath>


const double PI = 3.141592653589793;


bool isValidAngle(double alpha) {
    return std::isfinite(alpha);
}


double toRadians(double degrees) {
    return degrees * PI / 180.0;
}


void rotatePoint(double& x, double& y, double alphaRad) {
    double newX = x * cos(alphaRad) - y * sin(alphaRad);
    double newY = x * sin(alphaRad) + y * cos(alphaRad);
    x = newX;
    y = newY;
}

int main() {
    setlocale(LC_ALL, "Russian");

    double x1, y1, x2, y2, x3, y3;
    double alpha;

    std::cout << "Введите координаты первой вершины (x1 y1): ";
    std::cin >> x1 >> y1;

    std::cout << "Введите координаты второй вершины (x2 y2): ";
    std::cin >> x2 >> y2;

    std::cout << "Введите координаты третьей вершины (x3 y3): ";
    std::cin >> x3 >> y3;

    std::cout << "Введите угол поворота (в градусах): ";
    std::cin >> alpha;

    if (!isValidAngle(alpha)) {
        std::cout << "Ошибка: некорректное значение угла" << std::endl;
        return 0;
    }

    double alphaRad = toRadians(alpha);

    rotatePoint(x1, y1, alphaRad);
    rotatePoint(x2, y2, alphaRad);
    rotatePoint(x3, y3, alphaRad);

    std::cout << "Новые координаты треугольника:" << std::endl;
    std::cout << "A(" << x1 << ", " << y1 << ")" << std::endl;
    std::cout << "B(" << x2 << ", " << y2 << ")" << std::endl;
    std::cout << "C(" << x3 << ", " << y3 << ")" << std::endl;

    return 0;
}
