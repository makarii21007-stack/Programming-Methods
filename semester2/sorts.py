import random
import time
import sys

sys.setrecursionlimit(1000000)

operations = 0
swaps = 0
insertions = 0


# MERGE SORT


def merge_sort(arr):
    global operations, insertions

    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    operations += 1

    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])

    result = []

    i = 0
    j = 0

    while i < len(left) and j < len(right):
        operations += 4

        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

        insertions += 1

    while i < len(left):
        result.append(left[i])
        i += 1
        insertions += 1

    while j < len(right):
        result.append(right[j])
        j += 1
        insertions += 1

    return result


# RADIX SORT


def radix_sort(arr):
    global operations, insertions

    max_num = max(arr)
    exp = 1

    while max_num // exp > 0:

        output = [0] * len(arr)
        count = [0] * 10

        for num in arr:
            index = (num // exp) % 10
            operations += 3
            count[index] += 1

        for i in range(1, 10):
            count[i] += count[i - 1]

        for i in range(len(arr) - 1, -1, -1):
            index = (arr[i] // exp) % 10

            output[count[index] - 1] = arr[i]
            count[index] -= 1

            insertions += 1

        for i in range(len(arr)):
            arr[i] = output[i]

        exp *= 10

    return arr


# QUICK SORT


def quick_sort(arr, low, high):
    if low >= high:
        return

    pivot = arr[(low + high) // 2]

    i = low
    j = high

    global operations, swaps

    while i <= j:

        while arr[i] < pivot:
            operations += 2
            i += 1

        while arr[j] > pivot:
            operations += 2
            j -= 1

        if i <= j:
            arr[i], arr[j] = arr[j], arr[i]
            swaps += 1

            i += 1
            j -= 1

    quick_sort(arr, low, j)
    quick_sort(arr, i, high)


# TEST


def test(name, func, arr):
    global operations, swaps, insertions

    operations = 0
    swaps = 0
    insertions = 0

    start = time.time()

    if name == "Quick Sort":
        func(arr, 0, len(arr) - 1)
    else:
        func(arr)

    end = time.time()

    print("\n" + name)
    print("Время:", round(end - start, 4))
    print("Операции:", operations)
    print("Вставки:", insertions)
    print("Обмены:", swaps)


# MAIN

sizes = [10000, 100000, 1000000]

for size in sizes:

    print("\n========================")
    print(size, "элементов")

    base = [random.randint(0, 1000000) for _ in range(size)]

    test("Merge Sort", merge_sort, base.copy())
    test("Radix Sort", radix_sort, base.copy())
    test("Quick Sort", quick_sort, base.copy())
