#include <stdio.h>
#include <stdlib.h>

//double AveragePropotion(int* Score, int N);
//int Max(int* Score, int N);

int main(void)
{

	/*
	//0보다 크거나 같고, 99보다 작거나 같은 정수가 주어질 때 다음과 같은 연산을 할 수 있다.
	//먼저 주어진 수가 10보다 작다면 앞에 0을 붙여 두 자리 수로 만들고, 각 자리의 숫자를 더한다.
	//그 다음, 주어진 수의 가장 오른쪽 자리 수와 앞에서 구한 합의 가장 오른쪽 자리 수를 
	//이어 붙이면 새로운 수를 만들 수 있다.다음 예를 보자.
	//26부터 시작한다. 2 + 6 = 8이다.새로운 수는 68이다. 6 + 8 = 14이다.
	//새로운 수는 84이다. 8 + 4 = 12이다.새로운 수는 42이다. 4 + 2 = 6이다.새로운 수는 26이다.
	//위의 예는 4번만에 원래 수로 돌아올 수 있다.따라서 26의 사이클의 길이는 4이다.
	//N이 주어졌을 때, N의 사이클의 길이를 구하는 프로그램을 작성하시오.

	int N, M = 100, cycle = 0;
	int A, B;
	scanf_s("%d", &N);

	M = N;
	do
	{
		A = M / 10 + M % 10;
		B = M % 10;
		M = 10 * B + A % 10;
		cycle++;
	} while (N != M);
	printf("%d\n", cycle);
	*/


	/*
	//세준이는 기말고사를 망쳤다.세준이는 점수를 조작해서 집에 가져가기로 했다.
	//일단 세준이는 자기 점수 중에 최댓값을 골랐다.이 값을 M이라고 한다.
	//그리고 나서 모든 점수를 점수 / M * 100으로 고쳤다.
	//예를 들어, 세준이의 최고점이 70이고, 수학점수가 50이었으면 수학점수는 
	//50 / 70 * 100이 되어 71.43점이 된다.
	//세준이의 성적을 위의 방법대로 새로 계산했을 때, 새로운 평균을 구하는 프로그램을 작성하시오.
	
	int N, M;
	double Total = 0;
	int* Score = NULL;
	scanf_s("%d", &N);

	Score = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &Score[i]);
		Total += Score[i];
	}
	M = Max(Score, N);
	printf("%.2f\n", (double)(Total*100 / N / M));
	*/

	/*
	//첫째 줄에는 테스트 케이스의 개수 C가 주어진다.
	//둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이
	//첫 수로 주어지고, 이어서 N명의 점수가 주어진다. 
	//점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.
	//각 케이스마다 한 줄씩 평균을 넘는 학생들의 비율을 반올림하여 소수점 셋째 자리까지 출력한다.

	int C, N;
	int* Score = NULL; // 학생들의 점수
	double* P = NULL; // 비율.
	scanf_s("%d", &C);

	P = (double*)malloc(sizeof(double)*C);

	for (int i = 0; i < C; i++)
	{
		scanf_s("%d", &N);
		Score = (int*)malloc(sizeof(int)*N);
		for (int j = 0; j < N; j++)
		{
			scanf_s("%d", &Score[j]);
		}
		P[i] = AveragePropotion(Score, N);
		free(Score);
	}

	for (int i = 0; i < C; i++)
	{
		printf("%.3f%%\n", P[i]);
	}

	free(P);
	*/
	/*
	int H, M;
	scanf_s("%d %d", &H, &M);

	if (M - 45 < 0) {
		H--;
		if (H < 0) {
			printf("%d %d\n", 24 + H, 15 + M);
		}
		else {
			printf("%d %d\n", H, 15 + M);
		}
	}
	else {
		printf("%d %d\n", H, M - 45);
	}
	*/
	return 0;
}
/*
double AveragePropotion(int* Score, int N)
{
	int index = 0, Total = 0;
	double average;
	for (int i = 0; i < N; i++)
	{
		Total += Score[i];
	}
	average = (double)Total / N;
	for (int i = 0; i < N; i++)
	{
		if (Score[i] > average)
		{
			index++;
		}
	}

	return (double)(100*index)/N;
}
*/
/*
int Max(int* Score, int N)
{
	int MAX;
	MAX = Score[0];

	for (int i = 1; i < N; i++)
	{
		if (Score[i] > MAX)
		{
			MAX = Score[i];
		}
	}

	return MAX;
}
*/