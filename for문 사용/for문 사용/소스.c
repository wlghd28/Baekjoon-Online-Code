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
		Total += num[i] - '0'; // 아이디어 기억.
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
	//오늘은 2007년 1월 1일 월요일이다.
	//그렇다면 2007년 x월 y일은 무슨 요일일까 ? 이를 알아내는 프로그램을 작성하시오.
	//첫째 줄에 빈 칸을 사이에 두고 x(1≤x≤12)와 y(1≤y≤31)이 주어진다.
	//참고로 2007년에는 1, 3, 5, 7, 8, 10, 12월은 31일까지, 4, 6, 9, 11월은 30일까지,
	//2월은 28일까지 있다.
	//첫째 줄에 x월 y일이 무슨 요일인지에 따라 SUN, MON, TUE, WED, THU, FRI, SAT중 하나를 출력한다.

	int x, y; // 월, 일을 받을 변수.
	int i = 0, day = 0; // 반복문 변수와 총 일수.
	int flag = 1; // 30또는 31을 더할때 스위칭할 변수.
	scanf_s("%d %d", &x, &y);

	if (x <= 2) // 1~2월 계산
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
	else if (x > 2 && x < 8) // 3~7월 계산
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
		day = day + y - 2; // 총 일수 계산.
	}
	else // 8~12월 계산
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