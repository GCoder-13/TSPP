//����������� � 4 ����
#include <iostream>
#include <conio.h>

using namespace std;

int main() {

	double a, b, c, d, max;

	cout << "Input four numbers: ";
	cin >> a >> b >> c >> d;

	max = (a > b) ? a : b;
	max = (max < c) ? c : max;
	max = (max < d) ? d : max;

	cout << "Max nubber: " << max << endl;

	_getch();
	return 0;
}