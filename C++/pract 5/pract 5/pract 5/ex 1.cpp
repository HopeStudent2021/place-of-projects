/*#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
using namespace std;

//Составить программу, выводящую на экран ведомость начисленной 
	//заработной платы (Ф.И.О., должность, год и дата рождения, заработная плата). 
	//Вывести дату рождения сотрудника с самой маленькой зарплатой.
	//cout<<"Задание 1"<<endl;
typedef struct SWorker
{
	string name, post, birth;
	double salary;
} Worker;

void Print_workers(Worker* workers, const int workers_count)
{

	cout << endl << "Ведомость начисленной  заработной платы(" << workers_count << " чел) имеет вид:";
	cout << "-----------------------------------------------------------------" << endl;
	cout << "          №           Должность              Дата рождения               З/п, руб" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	for (int i = 0; i < workers_count; i++)
	{
		cout << setw(6) << (i + 1) << "\t";
		cout << setw(17) << workers[i].name << "\t";
		cout << setw(20) << workers[i].post << "\t";
		cout << setw(17) << workers[i].birth << "\t";
		cout << setw(12) << workers[i].salary << endl;
	}
	cout << "-----------------------------------------------------------------" << endl;
}

void Get_birth(Worker * workers, const int workers_count)
{
	double mins = workers[0].salary;
	string k;
	for (int i = 0; i < workers_count; i++)
		if (workers[i].salary <= mins)
		{
			mins = workers[i].salary;
			k = workers[i].birth;
		}
	cout << "Дата рождения сотрудника с самой маленькой зарплатой: " << k << endl << endl;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Задание 1" << endl;
	const size_t WORKERS_COUNT = 3;
	Worker workers[WORKERS_COUNT];
	cout << "Вам предстоит ввести информацию о " << WORKERS_COUNT << " работниках" << endl;
	for (int i = 0; i < WORKERS_COUNT; i++)
	{
		cout << "\t Ввод информации о работнике № " << (i + 1) << endl;
		cout << "\t\t - введите имя: ";
		cin.ignore();
		getline(cin, workers[i].name);
		cout << "\t\t - введите должность: ";
		cin >> workers[i].post;
		cout << "\t\t - введите дату рождения: ";
		cin >> workers[i].birth;
		cout << "\t\t - введитеп з/п, руб: ";
		cin >> workers[i].salary;
		cout << endl;
	}
	Print_workers(workers, WORKERS_COUNT);

	Get_birth(workers, WORKERS_COUNT);
	return 0;
}*/


/*#include <iostream>		
#include <iomanip>		
#include <math.h> 
#include <time.h>

using namespace std;


typedef struct TBone
{
	int left;
	int right;
} Bone;




void Print_bones(const Bone* const bones, const int bones_count)
{
	cout << endl << "Информация об окружностях (" << bones_count << " шт.) имеет вид:" << endl;

	cout << "-----------------------------------------------" << endl;
	cout << "     №            Кость       Правая одной == Левой след " << endl;
	cout << "-----------------------------------------------" << endl;
	for (int i = 0; i < bones_count; i++)
	{
		cout << setw(6) << (i + 1);
		cout << setw(12) << "{" << bones[i].left << "; " << bones[i].right << "}";
		cout << setw(15) << (bones[i].right == bones[i + 1].left);
		cout << endl;
	}
	cout << "-----------------------------------------------" << endl;
}



int main(void)
{

	setlocale(LC_ALL, "Russian");


	const size_t BONES_COUNT = 28;


	Bone bones[BONES_COUNT];


	cout << "Вводится информация о " << BONES_COUNT << " костях домино." << endl;
	srand(time(0));
	for (int i = 0; i < BONES_COUNT; i++)
	{
		//fflush( stdin );

		bones[i].left = 1 + rand() % 6;
		bones[i].right = 1 + rand() % 6;
	}


	Print_bones(bones, BONES_COUNT);



	fflush(stdin);
	system("pause");


	return 0;
}*/

/*#include <iostream>	*/	
//#include <iomanip>		
//#include <string>
//#include <Windows.h>

//Определить комбинированный (структурный) тип для представления анкеты жителя,
//состоящей из его фамилии, названия города, где он проживает, и городского адреса.
//Адрес состоит из полей: «улица», «дом», «квартира». Ввести информацию по 10 жителям.
//Переписать из исходного массива в другой массив, информацию только о тех жителях, 
//которые живут в Москве.


