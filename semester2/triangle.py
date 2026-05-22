n = int(input("Количество треугольников: "))

max_min_side = 0
best_triangle = ()

for i in range(n):

    a = float(input("Сторона a: "))
    b = float(input("Сторона b: "))
    c = float(input("Сторона c: "))

    min_side = min(a, b, c)

    if min_side > max_min_side:
        max_min_side = min_side
        best_triangle = (a, b, c)

print("\nНаибольшая из минимальных сторон:", max_min_side)
print("Соответствующий треугольник:", best_triangle)
