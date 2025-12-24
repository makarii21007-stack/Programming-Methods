#include <iostream>
#include <clocale>
#include <cmath>


long long factorial(int n) {
    long long f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

double computeY(double x, double eps = 1e-3) {
    if (std::abs(x) > 1.0) {
        return NAN;
    }

    double y = x;
    double term;
    int n = 2;

    do {
        term = pow(-1, n - 1) * pow(2, n - 1) / factorial(n - 1) * pow(x, n);
        y += term;
        n++;
    } while (std::abs(term) >= eps);

    return y;
}

int main() {
    setlocale(LC_ALL, "Russian");

    double x = -1.0;
    double step = 0.1;
    double eps = 1e-3;

    std::cout << "x\t\ty" << std::endl;

    while (x <= 1.0 + 1e-6) {
        double y = computeY(x, eps);
        std::cout << x << "\t" << y << std::endl;
        x += step;
    }


    double yTest = computeY(0.5, eps);
    std::cout << "\nКонтрольная точка x=0.5: y = " << yTest << std::endl;

    return 0;
}
