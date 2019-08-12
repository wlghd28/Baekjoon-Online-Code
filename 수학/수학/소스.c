#include <stdio.h>

int main(void)
{
	double R;
	scanf_s("%lf", &R);
	printf("%6lf\n", R * R * 3.14159265358979323846);
	printf("%6lf\n", (2 * R) * (2 * R) / 2);

	/*
	int A, B, C;
	while (1)
	{
		scanf_s("%d %d %d", &A, &B, &C);
		if (A == 0 && B == 0 && C == 0)
			return;
		if ((A * A == B * B + C * C) || (B * B == A * A + C * C) || (C * C == B * B + A * A))
			printf("right\n");
		else
			printf("wrong\n");
	}
	*/
	/*
	int X, Y;
	int PointX[3];
	int PointY[3];
	int CheckX[1001];
	int CheckY[1001];
	for (int i = 0; i < 1001; i++) {
		CheckX[i] = 0;
		CheckY[i] = 0;
	}
	for (int i = 0; i < 3; i++) {
		scanf_s("%d %d", &PointX[i], &PointY[i]);
		CheckX[PointX[i]]++;
		CheckY[PointY[i]]++;
	}
	for (int i = 0; i < 3; i++) {
		if (CheckX[PointX[i]] == 1)
			X = PointX[i];
		if (CheckY[PointY[i]] == 1)
			Y = PointY[i];
	}
	printf("%d %d\n", X, Y);
	*/
	/*
	int x, y, w, h, dist;
	int distance[4];
	scanf_s("%d %d %d %d", &x, &y, &w, &h);
	dist = x;
	distance[0] = x;
	distance[1] = y;
	distance[2] = w - x;
	distance[3] = h - y;

	for (int i = 1; i < 4; i++) {
		if (distance[i] < dist)
			dist = distance[i];
	}

	printf("%d\n", dist);
	*/
	/*
	long long A, B, V;
	scanf_s("%lld %lld %lld", &A, &B, &V);
	
	if ((V - A) % (A - B) == 0) {
		printf("%lld\n", (V - A) / (A - B) + 1);
	}
	else {
		printf("%lld\n", (V - A) / (A - B) + 2);
	}
	*/
	/*
	long long A, B, C, point;
	scanf_s("%lld %lld %lld", &A, &B, &C);
	if (B >= C)
		point = -1;
	else {
		point = A / (C - B) + 1;
	}
	printf("%lld\n", point);
	*/

	return 0;
}