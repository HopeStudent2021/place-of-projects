// pract7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*#include <iostream>
#include <fstream>
#include <math.h>
#include <set>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int i = 0, k = 0, j = 0;
	ofstream outfile; // запись в файл
	outfile.open("f.txt");
	outfile << 1 << " " << 2 << " " << 3 << " " << 2 << " " << 5 << " " << 5 << " " << 2 << " " << 4 << endl;
	int number1[10];
	std::set<int> number2;
	int num; //просмотр содержимого
	ifstream in("f.txt");
	if (in.is_open())
	{
		while (in >> num)
		{
			number1[i] = num;
			number2.emplace(num);
			cout << number1[i] << " ";
			i++;
		}
		cout << endl;
	}
	outfile.close();
	outfile.open("g.txt");
	for (int n : number2)
	{
		outfile << n << " " << endl;
	}
	system("pause");
}
*/
/*Сформировать массив на диске, содержащий сведения о пациентах глазной
клиники. Класс содержит поля: фамилия пациента, пол, возраст, место проживания
(город), диагноз.
Написать программу, которая выбирает необходимую информацию с диска и
выводит на экран:
- количество иногородних, прибывших в поликлинику;
- список пациентов старше Х лет с диагнозом J.
*/
/*#include <fstream>
# include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
class myclass {
public:
	string fio, city, diagnos;
	char sex;
	int age;
	myclass(string fio, char sex, int age, string city, string diagnos) {
		this->fio = fio;
		this->sex = sex;
		this->age = age;
		this->city = city;
		this->diagnos = diagnos;
	}
	friend ostream& operator << (ostream& out, myclass& m);
	friend istream& operator >> (istream& out, myclass& m);
};

ostream& operator << (ostream& out, myclass& m)
{
	out << m.fio << " " << m.sex << " " << m.city << " " << m.diagnos <<  endl;
	return out;
}
istream& operator >> (istream& in, myclass& m)
{
	in >> m.fio >> m.sex >> m.city >> m.diagnos;
	return in;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ofstream fout("cppstudio.txt");
	string path = "cppstudio.txt";
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	myclass p1("Иванов Иван Иванович", 50, 'м', "Москва", "Глаукома");
	myclass p2("Солженицына Ирина Романовна", 45, 'ж', "Ростов", "Неврит");
	myclass p3("Федоров Сергей Викторович", 18, 'м', "Красноярск", "Блефарит");
	myclass p4("Меньшикова Виолетта Степановна", 25, 'ж', "Москва", "Лагофтальм");
	myclass p5("Романов Петр Алексеевич", 33, 'м', "Санкт-Петербург", "Птоз");

	if (!fs.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Файл открыт!" << endl;
	}
	fs.close();*/
	/*ofstream fout("cppstudio.txt"); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
	fout << "Работа с файлами в С++"; // запись строки в файл
	fout.close(); // закрываем файл
	system("pause");
	return 0;
	
	Films Films[5];
	cout << "0. Ввод данных" << endl << "1. Статистика по жанрам для студии Y" << endl << "2. Список фильмов категории Z, находящихся в коллекции" << endl << "3. Число фильмов 2000 г., имеющихся в коллекции " << endl << "4.Выход " << endl;
	int n; cin >> n;
	switch (n)
	{
	case 0: for (int i = 0; i < 5; i++) vvod(Films[5]); break;
	case 1: stat(Films[5]); break;
	case 2: spisok(Films[5]); break;
	case 3: chislo(Films[5]); break;
	case 4: cout << "Выход"; {return 0; }
	default: cout << "Error"; break;
	}
	system("pause");
	return 0;
	*/
//}

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "stdio.h"

using namespace std;
#define people_count 4


class Patient //имя класса
{
public:
	string surname; //имя рабочего
	char sex;
	string city;//цех
	int age;
	string diagnos;
	friend ostream& operator << (ostream& out, Patient& m);
	friend istream& operator >> (istream& out, Patient& m);
}patient;

ostream& operator << (ostream& out, Patient& m)
{
	out << m.surname << " " << m.sex << " " << m.age << " " << m.city << " " << m.diagnos << endl;
	return out;
}
istream& operator >> (istream& in, Patient& m)
{
	in >> m.surname >> m.sex >> m.age >> m.city >> m.diagnos;
	return in;
}

int main()
{
	setlocale(LC_ALL, "");
	system("chcp 1251");
	Patient patient[people_count];
	string  surname;
	char sex;
	string city;//город
	int age;
	string diagnos;
	cout << "Вам предстоит ввести информацию о " << people_count << " пациентах" << endl;
	for (int i = 0; i < people_count; i++)
	{
		fflush(stdin);
		cout << "Ввод информации о пациенте № " << (i + 1) << endl;
		cout << "\tВведите фамилию : "; cin >> patient[i].surname;
		cout << "\tВведите  пол(м или ж): "; cin >> patient[i].sex;
		cout << "\tВведите возраст: "; cin >> patient[i].age;
		cout << "\tВведите город: "; cin >> patient[i].city;
		cout << "\tВведите диагноз: "; cin >> patient[i].diagnos;
		cin.ignore();
		cout << "-----------------------------------------------------------------------------------" << endl;
	}

	//запись в файл
	ofstream outfile;
	outfile.open("Clinic.txt");
	for (int i = 0; i < people_count; i++)
		outfile << "Информации о пациенте №: " << (i + 1) << " " << "\nФамилия:" << patient[i].surname << ";" << " " << "\nПол: " << patient[i].sex << ";" << " " << "\nВозраст: " << patient[i].age << ";" << " " << "\nГород: " << patient[i].city << "\nДиагноз: " << patient[i].diagnos << "." << "\n------------------------------------------------------------------------------------" << endl;

	outfile.close();



	ifstream fin("Clinic.txt");

	int k = 0, x = 0;
	string js, gorod = "Москва";
	cout << "Возраст, старше которого искать:" << endl;
	cin >> x;
	cout << "Диагноз" << endl;
	cin >> js;
	cout << "Список пациентов старше Х лет с диагнозом J." <<  endl;
	for (int j = 0; j < 1; j++) {

		for (int i = 0; i < people_count; i++)
		{
			if((patient[i].age > x) && (patient[i].diagnos == js))
				cout << "Информации о пациенте №: " << (i + 1) << " " << "\nФамилия:" << patient[i].surname << ";" << " " << "\nПол: " << patient[i].sex << ";" << " " << "\nВозраст: " << patient[i].age << ";" << " " << "\nГород: " << patient[i].city << "\nДиагноз: " << patient[i].diagnos << "." << "\n------------------------------------------------------------------------------------" << endl;
				
			if (patient[i].city != gorod)
			{
				k++;
			}
			
		}
	}
	cout << "Количество иногородних, прибывших в поликлинику " << k << endl;
	
	system("pause");
	cin.get();
	outfile.close();
	return 0;

}
