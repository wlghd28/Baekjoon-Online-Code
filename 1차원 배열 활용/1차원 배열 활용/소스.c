#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//void Score(char* Q, int size, int* T, int i);
int main(void)
{
	int S[5];
	int Total = 0;
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d", &S[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		if (S[i] < 40)
		{
			S[i] = 40;
		}
		Total += S[i];
	}
	printf("%d\n", Total / 5);
	/*
	//다장조는 c d e f g a b C, 총 8개 음으로 이루어져있다. 
	//이 문제에서 8개 음은 다음과 같이 숫자로 바꾸어 표현한다. 
	//c는 1로, d는 2로, ..., C를 8로 바꾼다.
	//1부터 8까지 차례대로 연주한다면 ascending, 
	//8부터 1까지 차례대로 연주한다면 descending, 
	//둘 다 아니라면 mixed 이다.
	//연주한 순서가 주어졌을 때, 이것이 ascending인지, descending인지,
	//아니면 mixed인지 판별하는 프로그램을 작성하시오.
	//첫째 줄에 8개 숫자가 주어진다. 이 숫자는 문제 설명에서 설명한 음이며,
	//1부터 8까지 숫자가 한 번씩 등장한다.첫째 줄에 8개 숫자가 주어진다. 이 숫자는 
	//문제 설명에서 설명한 음이며, 1부터 8까지 숫자가 한 번씩 등장한다.
	int N[8];
	int index = 0;
	scanf_s("%d %d %d %d %d %d %d %d", 
		&N[0], &N[1], &N[2], &N[3], &N[4], &N[5], &N[6], &N[7]);

	if (N[0] == 1)
	{
		for (int i = 0; i < 8; i++)
		{
			if (N[i] != i + 1)
				index++;
		}
		if (index == 0)
		{
			printf("ascending\n");
		}
		else
		{
			printf("mixed\n");
		}

	}
	else if (N[0] == 8)
	{
		for (int i = 8; i > 0; i--)
		{
			if (N[8 - i] != i)
				index++;
		}
		if (index == 0)
		{
			printf("descending\n");
		}
		else
		{
			printf("mixed\n");
		}
	}
	else
	{
		printf("mixed\n");
	}
	*/

	/*
	//"OOXXOXXOOO"와 같은 OX퀴즈의 결과가 있다. 
	//O는 문제를 맞은 것이고, X는 문제를 틀린 것이다. 
	//문제를 맞은 경우 그 문제의 점수는 그 문제까지 연속된 O의 개수가 된다. 
	//예를 들어, 10번 문제의 점수는 3이 된다.
	//"OOXXOXXOOO"의 점수는 1+2+0+0+1+0+0+1+2+3 = 10점이다.
	//OX퀴즈의 결과가 주어졌을 때, 점수를 구하는 프로그램을 작성하시오.
	//첫째 줄에 테스트 케이스의 개수가 주어진다. 
	//각 테스트 케이스는 한 줄로 이루어져 있고, 
	//길이가 0보다 크고 80보다 작은 문자열이 주어진다. 
	//문자열은 O와 X만으로 이루어져 있다.

	char Q[80];
	int N;
	int* T;
	scanf_s("%d", &N);
	getchar();
	T = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++)
	{
		for (int i = 0; i < 80; i++)
		{
			Q[i] = NULL;
		}
		gets_s(Q, 80);
		Score(Q, 80, T, i);
	}
	for (int i = 0; i < N; i++)
	{
		printf("%d\n", T[i]);
	}
	free(T);
	*/


	/*
	//세 개의 자연수 A, B, C가 주어질 때 A×B×C를 계산한 결과에 
	//0부터 9까지 각각의 숫자가 몇 번씩 쓰였는지를 구하는 프로그램을 작성하시오.
	//예를 들어 A = 150, B = 266, C = 427 이라면
	//A × B × C = 150 × 266 × 427 = 17037300 이 되고,
	//계산한 결과 17037300 에는 0이 3번, 1이 1번, 3이 2번, 7이 2번 쓰였다.
	
	int A, B, C, T, i = 1;
	int Count[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	scanf_s("%d", &A);
	scanf_s("%d", &B);
	scanf_s("%d", &C);

	T = A * B * C;

	if (T < 10000000)
	{
		while (i < 10000000)
		{
			Count[(int)((T % (i * 10)) / i)]++;
			i *= 10;
		}
	}
	else if (T < 100000000)
	{
		while (i < 100000000)
		{
			Count[(int)((T % (i * 10)) / i)]++;
			i *= 10;
		}
	}
	else
	{
		while (i < 1000000000)
		{
			Count[(int)((T % (i * 10)) / i)]++;
			i *= 10;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", Count[i]);
	}


	//단어 갯수 구하기.
	//영어 대소문자와 띄어쓰기만으로 이루어진 문자열이 주어진다. 
	//이 문자열에는 몇 개의 단어가 있을까? 이를 구하는 프로그램을 작성하시오.
	//단, 한 단어가 여러 번 등장하면 등장한 횟수만큼 모두 세어야 한다.
	//첫 줄에 영어 대소문자와 띄어쓰기로 이루어진 문자열이 주어진다. 이 문자열의 길이는 1,000,000을 넘지 않는다. 단어는 띄어쓰기 한 개로 구분되며, 
	//공백이 연속해서 나오는 경우는 없다. 
	//또한 문자열의 앞과 뒤에는 공백이 있을 수도 있다.
	/*
	char S[1000002] = { (char)NULL };
	int i = 0, index = 0, k;
	gets_s(S,1000000);

	while (S[i] == ' ' && S[i] != NULL)
	{
		i++;
	}
	if (i == strlen(S))
	{
		printf("%d\n", 0);
	}
	else
	{
		i = 0;
		k = strlen(S) - 1; // strlen() 함수는 시간을 상당히 잡아먹는다.
		while (S[k] == ' ')
		{
			k--;
		}
		while (S[i] == ' ')
		{
			i++;
		}
		while (i != k)
		{
			if (S[i] == ' ')
				index++;
			i++;
		}
		printf("%d\n", index + 1);
	}
	*/
	return 0;
}
/*
void Score(char* Q, int size, int* T, int i)
{
	int j = 0;
	int index = 0, Total = 0;
	while (Q[j] != NULL)
	{
		if (Q[j] == 'O')
		{
			index++;
			Total += index;
		}
		else
		{
			index = 0;
		}
		j++;
	}
	T[i] = Total;
}
*/