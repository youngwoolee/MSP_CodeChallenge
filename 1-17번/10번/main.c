/*
문제 10. 노래방 프로그램
힌트 및 요구사항
a. txt 파일에 [번호 / 가수이름-노래제목 / 노래 가사 한 줄]의 데이터를 저장한다.
b. 첫 화면에서 [번호 / 가수이름 - 노래 제목] 을 출력한다.
c. 사용자가 원하는 노래의 번호를 입력한다.
d. 입력 받은 번호에 대한 노래 가사 한 줄을 파일 입출력을 통해 출력한다.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int searchIdx(FILE *, char);
void prnContent(FILE *);
void main()
{
	FILE * fp;			// 파일 구조체 포인터
	char buf[100];		// 파일에서 라인단위로 읽을때 이용할 버퍼
	int index;			// 노래 번호
	char choice = '\0';	// 사용자가 선택한 노래 번호
	char * context;

	if (fopen_s(&fp, "code challenge 2014 10번 문제 파일입출력 txt.txt", "r") != 0)
	{
		printf("error : 파일이 없습니다!\n");
		return;
	}

	printf("\tMSP노래방에 오신것을 환영합니다!\n\n\
		   	번호\t 가수  -  노래제목\n\
				--------------------------------------\n");
	// 번호,가수,노래제목 (TAB 기준 왼쪽) 출력
	while (!feof(fp))
	{
		if (fscanf_s(fp, "%d", &index) == -1) // 파일의 끝이 아니더라도 입력받은게 없으면 출력 중지
			break;
		printf("\t%d", index);
		fgets(buf, 100, fp);
		strtok_s(buf, "\t", &context);
		printf("\t%s\n", buf);
	}

	rewind(fp);	// 파일 포인터를 파일의 시작위치로 복귀

	// 사용자가 선택한 노래번호의 노래 가사 부분을 출력한다.
	while (choice != '0')
	{
		printf("\n\t노래 번호를 입력해주세요.\n\
			   	<0을 누르면 노래방 프로그램이 종료됩니다.> : ");
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
			printf("\t**번호가 잘못 입력되었습니다.**\n");
		}
	}
	fclose(fp);
}

// 파일에서 선택한 노래번호가 있는 줄로 파일 포인터를 이동한다.
int searchIdx(FILE * fp, char choice)
{
	int index;
	while (fscanf_s(fp, "%d", &index) != -1)
	{
		if (index == atoi(&choice))
			return 1;	// 성공 (의미X)
		fgets(NULL, 0, fp);
	}
	return -1;			// 실패 (의미X)
}

// 가사 부분(TAB기준 오른쪽) 출력한다.
void prnContent(FILE * fp)
{
	char buf[100];
	char * context;
	fgets(buf, 100, fp);
	strtok_s(buf, "\t", &context);
	printf("\t%s", context);
}