#include <stdio.h>
#include <stdlib.h>

//double AveragePropotion(int* Score, int N);
//int Max(int* Score, int N);

int main(void)
{

	/*
	//0���� ũ�ų� ����, 99���� �۰ų� ���� ������ �־��� �� ������ ���� ������ �� �� �ִ�.
	//���� �־��� ���� 10���� �۴ٸ� �տ� 0�� �ٿ� �� �ڸ� ���� �����, �� �ڸ��� ���ڸ� ���Ѵ�.
	//�� ����, �־��� ���� ���� ������ �ڸ� ���� �տ��� ���� ���� ���� ������ �ڸ� ���� 
	//�̾� ���̸� ���ο� ���� ���� �� �ִ�.���� ���� ����.
	//26���� �����Ѵ�. 2 + 6 = 8�̴�.���ο� ���� 68�̴�. 6 + 8 = 14�̴�.
	//���ο� ���� 84�̴�. 8 + 4 = 12�̴�.���ο� ���� 42�̴�. 4 + 2 = 6�̴�.���ο� ���� 26�̴�.
	//���� ���� 4������ ���� ���� ���ƿ� �� �ִ�.���� 26�� ����Ŭ�� ���̴� 4�̴�.
	//N�� �־����� ��, N�� ����Ŭ�� ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

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
	//�����̴� �⸻��縦 ���ƴ�.�����̴� ������ �����ؼ� ���� ��������� �ߴ�.
	//�ϴ� �����̴� �ڱ� ���� �߿� �ִ��� �����.�� ���� M�̶�� �Ѵ�.
	//�׸��� ���� ��� ������ ���� / M * 100���� ���ƴ�.
	//���� ���, �������� �ְ����� 70�̰�, ���������� 50�̾����� ���������� 
	//50 / 70 * 100�� �Ǿ� 71.43���� �ȴ�.
	//�������� ������ ���� ������ ���� ������� ��, ���ο� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	
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
	//ù° �ٿ��� �׽�Ʈ ���̽��� ���� C�� �־�����.
	//��° �ٺ��� �� �׽�Ʈ ���̽����� �л��� �� N(1 �� N �� 1000, N�� ����)��
	//ù ���� �־�����, �̾ N���� ������ �־�����. 
	//������ 0���� ũ�ų� ����, 100���� �۰ų� ���� �����̴�.
	//�� ���̽����� �� �پ� ����� �Ѵ� �л����� ������ �ݿø��Ͽ� �Ҽ��� ��° �ڸ����� ����Ѵ�.

	int C, N;
	int* Score = NULL; // �л����� ����
	double* P = NULL; // ����.
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