#include <iostream>
#include "Header.h"

using namespace std;

int main(int argc, char** argv)
{
	/* Prism(кiлькысь кутів, R, h) */
	Prism<double> pr(4, 1.4142135, 5);

	cout.precision(3);
	cout << "S = " << pr.area() << endl
		<< "V = " << pr.volume() << endl
		<< "Diagonal = " << pr.diagonal() << endl;

	system("pause");
	return 0;
}