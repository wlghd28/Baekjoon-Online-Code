#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	/*
	// Look up �迭 Ȱ��
	// ���̾� �ð� ���.
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
	//�׷�ܾ� ���� ���ϱ�.

	int N, j, Nongroupvoca = 0; // ���� Ƚ�� ����, �׷�ܾ� �ƴ� �ܾ� ����. 
	char S[102]; // ���ڿ��� �ޱ����� �迭.
	int flag[26]; // ���ĺ��� �������� �ִ��� ������ �Ǵ��ϴ� �迭.
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int i = 0; i < 102; i++)
		{ // �Ź� ���ڿ� �ʱ�ȭ
			S[i] = NULL;
		}
		for (int i = 0; i < 26; i++)
		{ // �Ź� �湮 �迭 �ʱ�ȭ.
			flag[i] = 0;
		}
		getchar(); // �����ִ� �Է¹��� ����.
		gets_s(S, 100); // ���ڿ��� �Է¹޴´�.
		j = 0; // �ݺ��� ���� �ʱ�ȭ.
		while (S[j] != NULL)
		{
			if (flag[S[j] - 'a'] == 0)
			{ // ���ĺ��� ó�� ���°��.
				flag[S[j] - 'a'] = 1;
			}
			else if (S[j] != S[j - 1])
			{ // ���ĺ��� ó�� ���°� �ƴ� ����̸�
			  // �������ڿ� �ٸ� ���.
				Nongroupvoca++; // �׷�ܾ �ƴ� ���� 1�� �߰�.
				break; // while�� Ż��.
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
	//���ĺ� �ҹ��ڷθ� �̷���� �ܾ� S�� �־�����. 
	//������ ���ĺ��� ���ؼ�, �ܾ ���ԵǾ� �ִ� ��쿡��
	//ó�� �����ϴ� ��ġ��, ���ԵǾ� ���� ���� ��쿡��
	//-1�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	//������ ���ĺ��� ���ؼ�, a�� ó�� �����ϴ� ��ġ, b�� ó�� �����ϴ� ��ġ,
	//... z�� ó�� �����ϴ� ��ġ�� �������� �����ؼ� ����Ѵ�.
	//����, � ���ĺ��� �ܾ ���ԵǾ� ���� �ʴٸ� -1�� ����Ѵ�. 
	//�ܾ��� ù ��° ���ڴ� 0��° ��ġ�̰�, �� ��° ���ڴ� 1��° ��ġ�̴�.
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
	// ũ�ξ�Ƽ�� ���ĺ�.
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
	//���ĺ� ��ҹ��ڷ� �� �ܾ �־�����, 
	//�� �ܾ�� ���� ���� ���� ���ĺ��� �������� 
	//�˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.
	//��, �빮�ڿ� �ҹ��ڸ� �������� �ʴ´�.
	//ù° �ٿ� �� �ܾ�� ���� ���� ���� ���ĺ��� �빮�ڷ� ����Ѵ�.
	//��, ���� ���� ���� ���ĺ��� ���� �� �����ϴ� ��쿡�� ? �� ����Ѵ�.

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