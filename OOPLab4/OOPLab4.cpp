// OOPLab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "fibonacci.h"

int main()
{
	fibonacci<int> a(10);
	auto iter = a.cbegin();
	cout << *iter << endl;
	iter+=5;
	cout << *iter << endl;
	system("pause");

    return 0;
}

