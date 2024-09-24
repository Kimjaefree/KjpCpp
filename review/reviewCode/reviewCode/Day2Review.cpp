#include <iostream>

using namespace std;

void BmiProgram();
void GradeProgram();
void OddOrEvenProgram();

void main()
{
	// 수업 2일차 코드 복습
	// 1. BMI 프로그램
	BmiProgram();
	// 신체질량지수(BMI) = 체중(kg) / [신장(m)]2
	// 2. 학점 계산기
	GradeProgram();
	// 3. 홀수짝수 계산기
	OddOrEvenProgram();

	// 2일차 숙제 혼자서 구현 가능
	// 완벽숙지(O) 
}

void BmiProgram()
{
	float weight, height, bmi = 0.0f;

	cout << "키를 입력해주세요(m)" << endl;
	cin >> height;
	cout << "몸무게를 입력해주세요 (kg)" << endl;
	cin >> weight;

	bmi = weight / (height * height);
	cout << "BMI 지수 : " << bmi << endl;

	if (bmi <= 18.5)
	{
		cout << "저체중";
	}
	else if (bmi > 18.5 && bmi <= 23)
	{
		cout << "정상체중";
	}
	else if (bmi > 23 && bmi <=25)
	{
		cout << "과체중";
	}
	else if (bmi > 25 && bmi <= 30)
	{
		cout << "비만";
	}
	else
	{
		cout << "고도비만";
	}
}
void GradeProgram()
{
	int midtermScore, finalScore, attendanceScore, assignmentScore, totalScore = 0;
	cout << "중간평가 점수를 입력해주세요 " << endl;
	cin >> midtermScore;
	cout << "기말평가 점수를 입력해주세요 " << endl;
	cin >> finalScore;
	cout << "출석 점수를 입력해주세요 " << endl;
	cin >> attendanceScore;
	cout << "과제 점수를 입력해주세요 " << endl;
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

	cout << "정수를 입력하세요" << endl;
	cin >> num;
	if (num % 2 == 0)
	{
		cout << "짝수입니다";
	}
	else
	{
		cout << "홀수입니다";
	}
}