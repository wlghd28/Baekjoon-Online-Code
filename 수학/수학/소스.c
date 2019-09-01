#include <stdio.h>

int check[10] = { 0,0,0,0,0,0,0,0,0,0 };
int Number[20] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 }; // 입력받은 자연수를 자릿수별로 저장.
int Number2[20] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 }; // 답이 들어갈 배열.
int Bubble[11] = { 10,10,10,10,10,10,10,10,10,10,10 }; // K자리 까지 오는 숫자들을 오름차순으로 정렬.
int ReturnNumber(long long N); // 입력된 자연수를 이루는 숫자의 갯수를 반환.
                               // 입력된 자연수를 배열로 넣는 역할.
int Min(int Number[], int size); // 자연수의 자리숫자 중에 최솟값을 반환.
int Length(long long N); // 입력된 자연수의 길이를 반환.
int main(void)
{
	long long N, Num;
	int K, Count, index1 = 0, index2 = 0, index3 = 0, min;
	int tmp; // 정렬할때 쓰일 임시 변수.
	scanf_s("%lld %d", &N, &K);
	Num = N;
	Count = ReturnNumber(Num);
	if (Count == K) {
		printf("%lld\n", Num);
		return 0;
	}
	else if (Count > K) {
		for (int i = 0; i < 10; i++) {
			check[i] = 0;
		}
		while (index2 < K) {
			if (check[Number[index1]] == 0) {
				index2++;
				check[Number[index1]] = 1;
			}
			Number2[index3] = Number[index1];
			Bubble[index3] = Number[index1];
			index1++;
			index3++;
		}
		// 버블정렬
		for (int i = 0; i < index1; i++) {
			for (int j = 0; j < index1 - 1; j++) {
				if (Bubble[j] > Bubble[j + 1])
				{
					tmp = Bubble[j];
					Bubble[j] = Bubble[j + 1];
					Bubble[j + 1] = tmp;
				}
			}
		}
		index1--;
		if (Number[index1] < Number[index3]) {
			Number2[index1]++;
			min = Min(Number2, index3);
			while (Number[index3] != -1) {
				Number2[index3] = min;
				index3++;
			}
		}
		else {
			min = Min(Number2, index3);
			while(Number[index3] != -1) {
				if (check[Number[index3]] == 1) {
					Number2[index3] = Number[index3];
				}
				else {
					for (int i = 0; i < index1 + 1; i++) {
						if (Number[index3] < Bubble[i]) {
							Number2[index3] = Bubble[i];
							break;
						}
					}
					index3++;
					while (Number[index3] != -1) {
						Number2[index3] = min;
						index3++;
					}
					break;
				}
				index3++;
			}
		}
		for (int i = 0; i < index3; i++) {
			printf("%d", Number2[i]);
		}
		printf("\n");
		return 0;
	}
	// 수정 해야할 부분.
	else if (Count < K) {
		while (1) {
			if (ReturnNumber(++Num) == K) {
				printf("%lld\n", Num);
				return 0;
			}
		}
	}

	/*
	int A, B, C;
	while (1)
	{
		scanf_s("%d %d %d", &A, &B, &C);
		if (A == 0 && B == 0 && C == 0)
			return;
		if ((A * A == B * B + C * C) || (B * B == A * A + C * C) || (C * C == B * B + A * A))
			printf("right\n");
		else
			printf("wrong\n");
	}
	*/
	/*
	int X, Y;
	int PointX[3];
	int PointY[3];
	int CheckX[1001];
	int CheckY[1001];
	for (int i = 0; i < 1001; i++) {
		CheckX[i] = 0;
		CheckY[i] = 0;
	}
	for (int i = 0; i < 3; i++) {
		scanf_s("%d %d", &PointX[i], &PointY[i]);
		CheckX[PointX[i]]++;
		CheckY[PointY[i]]++;
	}
	for (int i = 0; i < 3; i++) {
		if (CheckX[PointX[i]] == 1)
			X = PointX[i];
		if (CheckY[PointY[i]] == 1)
			Y = PointY[i];
	}
	printf("%d %d\n", X, Y);
	*/
	/*
	int x, y, w, h, dist;
	int distance[4];
	scanf_s("%d %d %d %d", &x, &y, &w, &h);
	dist = x;
	distance[0] = x;
	distance[1] = y;
	distance[2] = w - x;
	distance[3] = h - y;

	for (int i = 1; i < 4; i++) {
		if (distance[i] < dist)
			dist = distance[i];
	}

	printf("%d\n", dist);
	*/
	/*
	long long A, B, V;
	scanf_s("%lld %lld %lld", &A, &B, &V);
	
	if ((V - A) % (A - B) == 0) {
		printf("%lld\n", (V - A) / (A - B) + 1);
	}
	else {
		printf("%lld\n", (V - A) / (A - B) + 2);
	}
	*/
	/*
	long long A, B, C, point;
	scanf_s("%lld %lld %lld", &A, &B, &C);
	if (B >= C)
		point = -1;
	else {
		point = A / (C - B) + 1;
	}
	printf("%lld\n", point);
	*/

	return 0;
}
int ReturnNumber(long long N)
{
	int count = 0 ,index = Length(N);
	// 체크배열 초기화.
	for (int i = 0; i < 10; i++) {
		check[i] = 0;
	}
	while (N != 0) {
		check[N % 10] = 1;
		Number[--index] = N % 10;
		N /= 10;
	}
	for (int i = 0; i < 10; i++) {
		if (check[i] == 1)
			count++;
	}
	return count;
}
int Min(int Number[], int size)
{
	int min = Number[0];
	for (int i = 1; i < size; i++) {
		if (min > Number[i])
			min = Number[i];
	}
	return min;
}
int Length(long long N)
{
	int count = 0;
	while (1) {
		N /= 10;
		count++;
		if (N == 0)
			return count;
	}
}