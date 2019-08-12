#include <stdio.h>
#include <stdlib.h>

/* ������ ����
int Length(int N);
int Discrimination(int N, int start);
int button[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };// ������ 9���� ��ư
int Min(int Num1, int Num2, int Num3);
*/
/* ü���� �ٽ� ĥ�ϱ�
char board[50][50];
int Returncount(int row, int col); // �������� �Է¹ް� �ּ��� Ƚ���� ��ȯ�ϴ� �Լ�.
*/
//int EndNumber(int N); // �Էµ� ���ڿ� 6�� 3���̻� ���ӵǸ� 1, �ƴϸ� 0�� ��ȯ.
/*
int Decomposition(int N); // �������� ����� ��ȯ�ϴ� �Լ�.
int ReturnNum(int N); // �Էµ� ������ ���� ���� �ڸ����� ���ڸ� ��ȯ.
int Length(int N); // �Էµ� ������ �ڸ����� ��ȯ.
*/
int HK[50][2];
int Ranking[50];
int Rank(int N, int H, int K);
int main(void)
{
	int N;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d %d", &HK[i][0], &HK[i][1]);
	}
	for (int i = 0; i < N; i++) {
		Ranking[i] = Rank(N, HK[i][0], HK[i][1]);
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", Ranking[i]);
	}


	/*
	int N, Num, flag = 0;
	scanf_s("%d", &N);
	Num = N - ((ReturnNum(N) - 1) + 9 * (Length(N) - 1));
	while (Num < N) {
		if (Decomposition(Num) + Num == N) {
			flag = 1;
			break;
		}
		Num++;
	}
	if (flag == 0)
		printf("0\n");
	else
		printf("%d\n", Num);
	*/

	/*
	int N, count = 0, Num = 666;
	scanf_s("%d", &N);

	while (1) {
		if (EndNumber(Num) == 1)
			count++;
		if (count == N)
			break;
		Num++;
	}
	printf("%d\n", Num);
	*/

	/* ü���� �ٽ� ĥ�ϱ�
	int N, M, min = 64, count;
	scanf_s("%d %d", &N, &M);
	// ������ �Է��� �޴´�.
	getchar();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//getchar();
			scanf_s(" %c", &board[i][j]);
		}
		getchar();
	}
	// 8*8 ü������ �ڸ��� �ִ� ��� ����� ���� ������.
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			count = Returncount(i, j);
			if (count < min)
				min = count;
			if (min == 0)
				break;
		} 
	}

	printf("%d\n", min);
	*/
	// ������ ����
	/*
	int N, M, Num, flag = 0;
	int pluschannelcount = 0, minuschannelcount = 0, buttoncount = 0, pluschannel, minuschannel;
	scanf_s("%d", &N);
	scanf_s("%d", &M);
	pluschannel = N;
	minuschannel = N;
	for (int i = 0; i < M; i++) { // ���峭 ��ư�� 1�� ����.
		scanf_s("%d", &Num);
		button[Num] = 1;
	}
	// �ܼ��� +, - �� �̿��ؼ� ä���� �ű� ���.
	if (N > 100) {
		buttoncount = N - 100;
	}
	else if (N == 100) {
		printf("0\n");
		return 0;
	}
	else {
		buttoncount = 100 - N;
	}
	// ��ư�� ��� ���峵�� ���.
	if (M == 10) {
		flag = -1;
	}
	else {
		while (1) {
			// ���ϴ� ä�ο������� 1�� ������Ű�� ä���� ��� ��ȣ�� ������ �ȳ� ��ư�� ��ȣ���� �Ǵ�.
			if (pluschannelcount > 499900)
				break;
			if (Discrimination(pluschannel, pluschannel) == 1) {
				break;
			}
			pluschannel++; // ä���� 1�� ������Ų��.
			pluschannelcount++; // ä���� ������Ų Ƚ��
		}
		while (1) {
			// ���ϴ� ä�ο������� 1�� ���ҽ�Ű�� ä���� ��� ��ȣ�� ������ �ȳ� ��ư�� ��ȣ���� �Ǵ�.
			if (minuschannel < 0)
				break;
			if (Discrimination(minuschannel, minuschannel) == 1) {
				break;
			}
			minuschannel--; // ä���� 1�� ���ҽ�Ų��.
			minuschannelcount++; // ä���� ���ҽ�Ų Ƚ��
		}
	}
	if (flag == -1)
		printf("%d\n", buttoncount);
	else {
		if (minuschannel < 0)
			pluschannelcount + Length(pluschannel) < buttoncount ? printf("%d\n", pluschannelcount + Length(pluschannel)) : printf("%d\n", buttoncount);
		else
			printf("%d\n", Min(pluschannelcount + Length(pluschannel), minuschannelcount + Length(minuschannel), buttoncount));
	}
	*/

	/*
	int N, M, C, min, index = 0;
	int* deck; // N���� ī����ڵ��� �� �迭.
	int* result; // 3���� ���� ������ ���� �� �迭.
	scanf_s("%d %d", &N, &M);
	C = N * (N - 1) * (N - 2) / 6; // N���� 3���� �̴� ����� ��.
	deck = (int*)malloc(sizeof(int)*N);
	result = (int*)malloc(sizeof(int)*C);
	// N���� ���ڸ� �迭�� ����.
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &deck[i]);
	}
	// 3���� ���ڸ� �̴� ��� ����� ���� �տ��� M�� �� ����� �����ϴ� �迭�� ����.
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				result[index] = deck[i] + deck[j] + deck[k] - M;
				index++;
			}
		}
	}
	min = result[0]; // result�迭�� �ּڰ��� ���ϱ����� �ʱ�ȭ.
	for (int i = 0; i < C; i++) {
		if (min > 0)
			min = 0 - M;
		if (result[i] == 0) {
			index = i;
			break;
		}
		if (min < result[i] && result[i] < 0) {
			min = result[i];
			index = i;
		}
	}

	printf("%d\n", result[index] + M);


	free(deck);
	free(result);
	*/
	return 0;
}
int Rank(int N, int H, int K)
{
	int ranking = 0;
	for (int i = 0; i < N; i++) {
		if (H < HK[i][0] && K < HK[i][1])
			ranking++;
	}
	return ranking + 1;
}
/*
int Decomposition(int N)
{
	int tmp = 0;
	while (1) {
		tmp += N % 10;
		N /= 10;
		if (N == 0)
			return tmp;
	}
}
int ReturnNum(int N)
{
	int number;
	while (1) {
		number = N % 10;
		N /= 10;
		if (N == 0)
			return number;
	}
}
int Length(int N)
{
	int count = 0;
	while (1) {
		N /= 10;
		count++;
		if (N == 0)
			return count;
	}
}
*/
/*
int EndNumber(int N)
{
	int flag = 0, count = 0;
	while (N > 0) {
		if (N % 10 == 6 && flag == 0) {
			count++;
			flag = 1;
		}
		else if (N % 10 == 6 && flag == 1) {
			count++;
		}
		else {
			count = 0;
			flag = 0;
		}
		if (count == 3)
			return 1;
		N /= 10;
	}
	return 0;
}
*/
/* ü���� �ٽ�ĥ�ϱ�
int Returncount(int row, int col)
{
	int whitecount = 0; // blackcount = 0;
	// ������ 'W' �� ��
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 8; j++) {
				if (j % 2 == 0 && board[row + i][col + j] != 'W')
					whitecount++;
				else if (j % 2 == 1 && board[row + i][col + j] != 'B')
					whitecount++;
			}
		}
		else {
			for (int j = 0; j < 8; j++) {
				if (j % 2 == 0 && board[row + i][col + j] != 'B')
					whitecount++;
				else if (j % 2 == 1 && board[row + i][col + j] != 'W')
					whitecount++;
			}
		}
	}
	//������ 'B' �� ��
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 8; j++) {
				if (j % 2 == 0 && board[row + i][col + j] != 'B')
					whitecount++;
				if (j % 2 == 1 && board[row + i][col + j] != 'W')
					whitecount++;
			}
		}
		else {
			for (int j = 0; j < 8; j++) {
				if (j % 2 == 0 && board[row + i][col + j] != 'W')
					whitecount++;
				if (j % 2 == 1 && board[row + i][col + j] != 'B')
					whitecount++;
			}
		}
	}
	// �� ����� �� ���� ���� ��ȯ.
	return whitecount > 32 ? 64 - whitecount : whitecount;
}
*/
/* ������ ����
int Discrimination(int N, int start)
{
	if (start == 0) {
		if (button[start] == 0)
			return 1;
		else
			return 0;
	}
	while (1)
	{
		if (N == 0)
			return 1;
		if (button[N % 10] == 0)
			N /= 10;
		else
			return 0;
	}
}
int Length(int N)
{
	int count = 0;
	while (1) {
		N /= 10;
		count++;
		if (N == 0)
			return count;
	}
}
int Min(int Num1, int Num2, int Num3)
{
	int min = Num1;
	if (min > Num2)
		min = Num2;
	if (min > Num3)
		min = Num3;
	return min;
}
*/