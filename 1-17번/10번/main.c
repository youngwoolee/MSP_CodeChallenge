/*
���� 10. �뷡�� ���α׷�
��Ʈ �� �䱸����
a. txt ���Ͽ� [��ȣ / �����̸�-�뷡���� / �뷡 ���� �� ��]�� �����͸� �����Ѵ�.
b. ù ȭ�鿡�� [��ȣ / �����̸� - �뷡 ����] �� ����Ѵ�.
c. ����ڰ� ���ϴ� �뷡�� ��ȣ�� �Է��Ѵ�.
d. �Է� ���� ��ȣ�� ���� �뷡 ���� �� ���� ���� ������� ���� ����Ѵ�.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int searchIdx(FILE *, char);
void prnContent(FILE *);
void main()
{
	FILE * fp;			// ���� ����ü ������
	char buf[100];		// ���Ͽ��� ���δ����� ������ �̿��� ����
	int index;			// �뷡 ��ȣ
	char choice = '\0';	// ����ڰ� ������ �뷡 ��ȣ
	char * context;

	if (fopen_s(&fp, "code challenge 2014 10�� ���� ��������� txt.txt", "r") != 0)
	{
		printf("error : ������ �����ϴ�!\n");
		return;
	}

	printf("\tMSP�뷡�濡 ���Ű��� ȯ���մϴ�!\n\n\
		   	��ȣ\t ����  -  �뷡����\n\
				--------------------------------------\n");
	// ��ȣ,����,�뷡���� (TAB ���� ����) ���
	while (!feof(fp))
	{
		if (fscanf_s(fp, "%d", &index) == -1) // ������ ���� �ƴϴ��� �Է¹����� ������ ��� ����
			break;
		printf("\t%d", index);
		fgets(buf, 100, fp);
		strtok_s(buf, "\t", &context);
		printf("\t%s\n", buf);
	}

	rewind(fp);	// ���� �����͸� ������ ������ġ�� ����

	// ����ڰ� ������ �뷡��ȣ�� �뷡 ���� �κ��� ����Ѵ�.
	while (choice != '0')
	{
		printf("\n\t�뷡 ��ȣ�� �Է����ּ���.\n\
			   	<0�� ������ �뷡�� ���α׷��� ����˴ϴ�.> : ");
		fflush(stdin);
		scanf_s("%c", &choice);

		printf("\n");
		switch (choice)
		{
		case '0':
			printf("\n");
			break;
		case '1':
			searchIdx(fp, choice);
			prnContent(fp);
			break;
		case '2':
			searchIdx(fp, choice);
			prnContent(fp);
			break;
		case '3':
			searchIdx(fp, choice);
			prnContent(fp);
			break;
		case '4':
			searchIdx(fp, choice);
			prnContent(fp);
			break;
		case '5':
			searchIdx(fp, choice);
			prnContent(fp);
			break;
		default:
			printf("\t**��ȣ�� �߸� �ԷµǾ����ϴ�.**\n");
		}
	}
	fclose(fp);
}

// ���Ͽ��� ������ �뷡��ȣ�� �ִ� �ٷ� ���� �����͸� �̵��Ѵ�.
int searchIdx(FILE * fp, char choice)
{
	int index;
	while (fscanf_s(fp, "%d", &index) != -1)
	{
		if (index == atoi(&choice))
			return 1;	// ���� (�ǹ�X)
		fgets(NULL, 0, fp);
	}
	return -1;			// ���� (�ǹ�X)
}

// ���� �κ�(TAB���� ������) ����Ѵ�.
void prnContent(FILE * fp)
{
	char buf[100];
	char * context;
	fgets(buf, 100, fp);
	strtok_s(buf, "\t", &context);
	printf("\t%s", context);
}