#include <stdio.h>

int Discriminant(int x1, int y1, int r1, int x2, int y2, int r2); // ÆÇº°½Ä.
int main(void)
{
	int T, x1,y1,r1,r2,x2,y2;
	scanf_s("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf_s("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		printf("%d\n", Discriminant(x1, y1, r1, x2, y2, r2));
	}
	
	return 0;
}
int Discriminant(int x1, int y1, int r1, int x2, int y2, int r2)
{
	int distance, min, max;
	distance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	if (r1 > r2)
	{
		min = r2;
		max = r1;
	}
	else
	{
		min = r1;
		max = r2;
	}
	if (distance == 0 && max == min)
		return -1;
	else if (distance == (max - min)*(max - min) || distance == (max + min)*(max + min))
		return 1;
	else if (distance < (max + min)*(max + min) && distance >(max - min)*(max - min))
		return 2;
	else
		return 0;
}