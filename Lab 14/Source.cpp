#include <iostream>

using namespace std;

float Ex_1_1()
{
	int a = 5;
	int b = 3;
	int c = 1;
	float c1;
	c1 = static_cast<float>(a) / b - c;
	return c1;
}

float Ex_1_2()
{
	int a2 = 8;
	int b2 = 2;
	int c2;
	c2 = static_cast<float>(a2 + 1) / b2 + 1.5;
	return c2;
}

unsigned char Ex_1_3()
{
	unsigned char a3 = 180;
	unsigned char c3;
	c3 = a3 * static_cast<char>(3);
	return c3;
}

unsigned short Ex_1_4()
{
	unsigned char a4 = 1;
	unsigned short c4;
	c4 = static_cast<short>(a4) - 2;
	return c4;
}

int main()
{
	printf_s("Ex-1.1 = %f \n", Ex_1_1());
	printf_s("Ex-1.2 = %f \n", Ex_1_2());
	printf_s("Ex-1.3 = %c \n", Ex_1_3());
	printf_s("Ex-1.4 = %u \n", Ex_1_4());
	cout << endl;

	int j, b = 5, a = 4, c = 3; 
	j = b-- - a-- - c;
	printf_s("Ex-2.1 = %i \n", j);

	float k = 18 - (2 * (float)5) / 3;
	printf_s("Ex-2.2 = %f \n", k);

	int x = 14 + 74;
	cout << "Ex-2.3(oct) = " << oct << x << endl;
	cout << "Ex-2.3(dec) = " << dec << x << endl;
	cout << "Ex-2.3(hex) = " << hex << x << endl;

	system("pause");
	return 0;
}