//площа поверхні циліндра
#include <iostream>

using namespace std;

int main()
{
	double S, h, R, Pi = 3.14159;

	cout << "Input R and h: ";
	cin >> R >> h;

	S = (Pi*R*R) * 2 + Pi*R*h;

	cout << "S=" << S;

	system("pause");
	return 0;
}