#include<stdio.h>
int main()
{
	int a[5], i;
	int Max, Min;
	printf("수 입력\n");

	for (i = 0; i<5; i++)
		scanf_s("%d", a + i);

	Max = Min = a[0];
	for (i = 0; i < 5; i++)
	{
		if (Max < a[i])
			Max = a[i];

		if (Min > a[i])
			Min = a[i];
	}
	printf("최댓값 :%d\n", Max);
	printf("최솟값 :%d\n", Min);

	return 0;
}