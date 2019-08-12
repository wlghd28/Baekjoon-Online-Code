#include <stdio.h>
#include <stdlib.h>

/* 리모컨 문제
int Length(int N);
int Discrimination(int N, int start);
int button[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };// 멀쩡한 9개의 버튼
int Min(int Num1, int Num2, int Num3);
*/
/* 체스판 다시 칠하기
char board[50][50];
int Returncount(int row, int col); // 시작점을 입력받고 최소의 횟수를 반환하는 함수.
*/
//int EndNumber(int N); // 입력된 숫자에 6이 3개이상 연속되면 1, 아니면 0을 반환.
/*
int Decomposition(int N); // 분해합의 결과를 반환하는 함수.
int ReturnNum(int N); // 입력된 숫자의 가장 높은 자릿수의 숫자를 반환.
int Length(int N); // 입력된 숫자의 자릿수를 반환.
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

	/* 체스판 다시 칠하기
	int N, M, min = 64, count;
	scanf_s("%d %d", &N, &M);
	// 보드판 입력을 받는다.
	getchar();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//getchar();
			scanf_s(" %c", &board[i][j]);
		}
		getchar();
	}
	// 8*8 체스판을 자를수 있는 모든 경우의 수를 따진다.
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
	// 리모컨 문제
	/*
	int N, M, Num, flag = 0;
	int pluschannelcount = 0, minuschannelcount = 0, buttoncount = 0, pluschannel, minuschannel;
	scanf_s("%d", &N);
	scanf_s("%d", &M);
	pluschannel = N;
	minuschannel = N;
	for (int i = 0; i < M; i++) { // 고장난 버튼을 1로 변경.
		scanf_s("%d", &Num);
		button[Num] = 1;
	}
	// 단순히 +, - 만 이용해서 채널을 옮길 경우.
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
	// 버튼이 모두 고장났을 경우.
	if (M == 10) {
		flag = -1;
	}
	else {
		while (1) {
			// 원하는 채널에서부터 1씩 증가시키며 채널의 모든 번호가 고장이 안난 버튼의 번호인지 판단.
			if (pluschannelcount > 499900)
				break;
			if (Discrimination(pluschannel, pluschannel) == 1) {
				break;
			}
			pluschannel++; // 채널을 1씩 증가시킨다.
			pluschannelcount++; // 채널을 증가시킨 횟수
		}
		while (1) {
			// 원하는 채널에서부터 1씩 감소시키며 채널의 모든 번호가 고장이 안난 버튼의 번호인지 판단.
			if (minuschannel < 0)
				break;
			if (Discrimination(minuschannel, minuschannel) == 1) {
				break;
			}
			minuschannel--; // 채널을 1씩 감소시킨다.
			minuschannelcount++; // 채널을 감소시킨 횟수
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
	int* deck; // N개의 카드숫자들이 들어갈 배열.
	int* result; // 3개를 뽑은 숫자의 합이 들어갈 배열.
	scanf_s("%d %d", &N, &M);
	C = N * (N - 1) * (N - 2) / 6; // N개중 3개를 뽑는 경우의 수.
	deck = (int*)malloc(sizeof(int)*N);
	result = (int*)malloc(sizeof(int)*C);
	// N개의 숫자를 배열에 저장.
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &deck[i]);
	}
	// 3개의 숫자를 뽑는 모든 경우의 수를 합에서 M을 뺀 결과를 저장하는 배열에 저장.
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				result[index] = deck[i] + deck[j] + deck[k] - M;
				index++;
			}
		}
	}
	min = result[0]; // result배열중 최솟값을 구하기위한 초기화.
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
/* 체스판 다시칠하기
int Returncount(int row, int col)
{
	int whitecount = 0; // blackcount = 0;
	// 시작이 'W' 일 때
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
	//시작이 'B' 일 때
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
	// 두 경우중 더 작은 수를 반환.
	return whitecount > 32 ? 64 - whitecount : whitecount;
}
*/
/* 리모컨 문제
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