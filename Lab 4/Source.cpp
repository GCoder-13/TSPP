//Лаб 4. Статичні змінні
#include <iostream>
#include <cmath>

using namespace std;

class Rhomb
{
private:
	double d1, d2;
	const double Pi;
public:
	static unsigned int count;
	Rhomb() : Pi(3.14159), d1(3), d2(4) { count++; };
	Rhomb(double dd1, double dd2) : d1(dd1), d2(dd2), Pi(3.14159) { count++; };
	Rhomb(Rhomb &copy) : d1(copy.d1), d2(copy.d2), Pi(3.14159) { count++; };
	void Input();
	double Square()
	{
		double r;
		r = ((d1 * d2) / 2) / (2 * sqrt(pow((d1 / 2), 2) + pow((d2 / 2), 2)));
		return Pi*r*r;
	};
	double Angle_A()
	{
		return (2 * atan(d1 / d2));
	};
	double Angle_B() 
	{
		return (2 * atan(d2 / d1));
	};
	void Print();
	void Count()
	{
		cout << "Count: " << count << endl;
	}
};

unsigned int Rhomb::count = 0;

void Rhomb::Input()
{
	
	cout << "Input first and second diagonal: ";
	cin >> d1 >> d2;
	if (d1 <= 0 || d2 <= 0)
	{
		cout << "Incorrect input!" << endl;
		system("pause");
		exit(0);
	}
}

void Rhomb::Print() {
	cout.precision(3);
	cout << endl << "\t Square inscribed circle: " << Square() << endl;
	if (d1 < d2)
		cout << "\t Angle DAB=" << Angle_A()*(180 / Pi)
		<< ", angle ABC=" << Angle_B()*(180 / Pi) << " degrees" << endl;
	else cout << "\t Angle DAB=" << Angle_B()*(180 / Pi)
		<< ", angle ABC=" << Angle_A()*(180 / Pi) << " degrees" << endl;
}

int main()
{
	system("color f0");

	Rhomb figure_1;
	figure_1.Input();
	figure_1.Print();

	Rhomb figure_2(2.8, 2.8);
	figure_2.Print();

	Rhomb figure_3 = figure_2;
	figure_3.Print();

	figure_1.Count();
	figure_2.Count();
	figure_3.Count();

	system("pause");
	return 0;
}