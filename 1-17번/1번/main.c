#include<stdio.h>

void main()
{
	int dan; //������ �� ���� �Է� ���� ����
	int i, j;
	printf("����� ���� �Է����ּ���:");
	scanf_s("%d", &dan, 4);

	while (dan <= 0 || dan > 9)
	{
		printf("1~9������ ���ڷ� �ٽ� �Է����ּ���:------------\n");
		printf("����� ���� �Է����ּ���:");
		scanf_s("%d", &dan, 4);
	}

	for (i = 1; i <= 9; i++)
	{
		for (j = 0; j < dan * i; j++)
			printf("*");
		printf("\n");
	}
	fflush(stdin);
	getchar();
}
