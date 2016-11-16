#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Rhomb 
{
private:
	double d1, d2, Pi;
public:
	void Input();
	double Square();
	double Angle_A();
	double Angle_B();
	void Print()
	{
		cout << endl << "\t Square inscribed circle: " << Square() << endl;
		if (d1 < d2)
			cout << fixed << setprecision(0) << "\t Angle DAB=" << Angle_A()*(180 / Pi)
				<< ", angle ABC=" << Angle_B()*(180 / Pi) << " degrees" << endl;
		else cout << fixed << setprecision(0) << "\t Angle DAB=" << Angle_B()*(180 / Pi)
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
	Pi = 3.14159;
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
	Rhomb figure;
	figure.Input();
	figure.Print();
	system("pause");
	return 0;
}