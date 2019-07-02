#include <stdio.h>
#include <stdlib.h>
int Stack[5000]; // �������� �����͸� ������ ����.
int Stackindex = -1; // ������ �ε������� ����.
void InsertStack(int data); // ���� ����.
void InsertList(int data); // ���Ḯ��Ʈ ����.
int DeleteList(); // ���Ḯ��Ʈ ����.
struct People {
	struct People* leftnext;
	int Number;
	struct People* rightnext;
};
struct People* Head = NULL;
struct People* TmpHead = NULL;
int main(void)
{
	int N, K;
	scanf_s("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
	{
		InsertList(N - i);
	}
	// ����Ʈ�� ������ȯ������ �������.
	TmpHead = Head;
	while (Head->rightnext != NULL)
	{
		Head = Head->rightnext;
	}
	Head->rightnext = TmpHead; 
	TmpHead->leftnext = Head; 
	Head = TmpHead; // Head�� �ٽ� �ʱ��������� �ʱ�ȭ.
	for(int i=0; i < N; i++)
	{
		for (int i = 0; i < K - 1; i++)
		{	
			Head = Head->rightnext;
		}
		InsertStack(DeleteList());
	}
	
	printf("<");
	for (int i = 0; i < N - 1; i++)
	{
		printf("%d, ", Stack[i]);
	}
	printf("%d>", Stack[N - 1]);
	return 0;
}
void InsertList(int data) // ���Ḯ��Ʈ �����Լ�.
{
	struct People* Data = (struct People*)malloc(sizeof(struct People));
	Data->Number = data;
	if (Head == NULL)
	{
		Data->rightnext = NULL;
		Data->leftnext = NULL;
		Head = Data;
	}
	else 
	{
		Head->leftnext = Data;
		Data->rightnext = Head;
		Data->leftnext = NULL;
		Head = Data;
	}
}
int DeleteList() // ���Ḯ��Ʈ �����Լ�.
{
	struct People* tmp;
	int Num;
	tmp = Head;
	Num = Head->Number;
	if (Head->leftnext == NULL && Head->rightnext == NULL)
	{
		free(tmp);
		return Num;
	}
	else if (Head->leftnext == NULL)
	{
		Head->rightnext->leftnext = Head->leftnext;
	}
	else if (Head->rightnext == NULL)
	{
		Head->leftnext->rightnext = Head->rightnext;
	}
	else 
	{
		Head->leftnext->rightnext = Head->rightnext;
		Head->rightnext->leftnext = Head->leftnext;
	} 
	Head = Head->rightnext;
	free(tmp);
	return Num;
}
void InsertStack(int data)
{
	Stack[++Stackindex] = data;
}