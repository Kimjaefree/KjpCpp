#include <iostream>

using namespace std;

void main()
{
	printf("Ű(m)�� �Է����ּ���.\n");

	float height = 0.0;
	scanf_s("%f", &height);

	printf("������(kg)�� �Է����ּ���. \n");

	float weight = 0.0;
	scanf_s("%f", &weight);

	float bmi = 0.0;
	bmi = weight / (height) * (height);
}