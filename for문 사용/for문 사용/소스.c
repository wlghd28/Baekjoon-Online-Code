#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	
	/*
	int A, B;
	while (scanf("%d %d", &A, &B) != EOF) {
		printf("%d\n", A + B);
	}
	*/
	/*
	int N,Total = 0;
	scanf_s("%d", &N);
	char num[100] = {NULL};
	getchar();
	gets(num);
	for (int i = 0; i < N; i++)
	{
		Total += num[i] - '0'; // ���̵�� ���.
	}
	printf("%d\n", Total);
	*/
	/*
	int index = 0;
	char N[100] = { NULL };
	gets(N);
	while (N[index] != '\0')
	{
		for (int i = 0; i < 10; i++)
		{
			printf("%c", N[index]);
			index++;
			if (N[index] == '\0')
				break;
		}
		printf("\n");
	}
	*/
	/*
	//������ 2007�� 1�� 1�� �������̴�.
	//�׷��ٸ� 2007�� x�� y���� ���� �����ϱ� ? �̸� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.
	//ù° �ٿ� �� ĭ�� ���̿� �ΰ� x(1��x��12)�� y(1��y��31)�� �־�����.
	//����� 2007�⿡�� 1, 3, 5, 7, 8, 10, 12���� 31�ϱ���, 4, 6, 9, 11���� 30�ϱ���,
	//2���� 28�ϱ��� �ִ�.
	//ù° �ٿ� x�� y���� ���� ���������� ���� SUN, MON, TUE, WED, THU, FRI, SAT�� �ϳ��� ����Ѵ�.

	int x, y; // ��, ���� ���� ����.
	int i = 0, day = 0; // �ݺ��� ������ �� �ϼ�.
	int flag = 1; // 30�Ǵ� 31�� ���Ҷ� ����Ī�� ����.
	scanf_s("%d %d", &x, &y);

	if (x <= 2) // 1~2�� ���
	{
		for (i = 0; i < x - 1; i++)
		{
			if (flag == 1)
			{
				day += 31;
				flag *= -1;
			}
			else
			{
				day += 30;
				flag *= -1;
			}
		}
		day = day + y;
	}
	else if (x > 2 && x < 8) // 3~7�� ���
	{
		flag = 1;
		for (i = 0; i < x - 1; i++)
		{
			if (flag == 1)
			{
				day += 31;
				flag *= -1;
			}
			else
			{
				day += 30;
				flag *= -1;
			}
		}
		day = day + y - 2; // �� �ϼ� ���.
	}
	else // 8~12�� ���
	{
		flag = 1;
		for (i = 7; i < x - 1; i++)
		{
			if (flag == 1)
			{
				day += 31;
				flag *= -1;
			}
			else
			{
				day += 30;
				flag *= -1;
			}
		}
		day = day + 212 + y;
	}
	switch (day % 7)
	{
	    case 0:
		    printf("SUN\n");
		    break;
		case 1:
			printf("MON\n");
			break;
		case 2:
			printf("TUE\n");
			break;
		case 3:
			printf("WED\n");
			break;
		case 4:
			printf("THU\n");
			break;
		case 5:
			printf("FRI\n");
			break;
		case 6:
			printf("SAT\n");
			break;
	}
	*/

	return 0;
}