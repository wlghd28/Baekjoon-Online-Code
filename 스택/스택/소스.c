#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//int Stack[10000];
//int index = -1; //���ù迭 �ε������� ����.
//int Number = 1; // ������������ ���ĵ��ִ� �迭�� �ε����� ����.
//int PopNum = 0;
//int Answerindex = 0;
//void Push(int* Sequence, char* Answer);
//void Pop(int* Sequence, char* Answer);

int main(void)
{
	char Bracket[32]; // ��ȣ ���ڿ�(��Ʈ��)�� ���� ���ڿ�.
	char Operator[32]; // ������ ����.
	int Operand[32]; // �ǿ����� ����.
	int operatorindex = -1, operandindex = -1; // �����ڽ��� �ε���, �ǿ����ڽ��� �ε���.
	int Bracketindex = 0, bracketindex1 = 0, bracketindex2 = 0;// ���ڿ��� �ε��� ����, �� ��ȣ�� ��������. 
	int tmp = 0, flag = 0; // ���� ������� ��ȣ�� ���ÿ� �����ִ��� �Ǵ��ϴ� �÷��� ����.
	gets(Bracket); // ��ȣ ���ڿ�(��Ʈ��) �Է�.

	while (Bracket[Bracketindex] != NULL)
	{
		if (Bracket[Bracketindex] == '(') // '(' �� ���.
		{
			if (Bracket[Bracketindex + 1] == ']')
			{
				printf("0\n");
				return 0;
			}
			bracketindex1++;
		}
		else if (Bracket[Bracketindex] == '[') // '[' �ϰ��.
		{
			if (Bracket[Bracketindex + 1] == ')')
			{
				printf("0\n");
				return 0;
			}
			bracketindex2++;
		}
		else if (Bracket[Bracketindex] == ')')
		{
			bracketindex1--;
		}
		else if (Bracket[Bracketindex] == ']')
		{
			bracketindex2--;
		}
		if (bracketindex1 < 0 || bracketindex2 < 0)
		{
			printf("0\n");
			return 0;
		}
		Bracketindex++;
	}
	if (bracketindex1 != 0 || bracketindex2 != 0)
	{
		printf("0\n");
		return 0;
	}
	Bracketindex = 0;
	while (Bracket[Bracketindex] != NULL)
	{
		if (Bracket[Bracketindex] == '(' || Bracket[Bracketindex] == '[') // '(' �Ǵ� '[' �� ������ ���.
		{
			if (Bracket[Bracketindex] == '(') // '(' �� ���.
			{
				bracketindex1++;
			}
			else if (Bracket[Bracketindex] == '[') // '[' �ϰ��.
			{
				bracketindex2++;
			}
			if (Bracket[Bracketindex + 1] == ')') // ���� ������ ���� ��ȣ�� ')' �ϰ��.
			{
				Operand[++operandindex] = 2;
			}
			else if (Bracket[Bracketindex + 1] == ']') //
			{
				Operand[++operandindex] = 3;
			}
			else if (Bracket[Bracketindex + 1] == '(' || Bracket[Bracketindex + 1] == '[')
			{
				Operator[++operatorindex] = '(';
				flag = 1; // ���ÿ� '('�� ����ִ� ��Ȳ�̴�.
			}
		}
		else if (Bracket[Bracketindex] == ')' || Bracket[Bracketindex] == ']') // ')' �Ǵ� ']' �� ������ ���.
		{
			if (Bracket[Bracketindex + 1] == '(' || Bracket[Bracketindex + 1] == '[')
			{
				if (Operator[operatorindex] == '*')
				{
					tmp = Operand[operandindex];
					Operand[operandindex--] = 0;
					tmp *= Operand[operandindex--];
					Operand[++operandindex] = tmp;
					Operator[operatorindex] = '+';
				}
				else
					Operator[++operatorindex] = '+';
			}
			else if (Bracket[Bracketindex + 1] == ']' || Bracket[Bracketindex + 1] == ')')
			{
				if (Bracket[Bracketindex] == ')') // '(' �� ���.
				{
					bracketindex1--;
				}
				else if (Bracket[Bracketindex] == ']') // '[' �ϰ��.
				{
					bracketindex2--;
				}
				while (Operator[operatorindex] != '(' && flag == 1)
				{
					if (Operator[operatorindex] == '*')
					{
						tmp = Operand[operandindex];
						Operand[operandindex--] = 0;
						tmp *= Operand[operandindex--];
						Operand[++operandindex] = tmp;
					}
					else if (Operator[operatorindex] == '+')
					{
						tmp = Operand[operandindex];
						Operand[operandindex--] = 0;
						tmp += Operand[operandindex--];
						Operand[++operandindex] = tmp;
					}
					Operator[operatorindex--] = NULL;
				}
				if (Operator[operatorindex] == '(')
				{
					Operator[operatorindex--] = NULL; // '(' ��
					if (bracketindex1 == 0 && bracketindex2 == 0)
					{
						flag = 0; // ���ÿ��� '(' ���ŵ� ��Ȳ.
					}
				}
				Operator[++operatorindex] = '*'; // '*' Ǫ��.
				if (Bracket[Bracketindex + 1] == ']')
				{
					Operand[++operandindex] = 3;
				}
				else if (Bracket[Bracketindex + 1] == ')')
				{
					Operand[++operandindex] = 2;
				}
			}
		}
		Bracketindex++;
	}
	while (operatorindex > -1)
	{
		if (Operator[operatorindex] == '*')
		{
			tmp = Operand[operandindex];
			Operand[operandindex--] = 0;
			tmp *= Operand[operandindex--];
			Operand[++operandindex] = tmp;
		}
		else if (Operator[operatorindex] == '+')
		{
			tmp = Operand[operandindex];
			Operand[operandindex--] = 0;
			tmp += Operand[operandindex--];
			Operand[++operandindex] = tmp;
		}
		Operator[operatorindex--] = NULL;
	}
	printf("%d\n", Operand[operandindex]);

	/*
	int T, bracketindex, vpsindex;
	char VPS[51];
	scanf_s("%d", &T);
	getchar();

	for (int i = 0; i < T; i++)
	{
		gets(VPS);
		vpsindex = 0;
		bracketindex = 0;
		while (VPS[vpsindex] != NULL)
		{
			if (VPS[vpsindex] == '(')
				bracketindex++;
			else
				bracketindex--;
			if (bracketindex < 0)
			{
				printf("NO\n");
				break;
			}
			vpsindex++;
		}
		if (bracketindex == 0 && vpsindex == strlen(VPS))
			printf("YES\n");
		else if(bracketindex != 0 && vpsindex == strlen(VPS))
			printf("NO\n");
	}
	*/
	/*
	int n, N, tmp;
	int* Sequence;
	char* Answer;
	scanf_s("%d", &n);
	Sequence = (int*)malloc(sizeof(int)*n);
	Answer = (char*)malloc(sizeof(char)*n * 2);
	for (int i = 0; i < n * 2; i++)
	{
		Answer[i] = NULL;
	}
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &N);
		if (PopNum > N)
		{
			if (index == -1)
			{
				printf("NO\n");
				return 0;
			}
			if (Sequence[index] == N)
				Pop(Sequence, Answer);
			else
			{
				printf("NO\n");
				return 0;
			}
		}
		else
		{
			tmp = Number;
			for (int i = 0; i < N - tmp + 1; i++)
			{
				Push(Sequence, Answer);
			}
			Pop(Sequence, Answer);
		}
	}
	tmp = 0;
	while (tmp < Answerindex)
	{
		printf("%c\n", Answer[tmp++]);
	}
	free(Sequence);
	free(Answer);
	*/
	/*
	int N;
	char Command[11];
	char Integer[7];
	scanf_s("%d", &N);
	getchar(); // N�� �Է¹��� �� ���� �ΰ� ����.

	for (int i = 0; i < N; i++)
	{
		gets(Command); // ����� �޴´�.

		if (strncmp(Command, "push", 4) == 0) // push ���
		{
			for (int i = 0; i < 7; i++)
			{
				Integer[i] = Command[i + 5];
			}
			index++;
			Stack[index] = atoi(Integer);
		}
		else if (strncmp(Command, "pop", 3) == 0) // pop ���
		{
			if (index == -1)
				printf("-1\n");
			else
			{
				printf("%d\n", Stack[index]);
				Stack[index] = 0;
				index--;
			}
		}
		else if (strncmp(Command, "size", 4) == 0) // size ���
		{
			printf("%d\n", index + 1);
		}
		else if (strncmp(Command, "empty", 5) == 0) // empty ���
		{
			if (index == -1)
				printf("1\n");
			else
				printf("0\n");
		}
		else if(strncmp(Command, "top", 3) == 0)// top ���
		{
			if (index == -1)
				printf("-1\n");
			else
				printf("%d\n", Stack[index]);
		}
	}
	*/
	return 0;
}
/*
void Push(int* Sequence, char* Answer)
{	
	Sequence[++index] = Number++;
	Answer[Answerindex++] = '+';
}
void Pop(int* Sequence, char* Answer)
{
	PopNum = Sequence[index];
	Sequence[index--] = 0;
	Answer[Answerindex++] = '-';
}
*/