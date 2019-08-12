#include <stdio.h>

// 프랙탈 모형으로 별찍기
/*
char arr[6144][3072];
void Fractal(int N, int x, int y); // 프랙탈 도형 만들기.
void ValueStar(int N, int M, int x, int y); // 공백으로 되있는 배열에 *을 채워넣는 함수.
void PrintStar(int N);
void PrintTriangle(int x, int y);
void PrintEmpty(int x, int y);
*/
//char arr[2187][2187];
//void PrintEmpty(int N, int istart, int jstart);
//int ReturnNumber(int N);
//int KaprekarNumber(int N);
//int SelfNumber(int N, int* S, int size);
//long long factorial(int N);
//int TotalCount = 1;
void HanoiTop(int count1, int count2, int N, int A, int B);
int Count(int N);
int main(void)
{
	int N;
	scanf_s("%d", &N);

	printf("%d\n", Count(N));
	HanoiTop(1, 1, N, 1, 3);


	/*
	int N;
	scanf_s("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = '*';
		}
	}
	PrintEmpty(N, 0, 0);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	*/
	/*
	int N;
	scanf_s("%d", &N);

	factorial(N);
	*/
	/*
	int S[10000] = { 0 };
	for (int i = 0; i < 10000; i++)
	{
		S[i] = KaprekarNumber(i);
	}
	for (int i = 0; i < 10000; i++)
	{
		if (SelfNumber(i, S, 10000) == 0)
			printf("%d\n", i);
	}
	*/
	// 한수 갯수 구하기
	/*
	int N;
	scanf_s("%d", &N);

	int index = 0, M = 1;
	while (M < N + 1)
	{
		if (ReturnNumber(M) == 1)
			index++;
		++M;
	}	
	printf("%d\n", index);
	*/


	// 프랙탈 모형 출력하기.
	/*
	int N;
	scanf_s("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N * 2; j++)
		{
			arr[j][i] = ' ';
		}
	}

	ValueStar(N, 1, N - 3, 0);
	Fractal(N, N, N);
	PrintStar(N);
	*/

	return 0;
}
void HanoiTop(int count1, int count2, int N, int A, int B)
{
	if (count1 > N || count2 > N) 
		return;
	if (A == 1 && B == 3) {
		HanoiTop(++count1, count2, N, 1, 2);
		printf("1 3\n");
		HanoiTop(count1, ++count2, N, 2, 3);
	}
	else if (A == 1 && B == 2) {
		HanoiTop(++count1, count2, N, 1, 3);
		printf("1 2\n");
		HanoiTop(count1, ++count2, N, 3, 2);
	}
	else if (A == 3 && B == 2) {
		HanoiTop(++count1, count2, N, 3, 1);
		printf("3 2\n");
		HanoiTop(count1, ++count2, N, 1, 2);
	}
	else if (A == 2 && B == 1) {
		HanoiTop(++count1, count2, N, 2, 3);
		printf("2 1\n");
		HanoiTop(count1, ++count2, N, 3, 1);
	}
	else if (A == 2 && B == 3) {
		HanoiTop(++count1, count2, N, 2, 1);
		printf("2 3\n");
		HanoiTop(count1, ++count2, N, 1, 3);
	}
	else if (A == 3 && B == 1){
		HanoiTop(++count1, count2, N, 3, 2);
		printf("3 1\n");
		HanoiTop(count1, ++count2, N, 2, 1);
	}
} 
int Count(int N)
{
	int count = 1;
	for (int i = 0; i < N; i++) {
		count *= 2;
	}
	return count - 1;
}
/*
void PrintEmpty(int N, int istart, int jstart)
{
	for (int i = istart + N / 3; i < istart + (N / 3) * 2; i++) {
		for (int j = jstart + N / 3; j < jstart + (N / 3) * 2; j++) {
			arr[i][j] = ' ';
		}
	}
	if (N == 3)
		return;
	PrintEmpty(N / 3, istart, jstart);
	PrintEmpty(N / 3, istart + N / 3, jstart);
	PrintEmpty(N / 3, istart + (N / 3) * 2, jstart);
	PrintEmpty(N / 3, istart, jstart + N / 3);
	PrintEmpty(N / 3, istart + (N / 3) * 2, jstart + N / 3);
	PrintEmpty(N / 3, istart, jstart + (N / 3) * 2);
	PrintEmpty(N / 3, istart + N / 3, jstart + (N / 3) * 2);
	PrintEmpty(N / 3, istart + (N / 3) * 2, jstart + (N / 3) * 2);

}
*/
/*
long long factorial(int N)
{
	long long total = 1;
	for (int i = 0; i < N; i++) {
		total *= N - i;
	}
	return total;
}
*/
/*
int SelfNumber(int N, int* S, int size)
{
	for (int i = 0; i < 10000; i++)
	{
		if (N == S[i])
			return 1;
			
	}
	return 0;
}
*/
/*
int KaprekarNumber(int N)
{
	int M;
	if (N < 10)
	{
		M = N;
	}
	else if (N < 100)
	{
		M = (int)N / 100 + (int)(N % 100) / 10 + N % 10;
	}
	else if (N < 1000)
	{
		M = (int)N / 1000 + (int)(N % 1000) / 100 + (int)(N % 100) / 10 + N % 10;
	}
	else if (N < 10000)
	{
		M = (int)N / 10000 + (int)(N % 10000) / 1000 + (int)(N % 1000) / 100 + (int)(N % 100) / 10 + N % 10;
	}
	else
		M = 1;

	return N + M;
}
*/
/*
int ReturnNumber(int N)
{
	if (N < 100)
	{
		return 1;
	}
	else if (N < 1000)
	{
		if (((N % 10) - (int)(N % 100) / 10) == ((int)(N % 100) / 10 - (int)(N / 100)))
			return 1;
		else
			return 0;
	}
	else
	{
		return 0;
	}
}
*/
/*
void Fractal(int N, int x, int y)
{
	if (N == 3)
		return;
	int k, h, g;
	g = x - N / 2 + 3;
	h = y - N / 2;
	for (int i = N / 6 - 1; i > 0; i--)
	{
		k = g;
		for (int j = 0; j < i; j++)
		{
			PrintEmpty(k, h);
			k += 6;
		}
		h += 3;
		g += 3;
	}
	Fractal(N / 2, x, y - N / 2);
	Fractal(N / 2, x - N / 2, y);
	Fractal(N / 2, x + N / 2, y);
}
void ValueStar(int N, int M, int x, int y)
{
	if (M > N/3)
		return;
	int k;
	k = x;
	for (int i = 0; i < M; i++)
	{
		PrintTriangle(k, y);
		k += 6;
	}
	ValueStar(N, ++M, x - 3, y + 3);
}
void PrintTriangle(int x, int y)// 별을 채워넣는 함수.
{
	arr[x + 2][y] = '*';
	arr[x + 1][y + 1] = '*';
	arr[x + 3][y + 1] = '*';
	for (int i = x; i < x + 5; i++)
	{
		arr[i][y + 2] = '*';
	}	
}
void PrintEmpty(int x, int y) // 공백으로 만드는 함수.
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			arr[x + j][y + i] = ' ';
		}
	}
}
void PrintStar(int N)
{
	// 배열 최종 출력.
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N * 2; j++)
		{
			printf("%c", arr[j][i]);
		}
		printf("\n");
	}
}
*/


