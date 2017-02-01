#include <stdio.h> 

void main()
{
	char str[30];
	int i;
	printf("문자열을 입력하세요:");
	gets_s(str, 30);

	for (i = 0; i < 30; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 'a' - 'A';
	}

	printf("바뀐 문자열:%s\n", &str);
}
