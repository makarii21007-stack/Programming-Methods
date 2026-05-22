import math
import random
from abc import ABC, abstractmethod

# Родительский класс


class Shape(ABC):

    @abstractmethod
    def show(self):
        pass

    @abstractmethod
    def save(self, filename):
        pass

    def __del__(self):
        print("Треугольник удален")


# Класс Triangle


class Triangle(Shape):

    # Конструктор
    def __init__(self, ax, ay, bx, by, cx, cy):

        self.A = (ax, ay)
        self.B = (bx, by)
        self.C = (cx, cy)

    # Случайный треугольник
    @classmethod
    def random_triangle(cls):

        while True:

            t = cls(
                random.randint(0, 10),
                random.randint(0, 10),
                random.randint(0, 10),
                random.randint(0, 10),
                random.randint(0, 10),
                random.randint(0, 10),
            )

            if t.is_valid():
                return t

    # Чтение из файла
    @classmethod
    def from_file(cls, filename):

        with open(filename, "r") as f:
            data = list(map(float, f.read().split()))

        return cls(*data)

    # Вывод координат
    def show(self):

        print("A =", self.A)
        print("B =", self.B)
        print("C =", self.C)

    # Длины сторон
    def sides(self):

        a = math.dist(self.B, self.C)
        b = math.dist(self.A, self.C)
        c = math.dist(self.A, self.B)

        return a, b, c

    # Вывод сторон
    def show_full(self):

        self.show()

        a, b, c = self.sides()

        print("Стороны:", round(a, 2), round(b, 2), round(c, 2))

    # Проверка существования
    def is_valid(self):

        a, b, c = self.sides()

        return a + b > c and a + c > b and b + c > a

    # Сохранение
    def save(self, filename):

        with open(filename, "w") as f:

            f.write(
                f"{self.A[0]} {self.A[1]} "
                f"{self.B[0]} {self.B[1]} "
                f"{self.C[0]} {self.C[1]}"
            )

    # Равенство
    def __eq__(self, other):

        return sorted(self.sides()) == sorted(other.sides())

    # Площадь
    def area(self):

        a, b, c = self.sides()

        p = (a + b + c) / 2

        return math.sqrt(p * (p - a) * (p - b) * (p - c))

    # Периметр
    def perimeter(self):

        return sum(self.sides())

    # Высоты
    def heights(self):

        s = self.area()

        a, b, c = self.sides()

        return (2 * s / a, 2 * s / b, 2 * s / c)

    # Радиусы окружностей
    def radii(self):

        s = self.area()

        a, b, c = self.sides()

        p = self.perimeter() / 2

        r = s / p
        R = (a * b * c) / (4 * s)

        return r, R

    # Тип треугольника
    def triangle_type(self):

        a, b, c = sorted(self.sides())

        if a == b == c:
            return "Равносторонний"

        elif a == b or b == c or a == c:
            return "Равнобедренный"

        elif c * c == a * a + b * b:
            return "Прямоугольный"

        else:
            return "Обычный"


# Пример

t1 = Triangle.random_triangle()

t1.show_full()

print("Площадь:", round(t1.area(), 2))
print("Периметр:", round(t1.perimeter(), 2))

print("Высоты:", t1.heights())

r, R = t1.radii()

print("Вписанная окружность:", round(r, 2))
print("Описанная окружность:", round(R, 2))

print("Тип:", t1.triangle_type())

t1.save("triangle.txt")

t2 = Triangle.from_file("triangle.txt")

print("Треугольники равны:", t1 == t2)
