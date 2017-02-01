/*
문제12. 아나그램(anagram)
요구사항
a. 두 문자열에 대하여 서로 '아나그램(anagram)' 관계에 있는지 판별하는 프로그램을 작성한다.
b. 아나그램(anagram)이란, 문자열의 문자들이 재배열하여
다른 문자열과 똑같은 문자열을 형성할 수 있으면 두 문자열을 아나그램이라고 한다.
c. 예를 들면, 문자열 "THE EYES"와 "THEY SEE"는 서로 아나그램이라고 할 수 있다.
이 두 문자열은 알파벳 E가 3개, H가 1개, T가 1개, S가 1개, Y가 1개로
같은 구성의 알파벳으로 형성되어 있기 때문이다.

요구사항
a. 프로그램을 작성할 때, 특수문자나 공백 또는 대소문자 차이는 판별에서 무시하도록 한다.
즉, 어떤 문자가 입력되어도 오직 문자로만 아나그램을 판별하도록 한다.
*/
#include <stdio.h>
#include <string.h>
void main()
{
	// 문자열 입력 받을 배열 선언
	char str1[100],
		str2[100];

	// 해당 알파벳별(대소문자 구분X) 나온 횟수 저장할 배열 선언
	int Alpa_cnt1[26],	// ex) Alpa_cnt1[0] = ('a' 또는 'A'가 나온 횟수)
		Alpa_cnt2[26];	//	   Alpa_cnt1[1] = ('b' 또는 'B'가 나온 횟수)

	// 제어 변수
	int	i;

	// 사용자 선택(y/n)
	char choice;

	do{
		// COUNT 값 0으로 초기화
		for (i = 0; i<26; i++)
			Alpa_cnt1[i] = Alpa_cnt2[i] = 0;

		// 비교할 문자열 입력
		printf("Input the 1st sentence: ");
		gets_s(str1, 100);
		printf("Input the 2st sentence: ");
		gets_s(str2, 100);

		// 첫 번째 문자열의 알파벳별 횟수 계산  
		for (i = 0; (unsigned int)i < strlen(str1); i++)
		{
			if (str1[i] >= 'A' && str1[i] <= 'Z')
				Alpa_cnt1[str1[i] - 'A']++;
			else if (str1[i] >= 'a' && str1[i] <= 'z')
				Alpa_cnt1[str1[i] - 'a']++;
		}

		// 두 번째 문자열의 알파벳별 횟수 계산
		for (i = 0; (unsigned int)i < strlen(str2); i++)
		{
			if (str2[i] >= 'A' && str2[i] <= 'Z')
				Alpa_cnt2[str2[i] - 'A']++;
			else if (str2[i] >= 'a' && str2[i] <= 'z')
				Alpa_cnt2[str2[i] - 'a']++;
		}

		// 계산된 결과 비교
		for (i = 0; i<26; i++)
		if (Alpa_cnt1[i] != Alpa_cnt2[i])
			break;

		if (i == 26)
			printf("Yes! They are anagrams!!\n");
		else
			printf("No! They are not anagrams!!\n");

		// 사용자 선택
		printf("Continue? <y/N>");
		choice = getc(stdin);
		fflush(stdin);

		printf("\n");
	} while (choice != 'n' && choice != 'N');	// 반복문 조건

	printf("Thank you !!\n");
}