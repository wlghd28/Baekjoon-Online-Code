#include <stdio.h>

void HeapSort(int* A, int size);
void Heapify(int index, int index2);
void BuildHeap(int* A, int size);
void swap(int index1, int index2);
int Compare(int index1, int index2);
int Num[1000001];

int main(void)
{
	int N;
	scanf_s("%d", &N);
	
	for (int i = 1; i < N + 1; i++)
	{
		scanf_s("%d", &Num[i]);
	}
	if (N == 1)
	{
		printf("%d\n", Num[N]);
		return 0;
	}
	HeapSort(Num, N + 1);
	for (int i = 1; i < N + 1; ++i)
	{
		printf("%d\n", Num[i]);
	}
	return 0;
}
void HeapSort(int* A, int size)
{
	int index = size - 1;
	BuildHeap(A, size); // 힙트리 최초로 만든다.
	while (index != 2) {
		swap(1, index); // 루트노드와 맨끝노드 교환.
		index--;  // 맨끝노드는 연결을 끊는다.
		Heapify(1, index); // 힙트리 재구성.
	}
	if (A[index] < A[1])
		swap(index, 1);
}
void BuildHeap(int* A, int size)
{
	int index = 2, tmpindex;
	while (index < size) {
		tmpindex = index;
		while (tmpindex != 1) {
			if (A[tmpindex] > A[tmpindex / 2])
				swap(tmpindex, tmpindex / 2);
			else
				break;
			tmpindex /= 2;
		}
		index++;
	}
}
void Heapify(int index, int index2)
{
	int tmp;
	while (index * 2 + 1 <= index2)
	{
		tmp = Compare(index * 2, index * 2 + 1);
		if (Num[tmp] > Num[index])
			swap(tmp, index);
		else
			return;
		index = tmp;
	}
	if (index * 2 == index2)
	{
		if(Num[index * 2]>Num[index])
			swap(index * 2, index);
	}
}
void swap(int index1, int index2)
{
	int tmp;
	tmp = Num[index1];
	Num[index1] = Num[index2];
	Num[index2] = tmp;
}
int Compare(int index1, int index2)
{
	if (Num[index1] > Num[index2])
		return index1;
	else
		return index2;
}