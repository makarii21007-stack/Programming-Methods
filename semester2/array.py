students = []

n = int(input("Количество студентов: "))

for i in range(n):

    fio = input("Фамилия И.О.: ")
    ticket = input("Номер студенческого билета: ")
    course = int(input("Курс: "))
    avg = float(input("Средний балл: "))
    study_type = input("Форма обучения (дневное/заочное): ")
    debts = int(input("Количество задолженностей: "))

    student = {
        "fio": fio,
        "ticket": ticket,
        "course": course,
        "avg": avg,
        "study_type": study_type,
        "debts": debts,
    }

    students.append(student)

print("\nСтуденты с задолженностями на дневном обучении:")

for student in students:

    if student["debts"] > 0 and student["study_type"] == "дневное":
        print(student["fio"])
