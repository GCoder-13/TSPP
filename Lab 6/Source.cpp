#include <iostream>

using namespace std;

class Vector
{
	private:
		int x, y, z;
	public:
		Vector() : x(0), y(0), z(0) {};
		Vector(int xx, int yy, int zz): x(xx), y(yy), z(zz) {};
		Vector operator+(Vector &p);
		void operator<<(Vector &p);
};

Vector Vector::operator+(Vector &p)
{
	Vector temp;
	temp.x = x + p.x;
	temp.y = y + p.y;
	temp.z = z + p.z;
	return Vector();
}

void Vector::operator<<(Vector &p)
{
	cout << p.x << endl;
	cout << p.y << endl;
	cout << p.z << endl;
}

int main()
{
	system("color f0");
	int x, y, z;
	Vector vek;

	cout << "Input vector (x,y,z): ";
	cin >> x >> y >> z;
	Vector vek1(x, y, z);

	cout << "Input vector (x,y,z): ";
	cin >> x >> y >> z;
	Vector vek2(x, y, z);

	vek = vek1 + vek2;

	cout << vek;

	system("pause");
	return 0;
}