#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char Queue[10000];
//int VertexGraph[1000][1000]; // �׷����� ������ķ� ǥ��.
//int** VertexGraph;
//int Queue[1000]; // �������� �����͸� ������ ť.
//int* Queue;
int Stack[1000]; // �������� �����͸� ������ ����.
int Stackindex = -1; // ������ �ε������� ����.
//int frontindex = -1; // ť�� front ����.
//int backindex = -1; // ť�� back ����.
//int Count = 0; // BFS Ž���Ҷ� ��� ���� ��ȸ�ߴ��� �Ǵ��ϴ� ����.
//char CirculJudge[1000]; // ���� ��ȸ�Ǵ� �迭.
//char* CirculJudge;
//void DFS(int Index, int Vertexsize);// ���� �켱 Ž��
//void BFS(int Index, int Vertexsize);// �ʺ� �켱 Ž��
void InsertStack(int data);
//void InsertQueue(int data);
//int DeleteQueue();
/*
struct Printer {
	int priority;
	char Mark;
	struct Printer* next;
};
void InsertQueue(struct Printer T);
struct Printer DeleteQueue();
struct Printer* front;
struct Printer* back;
*/
int main(void)
{
	int Josepus[1000];
	int N, K, count = 0, index = -1;
	scanf_s("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
	{
		Josepus[i] = i + 1;
	}
	while (Stackindex != N - 1)
	{
		if (Josepus[++index] != 0)
		{
			count++;
		}
		if (count == K)
		{
			InsertStack(Josepus[index]);
			Josepus[index] = 0;
			count = 0;
		}	
		if (index == N - 1)
		{
			index = -1;
		}
	}
	for (int i = 0; i < N; i++)
	{
		printf("%d ", Stack[i]);
	}

	/*
	int testcase, M, N, index;
	struct Printer T;
	struct Printer* indexpointer;
	// �� ��°�� �μ�Ǵ��� ��Ÿ���� ����, ���� �ε����� ����Ű�� ����.
	scanf_s("%d", &testcase);
	for (int i = 0; i < testcase; i++)
	{
		T.priority = 0;
		T.Mark = NULL;
		index = 0;
		front = NULL;
		back = NULL;
		scanf_s("%d %d", &M, &N);
		for (int i = 0; i < M; i++)
		{
			scanf_s("%d", &T.priority);
			InsertQueue(T); // ť�� �켱�������� ����.
			if (i == N)
				front->Mark = 'o'; // �� ��° �μ����� �ñ��� ���� ��ũ.
		}
		while (1)
		{
			indexpointer = back;
			while (indexpointer != NULL)
			{
				if (back->priority < indexpointer->priority)
				{
					T = DeleteQueue();
					InsertQueue(T);
					break;
				}
				indexpointer = indexpointer->next;
			}
			if (indexpointer == NULL)
			{
				T = DeleteQueue();
				index++;
				if (T.Mark == 'o')		
					break;
			}
		}
		while (back != front)
		{
			DeleteQueue(); // �����ִ� ť�� ����ش�.
		}
		free(front); // �������� ���� ���� 1�� ����.
		printf("%d\n", index);
	}
	*/
	/*
	int N, M, V, Vertex1, Vertex2;
	scanf_s("%d %d %d", &N, &M, &V);
	Queue = (int*)malloc(sizeof(int)*N);
	CirculJudge = (char*)malloc(sizeof(char)*N);
	VertexGraph = (int**)malloc(sizeof(int*)*N);
	for (int i = 0; i < N; i++)
	{
		VertexGraph[i] = (int*)malloc(sizeof(int)*N);
	}
	for (int i = 0; i < M; i++)
	{
		scanf_s("%d %d", &Vertex1, &Vertex2);
		VertexGraph[Vertex1 - 1][Vertex2 - 1] = 1; // ����� �������� 1�� �ʱ�ȭ.
		VertexGraph[Vertex2 - 1][Vertex1 - 1] = 1; // ����� ���ἱ.
	}
	DFS(V - 1, N); // DFS Ž��.
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		CirculJudge[i] = NULL;
	}
	BFS(V - 1, N); // BFS Ž��.
	for (int i = 0; i < N; i++)
	{
		free(VertexGraph[i]);
	}
	free(Queue);
	free(CirculJudge);
	free(VertexGraph);
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
			Queue[++frontindex] = atoi(Integer);
			if (frontindex == 9999)
			{
				frontindex = -1;
			}
		}
		else if (strncmp(Command, "pop", 3) == 0) // pop ���
		{
			if (frontindex == backindex)
				printf("-1\n");
			else
			{
				printf("%d\n", Queue[++backindex]);
				Queue[backindex] = 0;
				if (backindex == 9999)
				{
					backindex = -1;
				}
			}
		}
		else if (strncmp(Command, "size", 4) == 0) // size ���
		{
			printf("%d\n", frontindex - backindex);
		}
		else if (strncmp(Command, "empty", 5) == 0) // empty ���
		{
			if (frontindex == backindex)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strncmp(Command, "front", 5) == 0) // front ���
		{
			if (frontindex == backindex)
				printf("-1\n");
			else
				printf("%d\n", Queue[backindex + 1]);
			
		}
		else if (strncmp(Command, "back", 4) == 0) // back ���
		{
			if (frontindex == backindex)
				printf("-1\n");
			else
				printf("%d\n", Queue[frontindex]);
		}
	}
	*/
		return 0;
}
/*
void DFS(int Index, int Vertexsize)// ���� �켱 Ž�� �Լ�.
{
	CirculJudge[Index] = 't';// ��ȸ�ߴٴ� ǥ��.
	//InsertStack(Index + 1);// ������ �����͸� ���ÿ� ����.
	printf("%d ", Index + 1);
	for (int i = 0; i < Vertexsize; ++i)
	{
		if (VertexGraph[Index][i] == 1 && CirculJudge[i] != 't') 
			//���� ������ ������ִ� �����̸鼭 ��ȸ���� ���� ����.
		{
			DFS(i, Vertexsize); // �����������κ��� DFS Ž��.
		}
		// ���ǹ��� ������� �������� ��� ������ ��ȸ�� ���.
	}
}
void BFS(int Index, int Vertexsize)
{
	printf("%d ", Index + 1);
	if(Count == 0)
		CirculJudge[Index] = 't';// ù ������ȸ �ߴٴ� ǥ��.
	Count++; // ���� ��ȸ�� ������ ����.
	for (int i = 0; i < Vertexsize; ++i)
	{
		if (VertexGraph[Index][i] == 1 && CirculJudge[i] != 't')
			// ���������� �����ϸ鼭 ��ȸ���� ���� ����.
		{
			InsertQueue(i + 1); // ť�� �������������� ����.
			CirculJudge[i] = 't'; // ��ȸ�ߴٴ� ǥ��.
		}
	}
	if (Count == Vertexsize || frontindex == backindex) // ��� ������ ��ȸ���� �� ����.
		return;
	else
	{
		Index = DeleteQueue(); // ť���ִ� ���������� �Ѱ�����.
							   // ������ ���� �����ͷ� �̵��� ��.
		BFS(Index - 1, Vertexsize); // BFS Ž�� ����.
	}
}
*/

void InsertStack(int data)
{
	Stack[++Stackindex] = data;
}

/*
void InsertQueue(int data)
{
	Queue[++frontindex] = data;
	if (frontindex == 999)
		frontindex = -1;
}
int DeleteQueue()
{
	int tmp;
	tmp = Queue[++backindex];
	Queue[backindex] = 0;
	if (backindex == 999)
		backindex = -1;
	return tmp;
}
*/
/*
void InsertQueue(struct Printer T)
{
	struct Printer* tmp = (struct Printer*)malloc(sizeof(struct Printer));
	tmp->Mark = T.Mark;
	tmp->priority = T.priority;
	if (back == NULL)
	{
		tmp->next = front;
		front = tmp;
		back = tmp;
	}
	else
	{
		front->next = tmp;
		tmp->next = NULL;
		front = tmp;
	}
}
struct Printer DeleteQueue()
{
	struct Printer Content;
	struct Printer* tmp;
	Content.priority = back->priority;
	Content.Mark = back->Mark;
	tmp = back;
	back = back->next;
	free(tmp);
	if (back == NULL)
		front = NULL;
	return Content;
}
*/