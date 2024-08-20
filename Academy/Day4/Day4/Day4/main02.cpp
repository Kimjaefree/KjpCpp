#include <iostream>

using namespace std;

void main()
{
	int a = 100;
	int b = 30;
	int swap = 0;

	printf("%d,%d", a, b);

    swap = a;
	a = b;
	b = swap;
	printf("%d,%d", a, b);
}