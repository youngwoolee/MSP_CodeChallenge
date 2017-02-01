/*
문제 13. 입력받은 두 수 사이의 소수 구하기

힌트 및 유의사항

1~300 사이의 정수를 입력 받고, 입력 받은 정수 사이에 소수를 출력한다.
예) 1부터 13사이의 소수( 1<소수<13) : 2, 3, 5, 7, 11
*/
#include <stdio.h>
void main()
{
	int n1, n2;
	int i, j;
	int idx = 0;

	printf("1부터 300 사이 정수 두개 입력 : ");
	scanf_s("%d%d", &n1, &n2);

	for (i = n1 + 1; i<n2; i++)
	{
		for (j = 2; j< i; j++)
		if (i%j == 0)
			break;

		if (j == i)
			printf("%d\n", i);
	}
}