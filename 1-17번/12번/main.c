/*
����12. �Ƴ��׷�(anagram)
�䱸����
a. �� ���ڿ��� ���Ͽ� ���� '�Ƴ��׷�(anagram)' ���迡 �ִ��� �Ǻ��ϴ� ���α׷��� �ۼ��Ѵ�.
b. �Ƴ��׷�(anagram)�̶�, ���ڿ��� ���ڵ��� ��迭�Ͽ�
�ٸ� ���ڿ��� �Ȱ��� ���ڿ��� ������ �� ������ �� ���ڿ��� �Ƴ��׷��̶�� �Ѵ�.
c. ���� ���, ���ڿ� "THE EYES"�� "THEY SEE"�� ���� �Ƴ��׷��̶�� �� �� �ִ�.
�� �� ���ڿ��� ���ĺ� E�� 3��, H�� 1��, T�� 1��, S�� 1��, Y�� 1����
���� ������ ���ĺ����� �����Ǿ� �ֱ� �����̴�.

�䱸����
a. ���α׷��� �ۼ��� ��, Ư�����ڳ� ���� �Ǵ� ��ҹ��� ���̴� �Ǻ����� �����ϵ��� �Ѵ�.
��, � ���ڰ� �ԷµǾ ���� ���ڷθ� �Ƴ��׷��� �Ǻ��ϵ��� �Ѵ�.
*/
#include <stdio.h>
#include <string.h>
void main()
{
	// ���ڿ� �Է� ���� �迭 ����
	char str1[100],
		str2[100];

	// �ش� ���ĺ���(��ҹ��� ����X) ���� Ƚ�� ������ �迭 ����
	int Alpa_cnt1[26],	// ex) Alpa_cnt1[0] = ('a' �Ǵ� 'A'�� ���� Ƚ��)
		Alpa_cnt2[26];	//	   Alpa_cnt1[1] = ('b' �Ǵ� 'B'�� ���� Ƚ��)

	// ���� ����
	int	i;

	// ����� ����(y/n)
	char choice;

	do{
		// COUNT �� 0���� �ʱ�ȭ
		for (i = 0; i<26; i++)
			Alpa_cnt1[i] = Alpa_cnt2[i] = 0;

		// ���� ���ڿ� �Է�
		printf("Input the 1st sentence: ");
		gets_s(str1, 100);
		printf("Input the 2st sentence: ");
		gets_s(str2, 100);

		// ù ��° ���ڿ��� ���ĺ��� Ƚ�� ���  
		for (i = 0; (unsigned int)i < strlen(str1); i++)
		{
			if (str1[i] >= 'A' && str1[i] <= 'Z')
				Alpa_cnt1[str1[i] - 'A']++;
			else if (str1[i] >= 'a' && str1[i] <= 'z')
				Alpa_cnt1[str1[i] - 'a']++;
		}

		// �� ��° ���ڿ��� ���ĺ��� Ƚ�� ���
		for (i = 0; (unsigned int)i < strlen(str2); i++)
		{
			if (str2[i] >= 'A' && str2[i] <= 'Z')
				Alpa_cnt2[str2[i] - 'A']++;
			else if (str2[i] >= 'a' && str2[i] <= 'z')
				Alpa_cnt2[str2[i] - 'a']++;
		}

		// ���� ��� ��
		for (i = 0; i<26; i++)
		if (Alpa_cnt1[i] != Alpa_cnt2[i])
			break;

		if (i == 26)
			printf("Yes! They are anagrams!!\n");
		else
			printf("No! They are not anagrams!!\n");

		// ����� ����
		printf("Continue? <y/N>");
		choice = getc(stdin);
		fflush(stdin);

		printf("\n");
	} while (choice != 'n' && choice != 'N');	// �ݺ��� ����

	printf("Thank you !!\n");
}