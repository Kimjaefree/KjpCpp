#include <iostream>

using namespace std;

void BMI_Program()
{
	//BMI ���� ���α׷� 1�� ����
	float height, heightSwap, weight, bmi = 0; // �ʿ��� ����(Ű,������,BMI) ����	

	printf("Ű(m)�� �Է����ּ��� : "); // Ű ��ġ �Է¹ޱ�
	scanf_s("%f", &height);

	printf("������(kg) �� �Է����ּ��� : "); // ������ ��ġ �Է¹ޱ�
	scanf_s("%f", &weight);

	heightSwap = height / 100;
	bmi = weight / (heightSwap * heightSwap); // bmi�� ���ϴ� ����

	if (0 <= bmi < 18.5) // if���� ����� bmi�� ���� ��� ��� ���
	{
		printf("BMI ���� : %.1f\n ��ü���Դϴ�.\n", bmi);
	}
	else if (bmi >= 18.5 && bmi < 23)
	{
		printf("BMI ���� : %.1f\n ����ü���Դϴ�.\n", bmi);
	}
	else if (bmi >= 23 && bmi < 25)
	{
		printf("BMI ���� : %.1f\n ��ü���Դϴ�.\n", bmi);
	}
	else if (bmi >= 25 && bmi < 30)
	{
		printf("BMI ���� : %.1f\n ���Դϴ�.\n", bmi);
	}
	else
	{
		printf("BMI ���� : %.1f\n �����Դϴ�.\n", bmi);
	}
}
void grade_System() // 2�� ���� ���� ����
{
	int m_ExamScore, f_ExamScore, attendance_Score, assignment_Score, Total = 0;

	printf("�߰��� ������ �Է����ּ��� : "); // �߰��� ���� �Է¹ޱ�
	scanf_s("%d", &m_ExamScore);

	printf("�⸻�� ������ �Է����ּ��� : "); // �⸻�� ���� �Է¹ޱ�
	scanf_s("%d", &f_ExamScore);

	printf("�⼮������ �Է����ּ��� : "); // �⼮ ���� �Է¹ޱ�
	scanf_s("%d", &attendance_Score);

	printf("���� ������ �Է����ּ��� : "); // ���� ���� �Է¹ޱ�
	scanf_s("%d", &assignment_Score);

	Total = (m_ExamScore + f_ExamScore + attendance_Score + assignment_Score);
	
	if (Total< 60) // if���� ����� �ջ� ������ ���� ���� ���
	{
		printf("F�Դϴ�.\n");
	}
	else if (Total >= 60 && Total < 70)
	{
		printf("D�Դϴ�.\n");
	}
	else if (Total >= 70 && Total < 80)
	{
		printf("C�Դϴ�.\n");
	}
	else if (Total >= 80 && Total < 90)
	{
		printf("B�Դϴ�.\n");
	}
	else if (Total >= 90 && Total <= 100)
	{
		printf("A�Դϴ�.\n");
	}
}
void odd_even_discriminator()
{
	int num = 0;

	printf("���ڸ� �Է����ּ��� : ");
	scanf_s("%d", &num);

	if (num % 2 == 0)
	{
		printf("%d�� ¦���Դϴ�.", num);
	}
	else if (num % 2 == 1)
	{
		printf("%d�� Ȧ���Դϴ�.", num);
	}
}

void main()
{
	BMI_Program();
	grade_System();
	odd_even_discriminator();
}



	