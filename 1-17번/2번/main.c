#include <stdio.h> 

void main()
{
	char str[30];
	int i;
	printf("���ڿ��� �Է��ϼ���:");
	gets_s(str, 30);

	for (i = 0; i < 30; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 'a' - 'A';
	}

	printf("�ٲ� ���ڿ�:%s\n", &str);
}
