/*
문제9. 2진수 출력

힌트 및 요구 사항

a. 사용자에게 n(2진수의 자릿수)과 k(2진수가 포함해야 할 1의 개수)를 입력받는다.
예를 들어, n=3 이고 k=1이면 001 010 100
b. n과 k의 범위는 0~10까지 이다.
c. k는 n보다 작거나 같아야 한다.
d. n자리의 2진수 중 1의 개수가 k개인 수를 모두 출력한다.
e. 결과값을 오름차순으로 정렬한다.
*/


/* 방법1 */

#include <stdio.h>
#include <math.h>
void main()
{
	int n,		/* 2진수의 자릿수 -> n */
		k,		/* 2진수가 포함해야 할 1의 개수 -> k */
		NUM,	/* 2진수 n자리로 표현 가능한 범위 */
		temp,	/* 2의 제곱승 범위 */
		i,		/* 제어변수 */
		cnt		/* 1의 개수 count 값 */;

	printf("음이 아닌 정수 n입력: ");
	scanf_s("%d", &n);
	printf("음이 아닌 정수 k입력: ");
	scanf_s("%d", &k);

	for (NUM = 0, cnt = 0; NUM < (int)pow((double)2, n); NUM++, cnt = 0)
	{
		for (i = 0; i <= n - 1; i++)
		{
			// temp : 2의 제곱[ 1(1), 2(10), 4(100), 8(1000), ...]
			temp = (int)pow((double)2, i);

			/* &연산을 통해 자리수가 1이면 count++
			ex) NUM = 5
			5(101) & 1(001) = 1(001)
			5(101) & 2(010) = 0(000)
			5(101) & 4(100) = 4(100) */
			if ((NUM & temp) == temp)
				cnt++;
		}
		if (cnt == k)
		{
			// 해당하는 NUM을 2진수처럼 출력
			for (i = n - 1; i >= 0; i--)
				printf("%d", NUM >> i & 1);
			printf(" ");
		}
	}

}

/* 방법2 */

//#include <stdio.h>
//#include <malloc.h>
//#include <math.h>
//void main()
//{
//	int n, /* 2진수의 자릿수 -> n */
//		k, /* 2진수가 포함해야 할 1의 개수 -> k */
//		NUM,
//		i, j, /* 제어변수 */
//		cnt;
//	char *p;
//
//	printf("음이 아닌 정수 n입력: ");
//	scanf_s("%d", &n);
//	printf("음이 아닌 정수 k입력: ");
//	scanf_s("%d", &k);
//	p = (char *)malloc(n); // 2진수 자리수(n) 만큼 공간 할당
//
//	for(NUM=0; NUM < (int)pow((double)2,n); NUM++)
//	{
//		for(i=n-1, j=0, cnt=0;
//			i>=0;
//			i--, j++)
//		{
//			//자리수 값이 1인것 카운트
//			if( (p[j] = NUM>>i&1) == 1 )
//				cnt++;
//		}
//		//포함한 1의 개수가 입력한 값(k)와 같을면 출력
//		if(k == cnt) 
//		{
//			for(i=0; i<n; i++)
//			{
//				printf("%d", p[i]);
//			}
//			printf(" ");
//		}	
//	}
//}
