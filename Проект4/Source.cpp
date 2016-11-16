#include <iostream>

using namespace std;

typedef long elem;

typedef struct Double_List {
	elem var;
	Double_List *next;
	Double_List *back;
}list;

list* make_element(elem a) {
	list *p;
	p = new list;
	p->var = a;
	p->next = NULL;
	p->back = NULL;
	return p;
}

list* Vusol(list *p, int k) {

	for (int i(0); i<k && p != NULL; i++)
	{
		p = p->next;
	}
	return *&p;
}

void add_element(elem a, list *p) {
	list *nw;
	for (int i(0); p->next != NULL; i++)
	{
		p = p->next;
	}
	nw=make_element(a);
	p->next = nw;
	nw->back = p;
}

void N_add(list *sp) {

	list *p, *end;
	elem a;
	int n;

	cout << "Input number element: ";
	cin >> n;
	cout << "Input element: ";
	cin >> a;

	end = Vusol(sp, n-1);
	p = make_element(a);
	p->back = end->back;
	p->next = end;
	end->back = p;
	if (n - 1 == 0)
		p->back = NULL;
	p->back->next = p;
}

void Input(list *&p) {
	elem a;
	cout << "Input element: ";
	cin >> a;
	if (p == NULL)
	{
		p = make_element(a);
	}
	else
	{
		add_element(a, p);
	}

	cout << endl;
}

void Output(list *p) {

	cout << endl;
	for (int i(0); p != NULL; i++) 
	{
		cout << "\t Element " << i + 1 << ": " << p->var << endl;
		p = p->next;
	}
}

void Free(list *&p) {

	list *del;

	for (int i(0); p != NULL; i++)
	{
		del = p->next;
		delete p;
		p = del;
	}
}

int main() {

	system("COLOR F0");

	list *page=NULL;
	bool option=true;
	char choice;

	while (option)
	{
		cout << "Do you want add element to list (y/n): ";
		cin >> choice;
		switch (choice)
		{
		case 'y': Input(*&page); option = true; break;
		default: option = false; break;
		}
	}

	option = true;

	while (option)
	{
		cout << endl << "Do you want to add element into the middle of the list (y/n): ";
		cin >> choice;
		switch (choice)
		{
		case 'y': N_add(page); option = true; break;
		default: option = false; break;
		}
	}

	cout << endl << "You want print list (y/n): ";
	cin >> choice;
	switch (choice)
	{
	case 'y': Output(page); break;
	default: break;
	}
	Free(*&page);
	system("PAUSE");
	return 0;
}