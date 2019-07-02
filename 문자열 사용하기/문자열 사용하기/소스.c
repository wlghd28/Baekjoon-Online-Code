#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	/*
	// Look up 배열 활용
	// 다이얼 시간 계산.
	char D[17];
	int Time[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5,
		6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 
		10, 10, 10, 10};
	int i = 0, Totaltime = 0;
	for (int i = 0; i < 17; i++)
	{
		D[i] = NULL;
	}
	gets_s(D, 17);
	while (D[i] != NULL)
	{
		Totaltime += Time[(int)D[i] - (int)'A'];
		i++;
	}

	printf("%d\n", Totaltime);
	*/

	/*
	//그룹단어 갯수 구하기.

	int N, j, Nongroupvoca = 0; // 실행 횟수 변수, 그룹단어 아닌 단어 개수. 
	char S[102]; // 문자열을 받기위한 배열.
	int flag[26]; // 알파벳이 나온적이 있는지 없는지 판단하는 배열.
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int i = 0; i < 102; i++)
		{ // 매번 문자열 초기화
			S[i] = NULL;
		}
		for (int i = 0; i < 26; i++)
		{ // 매번 방문 배열 초기화.
			flag[i] = 0;
		}
		getchar(); // 남아있는 입력버퍼 제거.
		gets_s(S, 100); // 문자열을 입력받는다.
		j = 0; // 반복문 변수 초기화.
		while (S[j] != NULL)
		{
			if (flag[S[j] - 'a'] == 0)
			{ // 알파벳이 처음 나온경우.
				flag[S[j] - 'a'] = 1;
			}
			else if (S[j] != S[j - 1])
			{ // 알파벳이 처음 나온게 아닌 경우이며
			  // 이전문자와 다른 경우.
				Nongroupvoca++; // 그룹단어가 아닌 갯수 1개 추가.
				break; // while문 탈출.
			}
			j++;
		}
		
	}

	printf("%d\n", N - Nongroupvoca);
	*/


	/*
	int N, M, j, k;
	char S[20];
	char** A;
	scanf_s("%d", &N);
	A = (char**)malloc(sizeof(char*) * N);

	for (int i = 0; i < N; i++)
	{
		A[i] = (char*)malloc(sizeof(char) * 160);
		for (int j = 0; j < 160; j++)
		{
			A[i][j] = NULL;
		}
	}

	for (int i = 0; i < N; i++)
	{
		scanf_s("%d",&M);
		getchar();
		for (int i = 0; i < 20; i++)
		{
			S[i] = NULL;
		}
		gets_s(S, 20);
		k = 0;
		j = 0;
		while (S[j] != NULL)
		{
			for (int h = 0; h < M; h++)
			{
				A[i][k] = S[j];
				k++;
			}
			j++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		printf("%s\n", A[i]);
		free(A[i]);
	}

	free(A);
	*/


	/*
	//알파벳 소문자로만 이루어진 단어 S가 주어진다. 
	//각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는
	//처음 등장하는 위치를, 포함되어 있지 않은 경우에는
	//-1을 출력하는 프로그램을 작성하시오.
	//각각의 알파벳에 대해서, a가 처음 등장하는 위치, b가 처음 등장하는 위치,
	//... z가 처음 등장하는 위치를 공백으로 구분해서 출력한다.
	//만약, 어떤 알파벳이 단어에 포함되어 있지 않다면 -1을 출력한다. 
	//단어의 첫 번째 글자는 0번째 위치이고, 두 번째 글자는 1번째 위치이다.
	char S[100];
	int N[26];
	int M[26];
	int i = 0, flag = 0;
	for (int i = 0; i < 26; i++)
	{
		N[i] = -1;
		M[i] = 0;
	}
	gets_s(S, 100);
	while (S[i] != NULL)
	{
		if (M[(int)S[i] - 97] == 0)
		{
			N[(int)S[i] - 97] = i;
			M[(int)S[i] - 97] = 1;
		}
		i++;
	}
	
	for (int i = 0; i < 26; i++)
	{
		printf("%d ", N[i]);
	}
	printf("\n");
	*/

	/*
	// 크로아티아 알파벳.
	char S[100];
	int index = 0, i = 0;
	gets_s(S, 100);

	while (S[i] != NULL)
	{
		if (S[i] == 'c' || S[i] == 'd' || S[i] == 'l' ||
			S[i] == 'n' || S[i] == 's' || S[i] == 'z')
		{
			switch (S[i])
			{
			case 'c':
				if (S[i + 1] == '=' || S[i + 1] == '-')
				{
					index++;
					i++;
				}
				else
					index++;
				break;
			case 'd':
				if (S[i + 1] == 'z')
				{
					if (S[i + 2] == '=')
					{
						index++;
						i += 2;
					}
					else
					{
						index++;
					}
				}
				else if (S[i + 1] == '-')
				{
					index++;
					i++;
				}
				else
					index++;
				break;
			case 'l':
				if (S[i + 1] == 'j')
				{
					index++;
					i++;
				}
				else
					index++;
				break;
			case 'n':
				if (S[i + 1] == 'j')
				{
					index++;
					i++;
				}
				else
					index++;
				break;
			case 's':
				if (S[i + 1] == '=')
				{
					index++;
					i++;
				}
				else
					index++;
				break;
			case 'z':
				if (S[i + 1] == '=')
				{
					index++;
					i++;
				}
				else
					index++;
				break;
			}
		}
		else
			index++;
		i++;
	}
	printf("%d\n", index);
	*/

	/*
	//알파벳 대소문자로 된 단어가 주어지면, 
	//이 단어에서 가장 많이 사용된 알파벳이 무엇인지 
	//알아내는 프로그램을 작성하시오.
	//단, 대문자와 소문자를 구분하지 않는다.
	//첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다.
	//단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ? 를 출력한다.

	char S[1000000];
	int A[26];
	int i = 0, MAX, index = 0;
	gets_s(S, 1000000);

	for (int j = 0; j < 26; j++)
	{
		A[j] = 0;
	}
	while (S[i] != NULL)
	{
		if ((int)S[i] <= 90)
		{
			A[(int)S[i] - 65]++;
		}
		else
		{
			A[(int)S[i] - 65 - 32]++;
		}
		i++;
	}
	MAX = A[0];
	for (int j = 1; j < 26; j++)
	{
		if (MAX < A[j])
			MAX = A[j];
	}
	for (int j = 0; j < 26; j++)
	{
		if (A[j] == MAX)
		{
			index++;
			i = j;
		}
	}
	if (index > 1)
		printf("?\n");
	else
		printf("%c\n", (char)(i + 65));
	*/

	return 0;
}