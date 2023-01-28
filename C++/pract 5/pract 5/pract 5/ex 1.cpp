/*#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
using namespace std;

//��������� ���������, ��������� �� ����� ��������� ����������� 
	//���������� ����� (�.�.�., ���������, ��� � ���� ��������, ���������� �����). 
	//������� ���� �������� ���������� � ����� ��������� ���������.
	//cout<<"������� 1"<<endl;
typedef struct SWorker
{
	string name, post, birth;
	double salary;
} Worker;

void Print_workers(Worker* workers, const int workers_count)
{

	cout << endl << "��������� �����������  ���������� �����(" << workers_count << " ���) ����� ���:";
	cout << "-----------------------------------------------------------------" << endl;
	cout << "          �           ���������              ���� ��������               �/�, ���" << endl;
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
	cout << "���� �������� ���������� � ����� ��������� ���������: " << k << endl << endl;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "������� 1" << endl;
	const size_t WORKERS_COUNT = 3;
	Worker workers[WORKERS_COUNT];
	cout << "��� ��������� ������ ���������� � " << WORKERS_COUNT << " ����������" << endl;
	for (int i = 0; i < WORKERS_COUNT; i++)
	{
		cout << "\t ���� ���������� � ��������� � " << (i + 1) << endl;
		cout << "\t\t - ������� ���: ";
		cin.ignore();
		getline(cin, workers[i].name);
		cout << "\t\t - ������� ���������: ";
		cin >> workers[i].post;
		cout << "\t\t - ������� ���� ��������: ";
		cin >> workers[i].birth;
		cout << "\t\t - �������� �/�, ���: ";
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
	cout << endl << "���������� �� ����������� (" << bones_count << " ��.) ����� ���:" << endl;

	cout << "-----------------------------------------------" << endl;
	cout << "     �            �����       ������ ����� == ����� ���� " << endl;
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


	cout << "�������� ���������� � " << BONES_COUNT << " ������ ������." << endl;
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

//���������� ��������������� (�����������) ��� ��� ������������� ������ ������,
//��������� �� ��� �������, �������� ������, ��� �� ���������, � ���������� ������.
//����� ������� �� �����: ������, ����, ���������. ������ ���������� �� 10 �������.
//���������� �� ��������� ������� � ������ ������, ���������� ������ � ��� �������, 
//������� ����� � ������.


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
	cout << endl << message << forms_count << " ��.) ����� ���:" << endl;

	cout << "-----------------------------------------------" << endl;
	cout << "     �             �������            �����            �����     " << endl;
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
		
		if (forms[i].city == "Moscov" || forms[i].city == "������")
			count++;

	return count;
}


Form * Get_circles_from_1_quarter(const Form * const forms, const int forms_count, const int circles_from_1_count)
{
	Form* circles_from_1 = new Form[circles_from_1_count];
	int index = 0;

	for (int i = 0; i < forms_count; i++)
		
		if (forms[i].city == "Moscov" || forms[i].city == "������")
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

	
	cout << "��� ��������� ������ ���������� � " << FORMS_COUNT << " �������." << endl;
	for (int i = 0; i < FORMS_COUNT; i++)
	{
		fflush(stdin);
		cout << "\t ���� ���������� �� ������ � " << (i + 1) << endl;

		cout << "\t\t - ������� �������: ";
		cin >> forms[i].surname;

		cout << "\t\t - ������� ����� ����������: ";
		cin >> forms[i].city;

		cout << "\t\t - ������� �������� �����, ����� ���� � �������� (�������� ����� � 2 ����� ����� ����� ������): ";
		cin >> forms[i].address.street >> forms[i].address.house >> forms[i].address.flat;

		cout << endl;
	}


	
	Print_forms(forms, FORMS_COUNT, "���������� ��� ���� ������� (");

	
	int circles_count_from_1 = Get_circles_count_from_1_quarter(forms, FORMS_COUNT);
	if (circles_count_from_1 == 0)
		cout << "����� ������� ��� ���, ��� ��������� � ������." << endl;
	else
	{
		
		Form* circles_from_1 = Get_circles_from_1_quarter(forms, FORMS_COUNT, circles_count_from_1);
		
		//Print_forms(circles_from_1, circles_count_from_1, "���������� � �������, ������� ��������� � ������ (");
		
		delete[]circles_from_1;
	}

	
	cout << endl;
	//fflush(stdin);
	//system("pause");

	return 0;
}*/

