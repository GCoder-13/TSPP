//Лаб-6. Перевантаження бінарних операторів
#include <iostream>
#include <iomanip>

using namespace std;

struct point
{
	int x, y, z;
};

point operator+(point& l, point& r)
{
	point temp;
	temp.x = l.x + r.x;
	temp.y = l.y + r.y;
	temp.z = l.z + r.z;
	return temp;
}

point operator+(point& l, int& a)
{
	point temp;
	temp.x = l.x + a;
	temp.y = l.y + a;
	temp.z = l.z + a;
	return temp;
}

point operator+(int& a, point& r)
{
	return r+a;
}

ostream& operator<<(ostream& os, point &p)
{
	cout << "(" << p.x << ";" << p.y << ";" << p.z << ")";
	return os;
}

istream& operator>>(istream& is, point &p)
{
	cin >> p.x >> p.y >> p.z;
	return is;
}

class Vector
{
	private:
		point st, fn;
	public:
		Vector() : st({ 0, 0, 0 }), fn({ 0, 0, 0 }) {};
		Vector(point a, point b): st(a), fn(b) {};
		void cInput();
		Vector operator+(Vector &p);
		Vector operator+(int a);
		friend ostream& operator<<(ostream& os, Vector &p);
};

void Vector::cInput()
{
	cout << "Enter the vector beginning (x;y;z): ";
	cin >> st;
	cout << "Enter the vectors end (x,y,z): ";
	cin >> fn;
}

Vector Vector::operator+(Vector& p)
{
	Vector temp;
	temp.st = st + p.st;
	temp.fn = fn + p.fn;
	return temp;
}

Vector Vector::operator+(int a)
{
	Vector temp;
	temp.st = st + a;
	temp.fn = fn + a;
	return temp;
}

Vector operator+(int a, Vector& p)
{
	return p + a;
}

ostream& operator<<(ostream& os, Vector &p)
{
	cout << endl << setw(10) << "Begin: " << p.st
		<< endl << setw(10) << "End: " << p.fn;
	return os;
}

int main()
{
	system("color f0");
	Vector vek1,vek2,vek3;

	cout << "\t Input vector AB" << endl;
	vek1.cInput();
	cout << "\t Input vector CD" << endl;
	vek2.cInput();

	vek3 = vek1 + vek2;
	cout << endl << "The sum of two vectors: " << vek3 << endl;

	vek3 = vek1 + 4;
	cout << endl << "Vector (AB + 4)" << vek3 << endl;

	vek3 = 2 + vek2;
	cout << endl << "Vector (2 + CD)" << vek3 << endl;

	system("pause");
	return 0;
}