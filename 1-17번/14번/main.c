/*
���� 14. ���ڸ� �Է� �޾� �������� ��ȯ�ϱ�
��Ʈ �� ���ǻ���
a) 0~9999 ������ ������ �Է� �ް�, �Է� ���� ������ �������� ��ȯ�Ͽ� ����ϴ� ���α׷��� �����϶�.
b) ��, ������ ��� ��( �� - ����, 10000 ) �Է� �� Out of Range! �� ����Ѵ�.
c) ��ҹ��ڴ� �������� �ʴ´�.

����)
0 �Է� �� -> ����� 'zero'
5  �Է� �� -> ����� 'five'
99  �Է� �� -> ����� 'ninety nine'
555  �Է� �� -> ����� 'five hundred fifty five'
3000 �Է� �� -> ����� 'three thousand'
9999 �Է� �� -> ����� 'nine thousand nine hundred ninety nine'
5100 �Է� �� -> ����� 'five thousand one hundred'
-1 �Է� �� -> ����� 'Out of Range!'
10000 �Է� �� -> ����� 'Out of Range!
*/
#include <stdio.h>
#include <string.h>

void main()
{

	int NUM,	// �Է¹��� ����
		i;		// ���� ����

	char str[100];	// �������� ��ȯ�� ���ڰ� ����� ���� �迭

	strcpy_s(str, 100, ""); // strcat���� ���ڿ� �̾� ���̱� ���� �غ�
	printf("������ �Է����ּ��� : ");
	scanf_s("%d", &NUM);	// ���� �Է¹ޱ�.

	if (NUM == 0)
	{
		printf("Zero\n");
		return;
	}

	// õ�� �ڸ������� �������� �����ڿ��� ��ȯ �� �迭�� ����.
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
				// 10~19 ������ ���� ó��
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
				i = 1; // for�� ���� ���� ����
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