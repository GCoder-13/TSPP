#include <iostream>
#include <conio.h>

using namespace std;

void Array(int* &A,int &n) {

	cout << "Input size array: ";
	if (!(cin >> n) || (n <= 0))
	{
		cout << endl << "\tIncorrect input";
		_getch();
		exit(0);
	}

	A = new int[n];
}

void DelArray(int *&A) {
	delete[] A;
}

void Input(int* &A, int n) {

	cout << "\t\t\t Complete array" << endl;

	for (int i(0); i < n; i++)
	{
		cout << "Input " << i + 1 << " number: ";
		if (!(cin >> A[i]))
		{
			cout << endl << "\tIncorrect input";
			_getch();
			exit(0);
		}
	}
}

void Output(int *A, int n) {

	cout << endl << "Array:";

	for (int i(0); i < n; i++)
		cout << "\t" << A[i];
}

void pMin(int *A, int n) {

	int min = A[n - 1], k=0;
	for (int i(0); i < n; i++)
	{
		if (A[i] > 0 && min >= A[i])
		{
			min = A[i];
			k++;
		}
	}

	if (k == 0)
		cout << endl << endl << "\t Don\'t have positive numbers" << endl;
	else cout << endl << endl << "MinPosNum = " << min << endl;
}

void Sort(int *A, int n) {

	int k = 0;
	for (int i(0); i < n; i++)
	{
		int x;
		if (A[i] & 1)
		{
			x = A[i];
			for (int j = i; j > 0; j--)
				A[j] = A[j - 1];
			A[0] = x;
			k++;
		}
	}

	for (int i(0); i < n; i++)
	{
		int c = A[i], j;
		if (i<k)
		{
			for (j = i - 1; j >= 0 && A[j] > c; j--)
				A[j + 1] = A[j];
			A[j + 1] = c;
		}
		else
		{
			for (j = k; j < n-1; j++)
			{
				if (A[j] < A[j + 1])
				{
					int t = A[j];
					A[j] = A[j + 1];
					A[j + 1] = t;
				}
			}
		}
	}
}

int main() {

	system("color F0");

	int *A, n;

	Array(*&A, n);
	Input(*&A, n);
	Output(A, n);
	pMin(A, n);
	Sort(A, n);
	Output(A, n);

	DelArray(*&A);
	
	_getch();
	return 0;
}