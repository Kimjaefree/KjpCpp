#include <iostream>

using namespace std;

void BmiProgram();
void GradeProgram();
void OddOrEvenProgram();

void main()
{
	// ���� 2���� �ڵ� ����
	// 1. BMI ���α׷�
	BmiProgram();
	// ��ü��������(BMI) = ü��(kg) / [����(m)]2
	// 2. ���� ����
	GradeProgram();
	// 3. Ȧ��¦�� ����
	OddOrEvenProgram();

	// 2���� ���� ȥ�ڼ� ���� ����
	// �Ϻ�����(O) 
}

void BmiProgram()
{
	float weight, height, bmi = 0.0f;

	cout << "Ű�� �Է����ּ���(m)" << endl;
	cin >> height;
	cout << "�����Ը� �Է����ּ��� (kg)" << endl;
	cin >> weight;

	bmi = weight / (height * height);
	cout << "BMI ���� : " << bmi << endl;

	if (bmi <= 18.5)
	{
		cout << "��ü��";
	}
	else if (bmi > 18.5 && bmi <= 23)
	{
		cout << "����ü��";
	}
	else if (bmi > 23 && bmi <=25)
	{
		cout << "��ü��";
	}
	else if (bmi > 25 && bmi <= 30)
	{
		cout << "��";
	}
	else
	{
		cout << "����";
	}
}
void GradeProgram()
{
	int midtermScore, finalScore, attendanceScore, assignmentScore, totalScore = 0;
	cout << "�߰��� ������ �Է����ּ��� " << endl;
	cin >> midtermScore;
	cout << "�⸻�� ������ �Է����ּ��� " << endl;
	cin >> finalScore;
	cout << "�⼮ ������ �Է����ּ��� " << endl;
	cin >> attendanceScore;
	cout << "���� ������ �Է����ּ��� " << endl;
	cin >> assignmentScore;

	totalScore = midtermScore + finalScore + attendanceScore + assignmentScore;
	
	if (totalScore < 60)
	{
		cout << "F";
	}
	else if (totalScore < 70 && totalScore >= 60)
	{
		cout << "D";
	}
	else if (totalScore < 80 && totalScore >= 70)
	{
		cout << "C";
	}
	else if (totalScore < 90 && totalScore >= 80)
	{
		cout << "B";
	}
	else if (totalScore <= 100 && totalScore >= 90)
	{
		cout << "A";
	}
}
void OddOrEvenProgram()
{
	int num = 0;

	cout << "������ �Է��ϼ���" << endl;
	cin >> num;
	if (num % 2 == 0)
	{
		cout << "¦���Դϴ�";
	}
	else
	{
		cout << "Ȧ���Դϴ�";
	}
}