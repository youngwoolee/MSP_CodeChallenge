#include<stdio.h>

void main()
{
	int dan; //구구단 단 수를 입력 받을 변수
	int i, j;
	printf("출력할 단을 입력해주세요:");
	scanf_s("%d", &dan, 4);

	while (dan <= 0 || dan > 9)
	{
		printf("1~9사이의 숫자로 다시 입력해주세요:------------\n");
		printf("출력할 단을 입력해주세요:");
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
