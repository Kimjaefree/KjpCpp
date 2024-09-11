#include <iostream>
#include "Vector.h"
using namespace std;

void main()
{
	Vector a;

	for (int i = 0; i < 10; i++)
	{
		a.push_back(i);
	}


	for (int i = 0; i < a.Size(); i++)
	{
		cout << a[i] << endl;
	}

	for (int i = 0; i < 5; i++)
	{
		a.pop_back();
	}

	cout << "---------------" << endl;
	for (int i = 0; i < a.Size(); i++)
	{
		cout << a[i] << endl;
	}
}