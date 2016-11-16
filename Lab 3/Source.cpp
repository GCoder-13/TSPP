#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Rhomb
{
private:
	double d1, d2, const Pi;
public:
	Rhomb() : Pi(3.14159), d1(3), d2(4) { cout << "Hallo_1!" << endl; };
	Rhomb(double dd1, double dd2) : d1(dd1), d2(dd2), Pi(3.14159) { cout << "Hallo_2!" << endl; };
	Rhomb(Rhomb &copy) : d1(copy.d1), d2(copy.d2), Pi(3.14159) { cout << "Hallo_3!" << endl; };
	void Input();
	double Square();
	double Angle_A();
	double Angle_B();
	void Print() {
		cout.precision(3);
		cout << endl << "\t Square inscribed circle: " << Square() << endl;
		if (d1 < d2)
			cout << "\t Angle DAB=" << Angle_A()*(180 / Pi)
			<< ", angle ABC=" << Angle_B()*(180 / Pi) << " degrees" << endl;
		else cout << "\t Angle DAB=" << Angle_B()*(180 / Pi)
			<< ", angle ABC=" << Angle_A()*(180 / Pi) << " degrees" << endl;
	}

};

void Rhomb::Input()
{
	cout << "Input first and second diagonal: ";
	cin >> d1 >> d2;
	while (d1 <= 0 || d2 <= 0)
	{
		cout << "Incorrect input!" << endl;
		system("pause");
		exit(0);
	}
}

double Rhomb::Square()
{
	double r;
	r = ((d1 * d2) / 2) / (2 * sqrt(pow((d1 / 2), 2) + pow((d2 / 2), 2)));
	return Pi*r*r;
}

double Rhomb::Angle_A()
{
	return (2 * atan(d1 / d2));
}

double Rhomb::Angle_B()
{
	return (2 * atan(d2 / d1));
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

	system("pause");
	return 0;
}