/*using namespace std;


typedef struct CAddress
{
	string street;
	int house; 
	int flat; 
} Address;


typedef struct CForm
{
	string surname, city;
	Address address; 
} Form;


void Print_forms(const Form* const forms, const int forms_count, const string message)
{
	cout << endl << message << forms_count << " шт.) имеет вид:" << endl;

	cout << "-----------------------------------------------" << endl;
	cout << "     №             Фамилия            Город            Адрес     " << endl;
	cout << "-----------------------------------------------" << endl;
	for (int i = 0; i < forms_count; i++)
	{
		cout << setw(6) << (i + 1);
		cout << setw(19) << forms[i].surname;
		cout << setw(19) << forms[i].city;
		cout << setw(12) << forms[i].address.street << ", " << forms[i].address.house << ", " << forms[i].address.flat;
		cout << endl;
	}
	cout << "-----------------------------------------------" << endl;
}

int Get_circles_count_from_1_quarter(const Form * const forms, const int forms_count)
{
	int count = 0;

	for (int i = 0; i < forms_count; i++)
		
		if (forms[i].city == "Moscov" || forms[i].city == "Москва")
			count++;

	return count;
}


Form * Get_circles_from_1_quarter(const Form * const forms, const int forms_count, const int circles_from_1_count)
{
	Form* circles_from_1 = new Form[circles_from_1_count];
	int index = 0;

	for (int i = 0; i < forms_count; i++)
		
		if (forms[i].city == "Moscov" || forms[i].city == "Москва")
		{
			circles_from_1[index] = forms[i];
			index++;
		}

	return circles_from_1;
}







int main(void)
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	setlocale(LC_ALL, "Russian");

	
	const size_t FORMS_COUNT = 3;

	
	Form forms[FORMS_COUNT];

	
	cout << "Вам предстоит ввести информацию о " << FORMS_COUNT << " жителях." << endl;
	for (int i = 0; i < FORMS_COUNT; i++)
	{
		fflush(stdin);
		cout << "\t Ввод информации об жителе № " << (i + 1) << endl;

		cout << "\t\t - введите фамилию: ";
		cin >> forms[i].surname;

		cout << "\t\t - введите город проживания: ";
		cin >> forms[i].city;

		cout << "\t\t - введите название улицы, номер дома и квартиры (название улицы и 2 целых числа через пробел): ";
		cin >> forms[i].address.street >> forms[i].address.house >> forms[i].address.flat;

		cout << endl;
	}


	
	Print_forms(forms, FORMS_COUNT, "Информация обо всех жителях (");

	
	int circles_count_from_1 = Get_circles_count_from_1_quarter(forms, FORMS_COUNT);
	if (circles_count_from_1 == 0)
		cout << "Среди жителей нет тех, кто проживает в Москве." << endl;
	else
	{
		
		Form* circles_from_1 = Get_circles_from_1_quarter(forms, FORMS_COUNT, circles_count_from_1);
		
		//Print_forms(circles_from_1, circles_count_from_1, "Информация о жителях, которые проживают в Москве (");
		
		delete[]circles_from_1;
	}

	
	cout << endl;
	//fflush(stdin);
	//system("pause");

	return 0;
}*/

//Определить структурный тип, описывающий гостиничный номер
//(название гостиницы,номер, комфортность (люкс, полулюкс, стандарт, эконом), количество человек, стоимость).
//Заполнить структурный массив 10-ю записями. Переписать из исходного массива в другой массив,
//информацию только о тех гостиничных номерах,
//название гостиницы которых начинается с сочетания букв «City». Затем новый массив отсортировать по номеру.


#include <iostream>		// для консольного ввода вывода
#include <string>		// для работы с типом данных string
#include <iomanip>		// для форматированного вывода данных на экран

// подключаем стандартное пространство имен
using namespace std;

const int MARKS_COUNT = 4; // количество оценок за экзамены у каждого студента

// описание сущности "Гостиничный номер"
typedef struct HRoom
{
	string name; // название гостиницы
	string comfort; // комфортность
	int cnt;  // количество человек
	int	number; // номер гостиницы
	double price; // стоимость
} Room;

// ввод информации о гостиничном номере
void Input_rooms_from_keyboard(Room rooms[], const int ROOMS_COUNT)
{
	cout << "Вам предстоит ввести информацию о " << ROOMS_COUNT << " гостиничных номерах." << endl << endl;
	for (int i = 0; i < ROOMS_COUNT; i++)
	{
		cout << "\tВвод информации о гостиничном номере №" << (i + 1) << endl;
		cout << "\t\t - введите название гостиницы: ";
		cin >> rooms[i].name;
		//fflush(stdin);

		cout << "\t\t - введите номер: ";
		cin >> rooms[i].number;
		//fflush(stdin);

		cout << "\t\t - введите комфортность (люкс, полулюкс, стандарт, эконом): ";
		cin >> rooms[i].comfort;
		//fflush(stdin);


		cout << "\t\t - введите стоимость: ";
		cin >> rooms[i].price;
		

		cout << endl;
	}
}

