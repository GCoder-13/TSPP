#include <iostream>
#include <cmath>

using namespace std;

class ExceptionInput {};

long double Fibonacci(int num)
{
	if (num == 0)
		throw exception("\t The number zero");
	double fi = (1 + sqrt(5)) / 2;
	cout.setf(ios_base::fixed);
	cout.precision(0);
	return ((pow(fi, num) - pow(-fi, -num)) / (2 * fi - 1));
}

int main()
{
	int n;
	try
	{
		cout << "Enter the serial number of the Fibonacci series: ";
		if (!(cin >> n))
			throw ExceptionInput();
		
		cout << endl << "The Fibonacci number: " << Fibonacci(n) << endl;
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	catch (const ExceptionInput&)
	{
		cout << "\t Incorrect input!" << endl;
		system("pause");
		exit(-1);
	}

	system("pause");
	return 0;
}