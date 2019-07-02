#include <stdio.h>
#include <stdlib.h>

//int MaxIndex(int M, int N); // 카잉달력 최대 경우의수 구해주는 함수.
int main(void)
{
	/*
	//카잉 제국의 백성들은 특이한 달력을 사용한 것으로 알려져 있다. 
	//그들은 M과 N보다 작거나 같은 두 개의 자연수 x, y를 가지고 각 년도를 <x:y>와 같은 형식으로 표현하였다. 
	//그들은 이 세상의 시초에 해당하는 첫 번째 해를 <1:1>로 표현하고, 두 번째 해를 <2:2>로 표현하였다. 
	//<x:y>의 다음 해를 표현한 것을 <x':y'>이라고 하자. 만일 x < M 이면 x' = x + 1이고, 그렇지 않으면 x' = 1이다.
	//같은 방식으로 만일 y < N이면 y' = y + 1이고, 그렇지 않으면 y' = 1이다.
	//<M:N>은 그들 달력의 마지막 해로서, 이 해에 세상의 종말이 도래한다는 예언이 전해 온다.
	//예를 들어, M = 10 이고 N = 12라고 하자. 첫 번째 해는 <1:1>로 표현되고, 
	//11번째 해는 <1:11>로 표현된다. <3:1>은 13번째 해를 나타내고, <10:12>는 
	//마지막인 60번째 해를 나타낸다. 네 개의 정수 M, N, x와 y가 주어질 때,
	//<M:N>이 카잉 달력의 마지막 해라고 하면 <x:y>는 몇 번째 해를 나타내는지 구하는 프로그램을 작성하라.
	// 카잉 달력.
	int T, M, N, x, y;
	int index, yq, Max;
	int* k;
	scanf_s("%d", &T);
	k = (int*)malloc(sizeof(int)*T);
	for (int i = 0; i < T; i++)
	{
		scanf_s("%d %d %d %d", &M, &N, &x, &y);
		yq = x;
		index = x;
		Max = MaxIndex(M, N);
		while (1)
		{
			if ((yq == y) || index > Max)
				break;
			else
			{
				if (yq > N)
					yq -= N;
				else
				{
					yq += M;
					index += M;
				}
			}
		}
		if (index > Max)
		{
			k[i] = -1;
		}
		else
		{
			k[i] = index;
		}

	}

	for (int i = 0; i < T; i++)
	{
		printf("%d\n", k[i]);
	}
	free(k);
	*/

	/*
	//우현이는 어린 시절, 지구 외의 다른 행성에서도 인류들이 살아갈 수 있는 미래가 오리라 믿었다. 
	//그리고 그가 지구라는 세상에 발을 내려 놓은 지 23년이 지난 지금, 세계 최연소 ASNA 우주 비행사가
	//되어 새로운 세계에 발을 내려 놓는 영광의 순간을 기다리고 있다.
	//그가 탑승하게 될 우주선은 Alpha Centauri라는 새로운 인류의 보금자리를 개척하기 위한 대규모
	//생활 유지 시스템을 탑재하고 있기 때문에, 그 크기와 질량이 엄청난 이유로 최신기술력을 총 동원하여
	//개발한 공간이동 장치를 탑재하였다. 하지만 이 공간이동 장치는 이동 거리를 급격하게 늘릴 경우 기계에
	//심각한 결함이 발생하는 단점이 있어서, 이전 작동시기에 k광년을 이동하였을 때는 k-1 , k 혹은 k+1 광년만을
	//다시 이동할 수 있다. 예를 들어, 이 장치를 처음 작동시킬 경우 -1 , 0 , 1 광년을 이론상 이동할 수 있으나 
	//사실상 음수 혹은 0 거리만큼의 이동은 의미가 없으므로 1 광년을 이동할 수 있으며, 그 다음에는 0 , 1 , 2 광년을
	//이동할 수 있는 것이다. ( 여기서 다시 2광년을 이동한다면 다음 시기엔 1, 2, 3 광년을 이동할 수 있다. )
	//김우현은 공간이동 장치 작동시의 에너지 소모가 크다는 점을 잘 알고 있기 때문에 x지점에서 y지점을 향해 최소한의 작동 횟수로 이동하려 한다. 
	//하지만 y지점에 도착해서도 공간 이동장치의 안전성을 위하여 y지점에 도착하기 바로 직전의 이동거리는 반드시 1광년으로 하려 한다.
	//김우현을 위해 x지점부터 정확히 y지점으로 이동하는데 필요한 공간 이동 장치 작동 횟수의 최솟값을 구하는 프로그램을 작성하라.

	int T, x, y, i, j, Point1, Point2;
	int* Count;
	scanf_s("%d", &T);
	Count = (int*)malloc(sizeof(int)*T);

	for (int k = 0; k < T; k++)
	{
		scanf_s("%d %d", &x, &y);
		i = 0;
		j = 0;
		Point1 = x;
		Point2 = y;
		if (y - x == 1)
		{
			Count[k] = 1;
		}
		else
		{
			while (1)
			{
				if (Point1 >= Point2)
					break;
				i++;
				Point1 += i;
				if (Point1 < Point2)
				{
					j++;
					Point2 -= j;
				}
			}
			Count[k] = i + j;
		}
	}
	for (int i = 0; i < T; i++)
	{
		printf("%d\n", Count[i]);
	}

	free(Count);
	*/

	/*
	//다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다.
	//한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다. 
	//다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의
	//최솟값을 출력하시오. (6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.)
	char N[8] = {NULL, NULL,  NULL,  NULL,  NULL,  NULL,  NULL, NULL};
	int R[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i = 0, index;
	gets_s(N, 8);

	while (N[i] != NULL)
	{
		if (N[i] - '0' == 6 || N[i] - '0' == 9)
		{
			R[7]++;
		}
		else
		{
			R[N[i] - '0']++;
		}
		i++;
	}
	if (R[7] % 2 == 0)
	{
		R[7] /= 2;
	}
	else
	{
		R[7] = R[7] / 2 + 1;
	}
	index = R[0];
	for (int i = 1; i < 9; i++)
	{
		if (index < R[i])
		{
			index = R[i];
		}	
	}

	printf("%d\n", index);
	*/

	/*
	// ACM 호텔 문제.
	int T;
	int* Room;
	int Hotel[3];
	scanf_s("%d", &T);
	Room = (int*)malloc(sizeof(int)*T);
	for (int i = 0; i < T; i++)
	{
		scanf_s("%d %d %d", &Hotel[0], &Hotel[1], &Hotel[2]);
		if (Hotel[2] % Hotel[0] == 0)
		{
			Room[i] = Hotel[0] * 100 + (int)Hotel[2] / Hotel[0];
		}
		else
		{
			Room[i] = (Hotel[2] % Hotel[0]) * 100 + (1 + (int)Hotel[2]/Hotel[0]);
		}
	}
	for (int i = 0; i < T; i++)
	{
		printf("%d\n", Room[i]);
	}
	free(Room);
	*/

	/*
	// 벌집 규칙
	int N;
	int i = 1;
	scanf_s("%d", &N);

	while (1)
	{
		if (N < (3 * (i -1) * i + 2))
		{
			break;
		}
		i++;
	}

	printf("%d\n", i);
	*/

	return 0;
}
/*
int MaxIndex(int M, int N)
{
	int index = 1, y = 1;

	while (1)
	{
		if (y > N)
		{
			y -= N;
		}
		else
		{
			y += M;
			index++;
		}
		if (y == 1)
			break;
	}
	return M * (index - 1);
}
*/