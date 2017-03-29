#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
	Queue q;
	q.Put("1");
	q.Put("2");

	q.Print();
	

	system("pause");
	return 0;
}