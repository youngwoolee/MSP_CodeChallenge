/*
문제7. 겹치는 공강 찾기.

힌트 및 요구사항

a. 파일입출력으로 풀어야 하며, 2개의 시간표 파일이 필요하다.
b. 시간표 파일(.txt)의 양식은 문제와 함께 제시한 예시 파일을 참고하면 된다.
c. 출력에서 화면과 같이 2개의 시간표 파일로부터 시간표를 읽어와 출력한 뒤, 겹치는 공강을 출력해주면 된다.
*/
#include <stdio.h>
#include <string.h>
enum DAY { MON = 1, TUE, WED, THU, FRI };
void main()
{
	enum DAY Day; /* 요일에 대한 enum 변수 */

	FILE * fp_my, /* mytime.txt 대한 파일 구조체 포인터 */
		*fp_fr; /* friendtime.txt 대한 파일 구조체 포인터 */

	int i, j; /* 제어 변수 */
	long cur_pos_periodMY[7], /* mytime.txt 파일의 각 라인별 시작 위치에 대한 offset */
		cur_pos_periodFR[7]; /* friendtime.txt 파일의 각 라인별 시작 위치에 대한 offset */

	char str_bufMY[2], /* mytime.txt 파일에서 문자열 단위로 읽을때 쓰는 버퍼 */
		str_bufFR[2], /* friendtime.txt 파일에서 문자열 단위로 읽을때 쓰는 버퍼 */
		line_buf[100]; /* 파일에서 한줄단위로 읽을때 쓰는 버퍼  */


	fopen_s(&fp_my,"mytime.txt", "r");
	fopen_s(&fp_fr,"friendtime.txt", "r");


	printf(" [ 겹치는 공강 찾아주는 프로그램 ]\n");
	printf(" cf) 공강은 \"-\"로 수업은 \"o\"으로 표시 됩니다!\n");

	printf(" < My TimeTable > \n");
	// mytime.txt 내용 출력
	for (i = 0; !feof(fp_my); i++)
	{
		cur_pos_periodMY[i] = ftell(fp_my); // 라인별 시작위치 저장
		fgets(line_buf, 255, fp_my);		// 한줄 읽어서 버퍼에 담고
		fputs(line_buf, stdout);			// 버퍼 내용을 출력
	}
	fseek(fp_my, 0, SEEK_SET);				// 출력 끝나면 파일 시작위치로 재 설정

	printf("\n < Friend's TimeTable > \n");
	// friendtime.txt 출력
	for (i = 0; !feof(fp_fr); i++)
	{
		cur_pos_periodFR[i] = ftell(fp_fr);
		fgets(line_buf, 255, fp_fr);
		fputs(line_buf, stdout);
	}
	fseek(fp_fr, 0, SEEK_SET);



	printf("\n\n < 겹치는 공강 > \n");
	// 월요일~금요일 각 요일별로
	for (Day = MON; Day <= FRI; Day++)
	{
		// 1교시~6교시 중에 겹치는 공강 찾기
		for (i = 1; i <= 6; i++)
		{
			// 저장해둔 위치로 이동
			fseek(fp_my, cur_pos_periodMY[i], SEEK_SET);
			fseek(fp_fr, cur_pos_periodFR[i], SEEK_SET);

			// 해당 요일에 대한 열(Column)값만 읽기 위해 왼쪽 필드 무시
			for (j = 1; j <= Day; j++)
			{
				fscanf(fp_my, "%*s");
				fscanf(fp_fr, "%*s");
			}

			fscanf(fp_my, "%s", str_bufMY);	// 내 시간표 먼저 읽고
			if (strcmp(str_bufMY, "-") == 0)	// 공강이면
			{
				fscanf(fp_fr, "%s", str_bufFR);		// 친구 시간표 읽어서
				if (strcmp(str_bufMY, str_bufFR) == 0) // 친구도 공강인지 check
					switch (Day)
				{
					case MON:
						printf("월요일 : %d교시\n", i);
						break;
					case TUE:
						printf("화요일 : %d교시\n", i);
						break;
					case WED:
						printf("수요일 : %d교시\n", i);
						break;
					case THU:
						printf("목요일 : %d교시\n", i);
						break;
					case FRI:
						printf("금요일 : %d교시\n", i);
						break;
				}
			}
		}
	}


	fclose(fp_my);
	fclose(fp_fr);
}