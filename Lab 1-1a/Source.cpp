#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <conio.h>

using namespace std;

struct Goods
{
	string Name;
	long Type;
	long Quantity;
	double Cost;
};
struct SKLAD
{
	Goods var;
	SKLAD *next;
	SKLAD *back;
};

SKLAD* make_element();
Goods Input();
SKLAD* Element(SKLAD *p, int &k);
int Size_list(SKLAD* p);
inline void Output(SKLAD* sk);
SKLAD* add_first(SKLAD *first);
SKLAD* del_first(SKLAD *first);
SKLAD* add_N(SKLAD *p);
void del_N(SKLAD *&p);
inline bool Empty(SKLAD *list);
void Free(SKLAD *&p);
void Print_N(SKLAD *p);
void Print(SKLAD *p);

inline void Menu()
{
	cout << "\t �i� ��� �������" << endl
		<< "1) ��������� �������� � ������� ������;" << endl
		<< "2) ��������� �������� � ������� ������;" << endl
		<< "3) ��������� �������� � ����-��� �i��� ������;" << endl
		<< "4) ��������� �������� � ����-����� �i��� ������;" << endl
		<< "5) �����i���, �� ������i� ������;" << endl
		<< "6) ������� ������;" << endl
		<< "7) ���� ������� �������� ������;" << endl
		<< "8) ���� �i���� ������;" << endl
		<< "0) ����� � ��������;" << endl;
}

int main()
{
	system("COLOR F0");
	setlocale(LC_ALL, "UKR");
	SKLAD *sk = NULL;
	char choice;

	while (true)
	{
		system("CLS");
		Menu();
		cout << endl << "�����i�� �i� i ������i�� �i����i��� ����i��: ";
		choice = _getche();

		switch (choice)
		{
		case '1': sk = add_first(sk); break;
		case '2': sk = del_first(sk); break;
		case '3': sk = add_N(sk); break;
		case '4': del_N(sk); break;
		case '5': if (!Empty(sk)) cout << endl << "\t ������ �� ������i�" << endl; break;
		case '6': Free(sk); break;
		case '7': Print_N(sk); break;
		case '8': Print(sk); break;
		case '0': exit(0);
		default: cout << endl << "�� �������� ��������!" << endl; break;
		}
		system("PAUSE");
	}
}

/*��������� ������*/
SKLAD* make_element()
{
	SKLAD *p;
	p = new SKLAD;
	p->var = Input();
	p->next = NULL;
	p->back = NULL;
	return p;
}

/*�������� ��������*/
Goods Input()
{
	Goods tovar;
	cout << endl << "����i�� ����� ������: ";
	cin >> tovar.Name;
	cout << "����i�� ��� ������: ";
	cin >> tovar.Type;
	cout << "����i�� �i���i��� ������: ";
	cin >> tovar.Quantity;
	cout << "����i�� �i�� ������: ";
	cin >> tovar.Cost;
	return tovar;
}

/*����� �������� ������*/
SKLAD* Element(SKLAD *p, int &k)
{
	int i;
	cout << endl << "����i�� ����� �������� (�i���) ������: ";
	cin >> k;
	k--;
	if ((k < 0) || (k - 1 > Size_list(p)))
		return NULL;
	if (k == 0)
		return p;
	for (i = 0; i < k && p->next != NULL; i++)
		p = p->next;

	return p;
}

int Size_list(SKLAD* p)
{
	int n = 0;
	if (!p)
		return 0;
	while (p->next != NULL)
	{
		p = p->next;
		n++;
	}
	return n;
}

void Output(SKLAD* sk)
{
	cout << endl
		<< "\t �����: " << sk->var.Name << endl
		<< "\t ���: " << sk->var.Type << endl
		<< "\t �i���i���: " << sk->var.Quantity << endl
		<< "\t �i��: " << fixed << setprecision(2) << sk->var.Cost << " ���." << endl << endl;
}

/*1) ��������� �������� � ������� ������;*/
SKLAD* add_first(SKLAD *first)
{
	SKLAD *p = make_element();
	if (first)
		first->back = p;
	p->next = first;
	return p;
}

/*2) ��������� �������� � ������� ������;*/
SKLAD* del_first(SKLAD *first)
{
	if (Empty(first))
		return NULL;
	Output(first);
	SKLAD *p = first->next;
	delete first;
	first = p;
	if (first)
		first->back = NULL;
	cout << "\t ������ ������� ������ ��������" << endl;
	return first;
}

/*3) ��������� �������� � ����-��� �i��� ������;*/
SKLAD* add_N(SKLAD *p)
{
	int k = 0;
	SKLAD* rez;
	rez = Element(p, k);
	if (rez == NULL && k != 0)
	{
		cout << endl << "\t �� �������� ��������!" << endl;
		return NULL;
	}
	SKLAD* sk = make_element();
	if (k == 0)
	{
		if (p)
			p->back = sk;
		sk->next = p;
		return sk;
	}
	if (k - 1 == Size_list(p))
	{
		sk->back = rez;
		rez->next = sk;
	}
	else
	{
		sk->back = rez->back;
		sk->next = rez;
		rez->back->next = sk;
		rez->back = sk;
	}
	return p;
}

/*4) ��������� �������� � ����-����� �i��� ������;*/
void del_N(SKLAD *&p)
{
	if (Empty(p))
		return;
	int k = 0;
	SKLAD* sk;
	sk = Element(p, k);
	if (sk == NULL || k - 1 == Size_list(p))
	{
		cout << endl << "\t �� �������� ��������!" << endl;
		return;
	}
	cout << endl << "����� �" << k + 1;
	if (k == 0)
	{
		p = del_first(p);
		return;
	}
	Output(sk);
	if (sk->next != NULL)
		sk->next->back = sk->back;
	sk->back->next = sk->next;
	delete sk;

	cout << endl << "\t ������� ��� ��������� �i ������" << endl;
}

/*5) �����i���, �� ������i� ������;*/
bool Empty(SKLAD *list)
{
	if (!list)
		cout << endl << "\t ������ ������i�!" << endl;
	return !list;
}

/*6) ������� ������;*/
void Free(SKLAD *&p)
{
	SKLAD *del;
	if (Empty(p))
		return;
	for (int i(0); p != NULL; i++)
	{
		del = p->next;
		delete p;
		p = del;
	}
	cout << endl << "\t ������ �������" << endl;
}

/*7) ���� ������� �������� ������;*/
void Print_N(SKLAD *p)
{
	if (Empty(p))
		return;
	int k = 0;
	SKLAD* sk;
	sk = Element(p, k);
	if (sk == NULL || k - 1 == Size_list(p))
	{
		cout << endl << "\t �� �������� ��������!" << endl;
		return;
	}
	cout << endl << "����� �" << k + 1;
	Output(sk);
}

/*8) ���� �i���� ������;*/
void Print(SKLAD *p)
{
	if (Empty(p))
		return;
	for (int i(0); p != NULL; i++)
	{
		cout << endl << "����� �" << i + 1;
		Output(p);
		p = p->next;
	}
}