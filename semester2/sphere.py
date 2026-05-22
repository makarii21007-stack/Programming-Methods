import math

n = int(input("Количество точек: "))
r = float(input("Радиус шара: "))

points = []

for i in range(n):
    x = float(input("x: "))
    y = float(input("y: "))
    z = float(input("z: "))

    points.append((x, y, z))

max_count = 0
best_point = ()

for p1 in points:

    count = 0

    for p2 in points:

        distance = math.sqrt(
            (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2 + (p1[2] - p2[2]) ** 2
        )

        if distance <= r:
            count += 1

    if count > max_count:
        max_count = count
        best_point = p1

print("\nЛучшая точка:", best_point)
print("Количество точек внутри шара:", max_count)