//���������� ����������� ���, ����������� ����������� �����
//(�������� ���������,�����, ������������ (����, ��������, ��������, ������), ���������� �������, ���������).
//��������� ����������� ������ 10-� ��������. ���������� �� ��������� ������� � ������ ������,
//���������� ������ � ��� ����������� �������,
//�������� ��������� ������� ���������� � ��������� ���� �City�. ����� ����� ������ ������������� �� ������.


#include <iostream>		// ��� ����������� ����� ������
#include <string>		// ��� ������ � ����� ������ string
#include <iomanip>		// ��� ���������������� ������ ������ �� �����

// ���������� ����������� ������������ ����
using namespace std;

const int MARKS_COUNT = 4; // ���������� ������ �� �������� � ������� ��������

// �������� �������� "����������� �����"
typedef struct HRoom
{
	string name; // �������� ���������
	string comfort; // ������������
	int cnt;  // ���������� �������
	int	number; // ����� ���������
	double price; // ���������
} Room;

// ���� ���������� � ����������� ������
void Input_rooms_from_keyboard(Room rooms[], const int ROOMS_COUNT)
{
	cout << "��� ��������� ������ ���������� � " << ROOMS_COUNT << " ����������� �������." << endl << endl;
	for (int i = 0; i < ROOMS_COUNT; i++)
	{
		cout << "\t���� ���������� � ����������� ������ �" << (i + 1) << endl;
		cout << "\t\t - ������� �������� ���������: ";
		cin >> rooms[i].name;
		//fflush(stdin);

		cout << "\t\t - ������� �����: ";
		cin >> rooms[i].number;
		//fflush(stdin);

		cout << "\t\t - ������� ������������ (����, ��������, ��������, ������): ";
		cin >> rooms[i].comfort;
		//fflush(stdin);


		cout << "\t\t - ������� ���������: ";
		cin >> rooms[i].price;
		

		cout << endl;
	}
}

void Print_rooms(Room rooms[], const int ROOMS_COUNT, const string message)
{
	cout << endl << message << ROOMS_COUNT << " ��.) ����� ���:" << endl;

	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << "     �             �������� ���������            �����          ������������ (����, ��������, ��������, ������)   ���������� �������    ���������  " << endl;
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

// ���������� ���-�� �������� �������� ������� ���������� � ��������� ���� �City�
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

// �������� ��� �������� �������� ������� ���������� � ��������� ���� �City�
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

// ���������� �������� ������� �� ������ �� �����������
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

// ������� ������� ��������� (����� �����)
int main(void)
{
	// ���������� �������� �������
	const int ROOMS_COUNT = 10;

	// ������, ���������� ���������� � �������� �������
	Room rooms[ROOMS_COUNT];

	// ������ ���������� � �������� ������� � ����������
	setlocale(LC_ALL, "Russian");
	Input_rooms_from_keyboard(rooms, ROOMS_COUNT);

	// ������� ���������� ��� ���� �������� ������� �� �����
	Print_rooms(rooms, ROOMS_COUNT, "���������� ��� ���� �������� ������� (");

	// ������� ���������� ��������, ��� �������� ���������� �� "City"
	int ova_count = Get_rooms_city_count(rooms, ROOMS_COUNT);

	if (city_count > 0)
	{
		// �������� ������ ���������� ���������, ��� ������� ������������� �� "ova"
		Room* ova_statements = Get_city_rooms(rooms, ROOMS_COUNT, city_count);

		// ������� ���������� � ���������, ��� ������� ������������� �� "ova"
		Print_rooms(city_rooms, city_count, "���������� � ���������, ��� ������� ������������ �� \"ova\" (");

		// ��������� ��������� �� �������� ����� �� ����������� (������� ������)
		Selection_sort(city_rooms, city_count);

		// ������� ���������� � ���������, ��� ������� ������������� �� "ova", ��������������� �� �������� ����� �� �����������
		Print_rooms(city_rooms, city_count, "���������� � ��������� (��������������� �� �������� �����), ��� ������� ������������ �� \"ova\" (");

		// ���������� ������� ������ ��-��� ������������� ������� � ����������
		delete[] city_rooms;
	}
	else
		cout << endl << "� ������ ������������ ���������� ��� �� ������ ��������, ��� ������� ������������ �� \"ova\"";

	// �������� ������ ���������, ����� � ������������ ���� ����������� ����������� ���������
	cout << endl << endl;
	fflush(stdin);
	system("pause");

	// ���������� ���������� ��������� � �������� ���������� � �� (��� 0 - ��� ������ �������!)
	return 0;
}