void Print_rooms(Room rooms[], const int ROOMS_COUNT, const string message)
{
	cout << endl << message << ROOMS_COUNT << " шт.) имеет вид:" << endl;

	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << "     №             Название гостиницы            Номер          Комфортность (люкс, полулюкс, стандарт, эконом)   Количество человек    Стоимость  " << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < ROOMS_COUNT; i++)
	{
		cout << setw(6) << (i + 1);
		cout << setw(20) << rooms[i].name << " " << rooms[i].number << "." << rooms[i].comfort << ".";
		cout << setw(24);
		
		cout << setw(20) << setprecision(3) << fixed << rooms[i].cnt << " " << rooms[i].price;
		cout << endl;
	}
	cout << "----------------------------------------------------------------------------------------" << endl;
}

// определяем кол-во названий гостиниц которых начинается с сочетания букв «City»
int Get_rooms_city_count(Room rooms[], const int ROOMS_COUNT)
{
	const string end_search = "ova";
	int count = 0;

	for (int i = 0; i < ROOMS_COUNT; i++)
		if ((rooms[i].name == "City") &&
			(rooms[i].name.length() == 4 || (rooms[i].name.find("City") = 0 )))
			count++;

	return count;
}

// получаем все названия гостиниц которых начинается с сочетания букв «City»
Room * Get_city_rooms(Room rooms[], const int ROOMS_COUNT, const int city_count)
{
	const string end_search = "City";
	Room* city_rooms = new Room[city_count];
	int index = 0;

	for (int i = 0; i < ROOMS_COUNT; i++)
		if (((rooms[i].name == "City") &&
			(rooms[i].name.length() == 4 or (rooms[i].name.find("City") = 0)))
		{
			city_rooms[index] = rooms[i];
			index++;
		}

	return city_rooms;
}

// сортировка гостиных номеров по номеру по возрастанию
void Selection_sort(Room city_rooms[], const int city_count)
{
	Room swap;
	int min_index;

	for (int i = 0; i < (city_count - 1); i++)
	{
		min_index = i;
		for (int j = (i + 1); j < city_count; j++)
			if (city_rooms[j].number < city_rooms[min_index].number)
				min_index = j;
		if (i != min_index)
		{
			swap = city_rooms[i];
			city_rooms[i] = city_rooms[min_index];
			city_rooms[min_index] = swap;
		}
	}
}

// главная функция программы (точка входа)
int main(void)
{
	// количество гостиных номеров
	const int ROOMS_COUNT = 10;

	// массив, содержащий информацию о гостиных номерах
	Room rooms[ROOMS_COUNT];

	// вводим информацию о гостиных номерах с клавиатуры
	setlocale(LC_ALL, "Russian");
	Input_rooms_from_keyboard(rooms, ROOMS_COUNT);

	// выводим информацию обо всех гостиных номерах на экран
	Print_rooms(rooms, ROOMS_COUNT, "Информация обо всех гостиных номерах (");

	// считаем количество гостиниц, чьи названия начинаются на "City"
	int ova_count = Get_rooms_city_count(rooms, ROOMS_COUNT);

	if (city_count > 0)
	{
		// получаем массив ведомостей студентов, чьи фамилии заканчиваются на "ova"
		Room* ova_statements = Get_city_rooms(rooms, ROOMS_COUNT, city_count);

		// выводим информацию о студентах, чьи фамилии заканчиваются на "ova"
		Print_rooms(city_rooms, city_count, "Информация о студентах, чьи фамилии оканчиваются на \"ova\" (");

		// сортируем ведомости по среднему баллу по возрастанию (методом выбора)
		Selection_sort(city_rooms, city_count);

		// выводим информацию о студентах, чьи фамилии заканчиваются на "ova", отсортированных по среднему баллу по возрастанию
		Print_rooms(city_rooms, city_count, "Информация о студентах (отсортированных по среднему баллу), чьи фамилии оканчиваются на \"ova\" (");

		// незабываем удалить память из-под динамического массива о ведомостях
		delete[] city_rooms;
	}
	else
		cout << endl << "В данных студенческих ведомостях нет ни одного студента, чья фамилия оканчивается на \"ova\"";

	// задержка работы программы, чтобы у пользователя была возможность просмотреть результат
	cout << endl << endl;
	fflush(stdin);
	system("pause");

	// завершение выполнение программы и передача управления в ОС (код 0 - все прошло успешно!)
	return 0;
}
