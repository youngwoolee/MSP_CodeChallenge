#include<stdio.h>
int main()
{
	int a[5], i;
	int Max, Min;
	printf("�� �Է�\n");

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
	printf("�ִ� :%d\n", Max);
	printf("�ּڰ� :%d\n", Min);

	return 0;
}