#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;

inline void OutputMenu()
{
	cout << "\t Select an action" << endl
		<< "1 - Put element;" << endl
		<< "2 - Get element;" << endl
		<< "3 - Clear queue;" << endl
		<< "4 - Show queue;" << endl
		<< "0 - Exit." << endl;
}

void SwitchMenu(Queue& queue)
{
	int action;
	while (true)
	{
		OutputMenu();
		try
		{
			cout << endl << "Select an action: ";
			if (!(cin >> action))
				throw FatalError(0x999, "Incorrect input");
		}
		catch (const FatalError& e)
		{
			queue.~Queue();
			e.display();
		}

		string elem;
		char *str;
		switch (action)
		{
		case 1:
			cout << "Enter element: ";
			cin.ignore();
			getline(cin, elem);				
			queue.Put(elem.c_str());
			break;
		case 2:
			str = queue.Get();
			if (str)
				cout << "The last element: " << str << endl;
			break;
		case 3:
			queue.~Queue();
			break;
		case 4:
			cout << "Queue:" << endl;
			queue.Print();
			break;
		case 0: return;
		default:
			cerr << "\t Incorrect input" << endl;
			break;
		}

		system("pause");
		system("cls");
	}
}

int main(int argc, char **argv)
{
	Queue list;
	SwitchMenu(list);

	return 0;
}