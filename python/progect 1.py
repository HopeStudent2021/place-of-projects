Mon = []
Tue = []
Wed = []
Th = []
Fr = []
Sat = []
Sun = []
journal = [Mon, Tue, Wed, Th, Fr, Sat, Sun]
for i in range (len(journal)):
    journal[i] = "Нет дел"
print(journal)
for i in range(len(journal)):
    journal[i] = input("измените дело: ")
print("Вывод календаря на неделю" )
print(journal)
