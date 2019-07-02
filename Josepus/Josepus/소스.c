#include <stdio.h>
#include <stdlib.h>
int Stack[5000]; // 정점들의 데이터를 저장할 스택.
int Stackindex = -1; // 스택의 인덱스참조 변수.
void InsertStack(int data); // 스택 삽입.
void InsertList(int data); // 연결리스트 삽입.
int DeleteList(); // 연결리스트 삭제.
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
	// 리스트를 원형순환구조로 만들어줌.
	TmpHead = Head;
	while (Head->rightnext != NULL)
	{
		Head = Head->rightnext;
	}
	Head->rightnext = TmpHead; 
	TmpHead->leftnext = Head; 
	Head = TmpHead; // Head를 다시 초기지점으로 초기화.
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
void InsertList(int data) // 연결리스트 삽입함수.
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
int DeleteList() // 연결리스트 삭제함수.
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