/*
문제 14. 숫자를 입력 받아 영문으로 변환하기
힌트 및 유의사항
a) 0~9999 까지의 정수를 입력 받고, 입력 받은 정수를 영문으로 변환하여 출력하는 프로그램을 구현하라.
b) 단, 범위를 벗어난 수( 예 - 음수, 10000 ) 입력 시 Out of Range! 를 출력한다.
c) 대소문자는 구분하지 않는다.

예시)
0 입력 시 -> 결과값 'zero'
5  입력 시 -> 결과값 'five'
99  입력 시 -> 결과값 'ninety nine'
555  입력 시 -> 결과값 'five hundred fifty five'
3000 입력 시 -> 결과값 'three thousand'
9999 입력 시 -> 결과값 'nine thousand nine hundred ninety nine'
5100 입력 시 -> 결과값 'five thousand one hundred'
-1 입력 시 -> 결과값 'Out of Range!'
10000 입력 시 -> 결과값 'Out of Range!
*/
#include <stdio.h>
#include <string.h>

void main()
{

	int NUM,	// 입력받을 숫자
		i;		// 제어 변수

	char str[100];	// 영문으로 변환된 숫자가 저장될 문자 배열

	strcpy_s(str, 100, ""); // strcat으로 문자열 이어 붙이기 위한 준비
	printf("정수를 입력해주세요 : ");
	scanf_s("%d", &NUM);	// 숫자 입력받기.

	if (NUM == 0)
	{
		printf("Zero\n");
		return;
	}

	// 천의 자리수부터 차례차례 영문자열로 변환 후 배열에 저장.
	for (i = 1000; i != 0; i /= 10)
	{
		switch (NUM / i)
		{
		case 0:
			break;
		case 1:
			switch (i)
			{
			case 1000:	strcat_s(str, 100, "one thousand "); break;
			case 100:	strcat_s(str, 100, "one hundred "); break;
				// 10~19 범위는 예외 처리
			case 10:
				if (NUM == 10)	strcat_s(str, 100, "ten ");
				else if (NUM == 11)	strcat_s(str, 100, "eleven ");
				else if (NUM == 12)	strcat_s(str, 100, "twelve ");
				else if (NUM == 13)	strcat_s(str, 100, "thirteen ");
				else if (NUM == 14)	strcat_s(str, 100, "fourteen ");
				else if (NUM == 15)	strcat_s(str, 100, "fifteen ");
				else if (NUM == 16)	strcat_s(str, 100, "sixteen ");
				else if (NUM == 17)	strcat_s(str, 100, "seventeen ");
				else if (NUM == 18)	strcat_s(str, 100, "eighteen ");
				else if (NUM == 19)	strcat_s(str, 100, "nineteen ");
				i = 1; // for문 종료 위한 설정
				break;
			case 1:		strcat_s(str, 100, "one "); break;
			}
			break;
		case 2:
			switch (i)
			{
			case 1000:	strcat_s(str, 100, "two thousand "); break;
			case 100:	strcat_s(str, 100, "two hundred "); break;
			case 10:	strcat_s(str, 100, "twenty "); break;
			case 1:		strcat_s(str, 100, "two "); break;
			}
			break;
		case 3:
			switch (i)
			{
			case 1000:	strcat_s(str, 100, "three thousand "); break;
			case 100:	strcat_s(str, 100, "three hundred "); break;
			case 10:	strcat_s(str, 100, "thirty "); break;
			case 1:		strcat_s(str, 100, "three "); break;
			}
			break;
		case 4:
			switch (i)
			{
			case 1000:	strcat_s(str, 100, "four thousand "); break;
			case 100:	strcat_s(str, 100, "four hundred "); break;
			case 10:	strcat_s(str, 100, "forty "); break;
			case 1:		strcat_s(str, 100, "four "); break;
			}
			break;
		case 5:
			switch (i)
			{
			case 1000:	strcat_s(str, 100, "five thousand "); break;
			case 100:	strcat_s(str, 100, "five hundred "); break;
			case 10:	strcat_s(str, 100, "fifty "); break;
			case 1:		strcat_s(str, 100, "five "); break;
			}
			break;
		case 6:
			switch (i)
			{
			case 1000:	strcat_s(str, 100, "six thousand "); break;
			case 100:	strcat_s(str, 100, "six hundred "); break;
			case 10:	strcat_s(str, 100, "sixty "); break;
			case 1:		strcat_s(str, 100, "six "); break;
			}
			break;
		case 7:
			switch (i)
			{
			case 1000:	strcat_s(str, 100, "seven thousand "); break;
			case 100:	strcat_s(str, 100, "seven hundred "); break;
			case 10:	strcat_s(str, 100, "seventy "); break;
			case 1:		strcat_s(str, 100, "seven "); break;
			}
			break;
		case 8:
			switch (i)
			{
			case 1000:	strcat_s(str, 100, "eight thousand "); break;
			case 100:	strcat_s(str, 100, "eight hundred "); break;
			case 10:	strcat_s(str, 100, "eighty "); break;
			case 1:		strcat_s(str, 100, "eight "); break;
			}
			break;
		case 9:
			switch (i)
			{
			case 1000:	strcat_s(str, 100, "nine thousand "); break;
			case 100:	strcat_s(str, 100, "nine hundred "); break;
			case 10:	strcat_s(str, 100, "ninety "); break;
			case 1:		strcat_s(str, 100, "nine "); break;
			}
			break;
		default:
			printf("Out of Range!\n");
			return;
		}
		NUM %= i;
	}
	printf("%s\n", str);
}