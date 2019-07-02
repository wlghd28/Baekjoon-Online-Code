#include <stdio.h>
#include <math.h>
//int PrimeNumber(int N);
int main(void)
{
	int T, n, Primeindex1, Primeindex2, flag;
	int P[10001];
	for (int i = 2; i < 10001; i++) // 배열의 원소가 1인 인덱스가 소수이다.
	{
		for (int j = i; j < 10001; j += i)
		{
			if (P[j] >= 1)
				P[j]++;
			else
				P[j] = 1;
		}
	}
	scanf_s("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf_s("%d", &n);
		if (P[n/2] == 1) // 입력받은 수의 절반이 소수일 경우.
			printf("%d %d\n", n / 2, n / 2);	
		else // 일반적인 경우.
		{
			flag = 0;
			Primeindex1 = n / 2 - 1;
			Primeindex2 = n / 2 + 1;
			while (1)
			{
				for (int i = Primeindex1; i < n / 2; i++)
				{
					if (P[i] == 1)
					{
						for (int j = Primeindex2; j > n / 2; j--)
						{
							if (P[j] == 1 && i + j == n)
							{
								Primeindex1 = i;
								Primeindex2 = j;
								flag = 1;
								break;
							}
						}
					}
					if (flag == 1)
						break;
				}
				if (flag == 1)
					break;
				Primeindex1--;
				Primeindex2++;
			}
			printf("%d %d\n", Primeindex1, Primeindex2);
		}
	}
	/*
	int N, M, Total = 0, Min = 0, flag = 0;
	scanf_s("%d", &M);
	scanf_s("%d", &N);

	for (int i = M; i <= N; i++)
	{
		if (PrimeNumber(i) == 1)
		{
			Total += i;
			if (flag == 0)
				Min = i;
			flag = 1;
		}
	}	
	if (Total == 0)
		printf("%d\n", -1);
	else
	{
		printf("%d\n%d\n", Total, Min);
	}
	*/
	return 0;
}
/*
int PrimeNumber(int N)
{
	int p = 2;
	if (N == 1)
		return 0;
	else
	{
		while (p <= (int)sqrt(N))
		{
			if (N % p == 0)
				return 0;
			else
				p++;
		}
		return 1;
	}
}
*/