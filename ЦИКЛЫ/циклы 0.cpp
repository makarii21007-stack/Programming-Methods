#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>

int main() {
    setlocale(LC_ALL, "Russian");
    int N;
    std::cout << "Введите N: ";
    std::cin >> N;

    srand(time(0));

    int success = 0;

    for (int i = 0; i < N; i++) {

        double a = (double)rand() / RAND_MAX;
        double b = (double)rand() / RAND_MAX;
        double c = (double)rand() / RAND_MAX;


        if (a + b > c && a + c > b && b + c > a) {
            success++;
        }
    }

    double probability = (double)success / N;

    std::cout << "Успешных треугольников: " << success << std::endl;
    std::cout << "Вероятность: " << probability << std::endl;

    return 0;
}
