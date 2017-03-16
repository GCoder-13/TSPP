#include <iostream>
#include <cmath>

using namespace std;

/* Підраховує кількість елементів масиву які кратні 5 */
template <typename T>
int Func(T* arr, const size_t length)
{
	int count = 0;
	for (size_t i = 0; i < length; i++)
	{
		if ((arr[i] / 5) == (static_cast<int>(arr[i] / 5)))
			count++;
	}
	return count;
}

int main(int argc, char** argv)
{
	const size_t MAX = 5;
	double arr[MAX] = { 120, 5, -25.5 , -15.0, 25.0 };

	cout << "Number of array elements that are multiples of 5: " << Func(arr, MAX) << endl;

	system("pause");
	return 0;
}