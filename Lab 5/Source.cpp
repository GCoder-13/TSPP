//Лаб-5. Дружні-функції та дружні-класи
#include <iostream>
#include <cmath>

using namespace std;

class Drug
{
	private:
		int a, b, c;
	public:
		Drug() : a(0), b(0), c(0) {};
		Drug(int aa, int bb, int cc): a(aa), b(bb), c(cc) {};
		friend int Divide(Drug);
};

int Divide(Drug Obj_1)
{
	int min,tmin, k;

	min = (Obj_1.a <= Obj_1.b) ? Obj_1.a : Obj_1.b;
	if (!min)	
		min = (Obj_1.a >= Obj_1.b) ? Obj_1.a : Obj_1.b;
	tmin = (min <= Obj_1.c) ? min : Obj_1.c;
	if (!tmin)	
		min = (Obj_1.c >= min) ? Obj_1.c : min;
	else min = tmin;
	if (!min)
		return 1;

	for (int i(1); i <= abs(min); i++)
	{
		if (Obj_1.a % i) continue;
		if (Obj_1.b % i) continue;
		if (Obj_1.c % i) continue;
		
		k = i;
	}
	return k;
}

int main()
{
	system("color f0");
	int a, b, c;
	cout << "Enter three number: ";
	if (!(cin >> a >> b >> c))
	{
		cout << "\t Incorrect enter!!!" << endl;
		system("pause");
		exit(-1);
	}
	Drug Obj_1(a,b,c);

	cout << endl << "\t Max divide: " << Divide(Obj_1) << endl;

	system("pause");
	return 0;
}