n1 = int(input("Количество точек первого множества: "))
set1 = set()

for i in range(n1):
    x = float(input("x: "))
    y = float(input("y: "))
    set1.add((x, y))


n2 = int(input("\nКоличество точек второго множества: "))
set2 = set()

for i in range(n2):
    x = float(input("x: "))
    y = float(input("y: "))
    set2.add((x, y))


intersection = set1 & set2
difference = set1 - set2

print("\nПересечение множеств:")
print(intersection)

print("\nРазность множеств (первое - второе):")
print(difference)