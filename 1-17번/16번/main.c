/*
문제 16. 볼링 스코어 계산하기
힌트 및 유의사항
a) 볼링 경기는 총 10개의 핀을 사용한다. 볼링 한 경기는 10개의 프레임으로 이루어진다. 그리고 경기 점수는 매 프레임의 점수를 합산한 것이다.
b) 마지막 프레임을 제외하면 각 프레임마다 최대 2회까지 투구를 할 수 있는데, 스트라이크인 경우에는 1회만 투구한다.
c) 첫 회에 스트라이크를 하지 못한 경우에는 한 번 더 투구를 할 기회가 있는데, 두 번째 투구에서 나머지 핀을 모두 쓰러뜨리면 스페어라 하고 그렇지 못한 경우를 미스라고 한다.
d) 경기는 총 10 프레임으로 진행되고, 경기가 모두 끝나고 나면 각 프레임별 점수를 합산한다.
* 프레임별 점수 계산 방법은 첨부된 PDF 파일을 참조하세요.
문제 예시 )
5       //총 5가지 경우
18      //18번동안 쓰러뜨린 핀수
5 5 8 0 10 7 2 10 10 7 3 9 1 9 1 10 5 5
12      //12번동안 쓰러트린 핀수
10 10 10 10 10 10 10 10 10 10 10 10
11      //11번동안 쓰러트린 핀수
10 10 10 10 10 10 10 10 10 9 0
12      //12번동안 쓰러트린 핀수
10 10 10 10 10 10 10 10 10 0 10 8
12      //12번동안 쓰러트린 핀수
8 8 10 10 10 10 10 10 10 10 10 10
*/
#include <stdio.h>
#include <malloc.h>
void main()
{
	FILE * fp;		// input.txt에 관한 파일 구조체 포인터
	int game_num,	// 입력받은 게임 횟수(input.txt 파일 첫행)
		try_num,	// 한 게임당(10프레임) 시도한 횟수
		game_idx,	// 각 게임에 대한 index
		frame_idx,	// 각 프레임에 대한 index
		*score,	// 각 게임당 'try_num'개 만큼 저장된 점수들의 집합
		** frame_score,	// score 배열을 프레임별로 계산한 점수들의 집합
		sum = 0,	// 각 게임당 총점
		i, j;		// 제어 변수

	// 파일 오픈
	if (fopen_s(&fp, "input.txt", "r") != 0){
		printf("file open error!!\n");
		return;
	}

	// 첫 행에서 게임 횟수 읽어옴
	fscanf_s(fp, "%d", &game_num);

	// 이차원배열에 대한 동적할당 (int형 * 게임횟수 * 프레임수)
	frame_score = (int **)malloc(sizeof(int *)*game_num);
	for (i = 0; i < game_num; i++)
		frame_score[i] = (int *)malloc(sizeof(int)* 10);

	// 이차원 배열 초기화
	/*for (i = 0; i < game_num; i++)
	for (j = 0; j < 10; j++)
	frame_score[i][j] = 0;*/

	// 파일에 입력된 내용을 읽어와 각 게임별 총점을 계산한다.
	for (game_idx = frame_idx = 0; game_idx < game_num; game_idx++)
	{
		fscanf_s(fp, "%d", &try_num);				// 한 경기에서 투구한 횟수 읽어와서
		score = (int *)malloc(sizeof(int)*try_num);	// 그 크기 만큼의 공간을 동적할당 후
		for (i = 0; i < try_num; i++)				// 그 공간에 각 투구별 점수를 저장해 놓는다.
			fscanf_s(fp, "%d", &score[i]);
		/* 파일에서 점수를 읽어와 배열에 저장한 이유 : 배열의 index를 이용해 순회를 편하게 하려고... */

		// 스트라이크, 스패어, 미스 일때의 프레임별 점수 계산법
		for (i = 0; i < try_num && frame_idx < 10;)
		{
			// 스트라이크
			if (score[i] == 10){
				frame_score[game_idx][frame_idx++] = score[i] + score[i + 1] + score[i + 2];
				i += 1;
			}
			else if (score[i] < 10)
			{
				// 스패어
				if (score[i] + score[i + 1] == 10){
					frame_score[game_idx][frame_idx++] = score[i] + score[i + 1] + score[i + 2];
					i += 2;
				}
				// 미스
				else if (score[i] + score[i + 1] < 10){
					frame_score[game_idx][frame_idx++] = score[i] + score[i + 1];
					i += 2;
				}
				// 에러
				else if (score[i] + score[i + 1] > 10) { sum = -1;	break; }
			}
			else { sum = -1;	break; }
		}// End of (Inner) for

		if (sum != -1)
		{
			// 각 게임 회차별 총점 구하기
			for (j = 0; j < 10; j++)
				sum += frame_score[game_idx][j];
			printf("%d\n", sum);
		}
		else
			printf("error\n");

		// 동적할당 해제
		free(score);
		// 재사용될 변수 초기화
		frame_idx = sum = 0;
	}// End of (Outer) for


	// 동적할당 해제
	for (i = 0; i < game_num; i++)
		free(frame_score[i]);
	free(frame_score);

	// 파일 닫기
	fclose(fp);
}