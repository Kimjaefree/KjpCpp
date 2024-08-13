#include <iostream>

using namespace std;

void BMI_Program()
{
	//BMI 측정 프로그램 1번 숙제
	float height, heightSwap, weight, bmi = 0; // 필요한 변수(키,몸무게,BMI) 선언	

	printf("키(m)를 입력해주세요 : "); // 키 수치 입력받기
	scanf_s("%f", &height);

	printf("몸무게(kg) 을 입력해주세요 : "); // 몸무게 수치 입력받기
	scanf_s("%f", &weight);

	heightSwap = height / 100;
	bmi = weight / (heightSwap * heightSwap); // bmi를 구하는 공식

	if (0 <= bmi < 18.5) // if문을 사용해 bmi에 따른 출력 결과 출력
	{
		printf("BMI 지수 : %.1f\n 저체중입니다.\n", bmi);
	}
	else if (bmi >= 18.5 && bmi < 23)
	{
		printf("BMI 지수 : %.1f\n 정상체중입니다.\n", bmi);
	}
	else if (bmi >= 23 && bmi < 25)
	{
		printf("BMI 지수 : %.1f\n 과체중입니다.\n", bmi);
	}
	else if (bmi >= 25 && bmi < 30)
	{
		printf("BMI 지수 : %.1f\n 비만입니다.\n", bmi);
	}
	else
	{
		printf("BMI 지수 : %.1f\n 고도비만입니다.\n", bmi);
	}
}
void grade_System() // 2번 숙제 학점 계산기
{
	int m_ExamScore, f_ExamScore, attendance_Score, assignment_Score, Total = 0;

	printf("중간평가 점수를 입력해주세요 : "); // 중간평가 점수 입력받기
	scanf_s("%d", &m_ExamScore);

	printf("기말평가 점수를 입력해주세요 : "); // 기말평가 점수 입력받기
	scanf_s("%d", &f_ExamScore);

	printf("출석점수를 입력해주세요 : "); // 출석 점수 입력받기
	scanf_s("%d", &attendance_Score);

	printf("과제 점수를 입력해주세요 : "); // 과제 점수 입력받기
	scanf_s("%d", &assignment_Score);

	Total = (m_ExamScore + f_ExamScore + attendance_Score + assignment_Score);
	
	if (Total< 60) // if문을 사용해 합산 점수에 따른 학점 출력
	{
		printf("F입니다.\n");
	}
	else if (Total >= 60 && Total < 70)
	{
		printf("D입니다.\n");
	}
	else if (Total >= 70 && Total < 80)
	{
		printf("C입니다.\n");
	}
	else if (Total >= 80 && Total < 90)
	{
		printf("B입니다.\n");
	}
	else if (Total >= 90 && Total <= 100)
	{
		printf("A입니다.\n");
	}
}
void odd_even_discriminator()
{
	int num = 0;

	printf("숫자를 입력해주세요 : ");
	scanf_s("%d", &num);

	if (num % 2 == 0)
	{
		printf("%d는 짝수입니다.", num);
	}
	else if (num % 2 == 1)
	{
		printf("%d는 홀수입니다.", num);
	}
}

void main()
{
	BMI_Program();
	grade_System();
	odd_even_discriminator();
}



	