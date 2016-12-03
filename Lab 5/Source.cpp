//Лаб-5. Дружні-функції та дружні-класи
#include <iostream>

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
	int min, k;

	min = (Obj_1.a < Obj_1.b) ? Obj_1.a : Obj_1.b;
	min = (min < Obj_1.c) ? min : Obj_1.c;

	for (int i(2); i < min; i++)
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
	cout << "Input three number: ";
	cin >> a >> b >> c;
	Drug Obj_1(a,b,c);

	cout << endl << "\t Max divide: " << Divide(Obj_1) << endl;

	system("pause");
	return 0;
}