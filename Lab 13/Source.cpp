#include <iostream>
#include "Header.h"

using namespace std;

int main(int argc, char** argv)
{
	/* Prism(кылькысь кутів, довжина сторін, апофема, висота) */
	Prism<double> pr(4,2,1,5);

	cout.precision(2);
	cout << "S = " << pr.area() << endl
		<< "V = " << pr.volume() << endl
		<< "Diagonal = " << pr.diagonal() << endl;

	system("pause");
	return 0;
}