#include <iostream>

using namespace std;

void main()
{
	printf("키(m)를 입력해주세요.\n");

	float height = 0.0;
	scanf_s("%f", &height);

	printf("몸무게(kg)을 입력해주세요. \n");

	float weight = 0.0;
	scanf_s("%f", &weight);

	float bmi = 0.0;
	bmi = weight / (height) * (height);
}