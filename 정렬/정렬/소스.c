#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//void Merge(int start, int T, int N); // 합병정렬.
//void MergeSort(int start, int T, int N); // 합병정렬.
//static int Sort[1050000]; // 정렬되지 않은 배열.
//static int Temp[1050000]; // 빈 배열.
//void CountingSort(int* Count, int size, int N); // 카운팅 정렬.
//int average(int* S,int N);
//int frecency(int* Count, int size);
struct Word {
	char W[51]; // 단어를 받을 배열.
	int Mark; // 단어의 중복여부 판단 변수.
	int Length; // 단어의 길이.
};
int MyCompare(const void* A, const void* B);
int main(void)
{
	int N, Max = 0; // swap : 사전순으로 인덱스를 정렬할때 쓰일 교환변수.
	scanf_s("%d", &N);
	struct Word* S = (struct Word*)malloc(sizeof(struct Word)*N);
	
	for (int i = 0; i < N; i++)
	{
		S[i].Mark = 0; // 중복 표시 변수를 전부 0으로 초기화.

	}
	for (int i = 0; i < N; i++)
	{
		scanf_s("%s", S[i].W, 51);
		S[i].Length = strlen(S[i].W);
		if (Max < S[i].Length) // 단어의 최대 길이수 저장.
			Max = S[i].Length;
		for (int j = 0; j < i; j++)
		{
			if (strcmp(S[i].W, S[j].W) == 0)
			{
				S[i].Mark = 1; // 현재 입력받은 단어가 한번이라도 나왔을시 1로 초기화.
				break;
			}
		}
	}
	// 사전 순으로 먼저 정렬.	
	qsort(S, N, sizeof(struct Word), MyCompare);
	// 길이 순으로 정렬.
	for (int i = 1; i <= Max; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (S[j].Length == i && S[j].Mark == 0)
			{
				printf("%s\n", S[j].W);
			}
		}
	}
	free(S);

	/* 통계학
	int N, i = 0;
	int* S;
	int Count[8001];
	scanf_s("%d", &N);
	S = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < 8001; i++)
	{
		Count[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &S[i]);
		Count[S[i] + 4000]++;
	}
	while (i < N) // 카운팅 정렬.
	{
		for (int j = 0; j < 8001; j++)
		{
			for (int k = 0; k < Count[j]; k++)
			{
				S[i++] = j - 4000;
			}
		}
	}
	printf("%d\n", average(S, N)); // 산술평균
	printf("%d\n", S[N / 2]); // 중앙값
	printf("%d\n", frecency(Count, 8001)); // 최빈값
	printf("%d\n", S[N - 1] - S[0]); // 범위
	
	free(S);
	*/

	/* 소트인사이드
	char N[10] = {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'};
	int Count[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	gets(N);
	for (int i = 0; i < 10; i++)
	{
		if(N[i] != 65)
			Count[9 - (N[i] - 48)]++;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < Count[i]; j++)
		{
			printf("%d", 9 - i);
		}
	}
	printf("\n");
	*/

	/* 카운팅 정렬.
	int N, M;
	int Count[10000];
	scanf_s("%d", &N);
	for (int i = 0; i < 10000; i++)
	{
		Count[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &M);
		Count[M - 1]++;
	}
	for (int i = 0; i < 10000; i++)
	{
		if(i != 0)
			Count[i] += Count[i - 1];
	}
	CountingSort(Count, 10000, N);
	*/

	/* 병합 정렬.
	int N;
	scanf_s("%d", &N);
	for (int i = 0; i < 1050000; i++)
	{
		Sort[i] = 1000001;
		Temp[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &Sort[i]);
	}

	//MergeSort(0, 2, N);

	printf("\n");
	for (int i = 0; i < N; i++)
	{
		printf("%d\n", Sort[i]);
	}
	*/

	return 0;
}
int MyCompare(const void* A, const void* B)
{
	struct Word * p1 = (struct Word*)A;
	struct Word * p2 = (struct Word*)B;
	return strcmp(p1->W, p2->W);
}
/*
int average(int* S, int N) // 산술평균
{
	int total = 0;
	for (int i = 0; i < N; i++)
	{
		total += S[i];
	}
	if (((double)total / N - (int)total / N) >= (double)1 / 2)
		return total / N + 1;
	else if (((double)total / N - (int)total / N) <= (double)1 * (-1) / 2)
		return total / N - 1;
	else
		return total / N;
}
int frecency(int* Count, int size) // 최빈값
{
	int MAX = Count[0], j = 0;
	int Index[8001];
	for (int i = 0; i < size; i++)
	{
		if (MAX < Count[i])
			MAX = Count[i];
		Index[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		if (Count[i] == MAX)
		{
			Index[j++] = i - 4000;
		}
	}
	if (Index[1] == 0)
		return Index[0];
	else
		return Index[1];
}
*/
/*
void CountingSort(int* Count, int size, int N)
{
	int i = 0, k = 1;
	while (i < N)
	{
		if (k == 1)
		{
			for (int j = 0; j < Count[k - 1]; j++)
			{
				printf("%d\n", k);
				i++;
			}
			k++;
		}
		else
		{
			for (int j = 0; j < Count[k - 1] - Count[k - 2]; j++)
			{
				printf("%d\n", k);
				i++;
			}
			k++;
		}
	}
}
*/
/*
void Merge(int start, int T, int N)
{
	int end = T - 1;
	int mid = (start + end) / 2;
	int i = start, k = start;
	int j = mid + 1;
	int flag; // 반복문 탈출시키기 위한 변수.
	while (1) // 이 부분이 핵심!
	{
		if (end > N - 1)
		{
			while (k <= end)
			{
				flag = 0;
				if (Sort[i] < Sort[j] && j <= end && i < mid + 1)
				{
					Temp[k++] = Sort[i++];
					flag = 1;
				}
				else if (Sort[i] > Sort[j] && j <= end && i < mid + 1)
				{
					Temp[k++] = Sort[j++];
					flag = 1;
				}
				if (j > end) // 두 영역중 앞부분이 남아있는 경우.
				{
					while (i < mid + 1)
					{
						Temp[k++] = Sort[i++];
					}
					flag = 1;
				}
				else if (i >= mid + 1) // 두 영역중 뒷부분이 남아있는 경우.
				{
					while (j <= end)
					{
						Temp[k++] = Sort[j++];
					}
					flag = 1;
				}
				if (flag == 0)
					return;
			}
			for (int i = start; i <= end; i++)
			{
				Sort[i] = Temp[i];
			}
			return;
		}
		else
		{
			while (k <= end)
			{
				if (Sort[i] < Sort[j] && j <= end && i < mid + 1)
				{
					Temp[k++] = Sort[i++];
				}
				else if (Sort[i] > Sort[j] && j <= end && i < mid + 1)
				{
					Temp[k++] = Sort[j++];
				}
				if (j > end) // 두 영역중 앞부분이 남아있는 경우.
				{
					while (i < mid + 1)
					{
						Temp[k++] = Sort[i++];
					}
				}
				else if (i >= mid + 1) // 두 영역중 뒷부분이 남아있는 경우.
				{
					while (j <= end)
					{
						Temp[k++] = Sort[j++];
					}
				}
			}
			for (int i = start; i <= end; i++)
			{
				Sort[i] = Temp[i];
			}
		}
		end += T, start += T;
		i = start, k = start;
		mid += T, j = mid + 1;
	}
}
void MergeSort(int start, int T, int N)
{
	Merge(start, T, N);
	if (T >= N)
		return;
	else
		MergeSort(start, T * 2, N);
}
*/
