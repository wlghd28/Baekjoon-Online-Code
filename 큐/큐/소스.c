#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char Queue[10000];
//int VertexGraph[1000][1000]; // 그래프를 인접행렬로 표현.
//int** VertexGraph;
//int Queue[1000]; // 정점들의 데이터를 저장할 큐.
//int* Queue;
int Stack[1000]; // 정점들의 데이터를 저장할 스택.
int Stackindex = -1; // 스택의 인덱스참조 변수.
//int frontindex = -1; // 큐의 front 변수.
//int backindex = -1; // 큐의 back 변수.
//int Count = 0; // BFS 탐색할때 모든 정점 순회했는지 판단하는 변수.
//char CirculJudge[1000]; // 정점 순회판단 배열.
//char* CirculJudge;
//void DFS(int Index, int Vertexsize);// 깊이 우선 탐색
//void BFS(int Index, int Vertexsize);// 너비 우선 탐색
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
	// 몇 번째로 인쇄되는지 나타내는 변수, 현재 인덱스를 가리키는 변수.
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
			InsertQueue(T); // 큐에 우선순위들을 삽입.
			if (i == N)
				front->Mark = 'o'; // 몇 번째 인쇄됬는지 궁금한 원소 마크.
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
			DeleteQueue(); // 남아있는 큐를 비워준다.
		}
		free(front); // 마지막에 남은 원소 1개 삭제.
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
		VertexGraph[Vertex1 - 1][Vertex2 - 1] = 1; // 연결된 두정점을 1로 초기화.
		VertexGraph[Vertex2 - 1][Vertex1 - 1] = 1; // 양방향 연결선.
	}
	DFS(V - 1, N); // DFS 탐색.
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		CirculJudge[i] = NULL;
	}
	BFS(V - 1, N); // BFS 탐색.
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
	getchar(); // N을 입력받을 때 생긴 널값 제거.

	for (int i = 0; i < N; i++)
	{
		gets(Command); // 명령을 받는다.

		if (strncmp(Command, "push", 4) == 0) // push 명령
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
		else if (strncmp(Command, "pop", 3) == 0) // pop 명령
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
		else if (strncmp(Command, "size", 4) == 0) // size 명령
		{
			printf("%d\n", frontindex - backindex);
		}
		else if (strncmp(Command, "empty", 5) == 0) // empty 명령
		{
			if (frontindex == backindex)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strncmp(Command, "front", 5) == 0) // front 명령
		{
			if (frontindex == backindex)
				printf("-1\n");
			else
				printf("%d\n", Queue[backindex + 1]);
			
		}
		else if (strncmp(Command, "back", 4) == 0) // back 명령
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
void DFS(int Index, int Vertexsize)// 깊이 우선 탐색 함수.
{
	CirculJudge[Index] = 't';// 순회했다는 표시.
	//InsertStack(Index + 1);// 정점의 데이터를 스택에 삽입.
	printf("%d ", Index + 1);
	for (int i = 0; i < Vertexsize; ++i)
	{
		if (VertexGraph[Index][i] == 1 && CirculJudge[i] != 't') 
			//현재 정점과 연결되있는 정점이면서 순회하지 않은 정점.
		{
			DFS(i, Vertexsize); // 현재정점으로부터 DFS 탐색.
		}
		// 조건문이 실행되지 않을경우는 모든 정점이 순회된 경우.
	}
}
void BFS(int Index, int Vertexsize)
{
	printf("%d ", Index + 1);
	if(Count == 0)
		CirculJudge[Index] = 't';// 첫 정점순회 했다는 표시.
	Count++; // 현재 순회한 정점의 개수.
	for (int i = 0; i < Vertexsize; ++i)
	{
		if (VertexGraph[Index][i] == 1 && CirculJudge[i] != 't')
			// 현재정점과 인접하면서 순회하지 않은 정점.
		{
			InsertQueue(i + 1); // 큐에 현재정점데이터 삽입.
			CirculJudge[i] = 't'; // 순회했다는 표시.
		}
	}
	if (Count == Vertexsize || frontindex == backindex) // 모든 정점을 순회했을 때 종료.
		return;
	else
	{
		Index = DeleteQueue(); // 큐에있는 정점데이터 한개추출.
							   // 추출한 정점 데이터로 이동한 후.
		BFS(Index - 1, Vertexsize); // BFS 탐색 시작.
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