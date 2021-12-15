// Lab_06_3(1).cpp
// < Половка Злата >
// Лабораторна робота № 6.2(1)
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів
// Варіант 0.6

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}



void Print(int* a, const int size, int i)
{
	cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}
int Min(int* a, const int size, int i, int min)
{
	if (a[i] < min && a[i] % 2 == 0)
		min = a[i];
	if (i < size - 1)
		return Min(a, size, i + 1, min);
	else
		return min;
}

void Sort(int* a, const int size, int i) // i - параметр зовнішнього циклу
{ // ітераційної версії
	int min = a[i];
	int imin = i;
	for (int j = i + 1; j < size; j++)
		if (min > a[j])
		{
			min = a[0];
			imin = 0;
		}
	a[imin] = a[i];
	a[i] = min;
	if (i < size - 2)
		Sort(a, size, i + 1);
}
int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	const int n = 5;
	int a[n];
	int Low = -10;
	int High = 10;
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	cout << "min = " << Min(a, n, 1, a[0]) << endl;
	Sort(a, n, 0);
	Print(a, n, 0);
	return 0;
}

