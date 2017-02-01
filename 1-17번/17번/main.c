/*
문제 17. 64 게임 구현하기

힌트 및 유의사항
a) 많은 플랫폼으로 구현되어 있는 게임, ‘2048’의 Easy 버전을 구현한다.
b) 기본 구조는 ‘2048’과 완전히 동일하지만 ‘2048’이 아닌 ‘64’를 완성하면 된다.
c) 게임 판은 4*4, 16개의 칸으로 구성되어 있으며 매 판 시작마다 16개의 칸 중에 임의로 한 개의 칸이 선택되어 선택된 칸에 2 또는 4가 랜덤하게 생성된다.
d) 사용자는 소문자 입력을 포함하여 W,A,S,D 키를 눌러 조작할 수 있다. (4가지 키가 아닌 다른 키를 누를 때 게임의 상태는 변하지 않는다.) 또한 각 키는 따로 엔터(개행문자)를 입력받지 않아도 반응해야 한다. (엔터를 꼭 입력해야 되는 경우 오답처리)
e) 매 입력시마다 변경되는 게임 판의 상태를 화면에 반영하기 위해 출력 때 system(“cls”)를 이용하여 매 번 화면을 초기화 한 뒤 게임 판을 출력한다. (화면을 지우지 않고 계속 출력하는 경우 오답처리)
f) 밀어내는 과정에서 병합할 수 있는 숫자가 있다면 모두 병합한다.
* 병합에 대한 자세한 방법은 첨부된 PDF 파일을 참조하세요.
g) 병합 시에는 점수가 발생한다. 얻는 점수는 병합으로 생성된 숫자의 값이다. 2와 2가 병합되어 4가 생성된 경우 플레이어는 4점을 얻는다.
h) 키를 누르는 동작으로 인해 숫자의 위치가 변하거나, 병합이 발생했을 경우에만 비어 있는 칸에 2 또는 4의 숫자가 생성된다. 숫자의 위치도 변하지 않고, 병합이 발생하지 않은 경우에는 숫자가 생성되지 않는다.
i) 숫자 64를 만들어 내면 한 판이 종료된다. 이 점수가 현재까지 진행한 게임의 점수 중 가장 높은 점수인 경우 Best Score에 반영된다.
j) 플레이 중 모든 칸이 가득차고, 병합될 수 없는 숫자가 없으면 한 판이 종료된다.
k) 매 판이 종료될 때마다 ‘게임을 한 번 더 하시겠습니까?’라는 문구를 출력하고 y/n으로 입력을 받는다. 그 외의 입력은 고려하지 않는다.
l) 게임 진행 중 플레이어가 ‘X’를 누른 경우에는 프로그램을 종료한다.
*/
#include <stdio.h> 
#include <windows.h> 
#include <conio.h> 
#include <time.h>

#define ROW 4		// 행 size
#define COLUMN 4	// 열 size
#define LEFT 97		// a(97)   A(65)
#define RIGHT 100	// d(100)  D(68)
#define UP 119		// w(119)  W(87)
#define DOWN 115	// s(115)  S(83)
#define EXIT 120	// x(120)  X(88)

// 콘솔 커서 관련한 win32 api 함수
void setCursor(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void removeCursor(void) {
	CONSOLE_CURSOR_INFO cur;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
	cur.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}

/* 함수 선언부분 */
void Prn_Map();
void Prn_Contents(int(*)[COLUMN]);
void Backup(int(*)[COLUMN], int(*)[COLUMN]);
int push_UP(int(*)[COLUMN]);
int push_DOWN(int(*)[COLUMN]);
int push_RIGHT(int(*)[COLUMN]);
int push_LEFT(int(*)[COLUMN]);
int isFull(int(*)[COLUMN]);
int chk_mvNmerg(int(*)[COLUMN]);
void random_generate(int(*)[COLUMN]);

/* 전역 변수  */
int Best_Score = 0,
Score = 0;

void main()
{
	int contents[ROW][COLUMN],		// 
		backup[ROW][COLUMN],
		row, column,
		kb,
		success,
		choice,
		i, j;

	srand(time(NULL));
	removeCursor();		//커서깜박이지우기 

	// 즉시종료('X') 또는 ('n' or 'N') 입력받을때까지 반복
	do{
		/* 게임 새로 시작시 초기 설정 */
		for (i = 0; i < ROW; i++)
		for (j = 0; j < COLUMN; j++)
			contents[i][j] = 0;		// 2차원 배열 0으로 초기화

		system("cls");	// 화면 지우고 
		Prn_Map();		// 맵(뼈대) 출력

		row = rand() % 4;	// 0~3
		column = rand() % 4;

		contents[row][column] = 2 * (rand() % 2 + 1);
		Prn_Contents(contents);

		setCursor(0, 18);
		printf("BEST : %d\n", Best_Score);
		printf("SCORE : %d\n\n", Score);
		printf("W : 모든 숫자 위로\n");
		printf("A : 모든 숫자 왼쪽으로\n");
		printf("S : 모든 숫자 아래로\n");
		printf("D : 모든 숫자 오른쪽으로\n");
		printf("X : 게임 종료\n");

		success = Score = 0;

		// 64만들기 성공하거나 맵이 꽉차서 더이상 게임진행이 불가능할때까지 반복
		do{
			while (!_kbhit()) // 키 입력 받기 전까지 STOP & WAIT
			{
			}
			kb = _getch();		// 키 입력
			system("cls");
			setCursor(0, 0);
			Prn_Map();

			switch (kb)
			{
			case UP:
				Backup(contents, backup);				// push 직전 내용 저장
				success = push_UP(contents); // PUSH!
				if (chk_mvNmerg(contents, backup) == 1)	// push 직후 내용 비교
					random_generate(contents);	// 숫자 추가
				Prn_Contents(contents);			// 배열 출력
				break;
			case DOWN:
				Backup(contents, backup);
				success = push_DOWN(contents);
				if (chk_mvNmerg(contents, backup) == 1)
					random_generate(contents);
				Prn_Contents(contents);
				break;
			case RIGHT:
				Backup(contents, backup);
				success = push_RIGHT(contents);
				if (chk_mvNmerg(contents, backup) == 1)
					random_generate(contents);
				Prn_Contents(contents);
				break;
			case LEFT:
				Backup(contents, backup);
				success = push_LEFT(contents);
				if (chk_mvNmerg(contents, backup) == 1)
					random_generate(contents);
				Prn_Contents(contents);
				break;
			case EXIT:	// 즉시 종료
				exit(1);
			}
			setCursor(0, 18);
			printf("BEST : %d\n", Best_Score);
			printf("Score : %d\n\n", Score);
			printf("W : 모든 숫자 위로\n");
			printf("A : 모든 숫자 왼쪽으로\n");
			printf("S : 모든 숫자 아래로\n");
			printf("D : 모든 숫자 오른쪽으로\n");
			printf("X : 게임 종료\n");
		} while (success != 1 && success != -1);

		switch (success){
		case 1:	// 성공
			if (Score > Best_Score)
			{
				Best_Score = Score;
				printf("\n%d점으로 BEST Score를 갱신하였습니다!!\n", Score);
			}
			break;
		case -1: // 실패
			printf("\n64를 만들지 못했습니다.\n");
			break;
		}
		printf("\n게임을 한 번 더 하시겠습니까?(y|n) ");
		fflush(stdin);
		scanf_s("%c", &choice);
	} while (choice != 'n' && choice != 'N');

}

/* 함수 정의 부분 */

// 맵(뼈대) 출력
void Prn_Map(){
	int i, j, k;
	for (k = 0; k<4; k++)
	{
		for (i = 0; i<4; i++)
		{
			printf("*");
			printf("---------");
		}
		printf("*\n");
		for (i = 0; i<3; i++)
		{
			for (j = 0; j<4; j++)
				printf("|         ");
			printf("|\n");
		}
	}

	for (i = 0; i<4; i++)
	{
		printf("*");
		printf("---------");
	}
	printf("*\n");
}
// 배열 내용 출력
void Prn_Contents(int(*contents)[COLUMN]){
	int row, column;
	for (row = 0; row < ROW; row++)
	for (column = 0; column < COLUMN; column++)
	if (contents[row][column] != 0)
	{
		// 화면상에서 배열의 인덱스를 기준으로 출력될 위치(X,Y) 계산후 => 커서이동&출력 //
		// X : {5, 15, 25, 35} => 10(n+1)-5	 (n>=0)	
		// Y : {2, 6, 10, 14}  => 4(n+1)-2   (n>=0)
		setCursor(10 * (column + 1) - 5, 4 * (row + 1) - 2);
		printf("%d", contents[row][column]);
	}
}
// chk_mvNmerg()함수 사용 위해..
void Backup(int(*contents)[COLUMN], int(*backup)[COLUMN]){
	int i, j;
	for (i = 0; i < ROW; i++)
	for (j = 0; j < COLUMN; j++)
		backup[i][j] = contents[i][j];
}

// PUSH 알고리즘
// 병합으로 64가 만들어지면		=> return 1
// 더 이상 게임 진행이 불가능하면 => return -1
// 기본 반환 값					=> return 0
int push_UP(int(*contents)[COLUMN]){
	int i, j, k, success = 0;

	for (i = 0; i < COLUMN; i++)
	for (j = 1; j < ROW; j++)
	{
		if (contents[j][i] != 0)
		{
			for (k = j - 1; k >= 0; k--)
			{
				// 이동 가능 => "다음 칸이 비어 있음"
				if (contents[k][i] == 0)
				{
					contents[k][i] = contents[k + 1][i];
					contents[k + 1][i] = 0;
				}
				else
				{
					if (contents[k][i] == contents[k + 1][i])		// 병합
					{
						if ((contents[k][i] *= 2) == 64)
							success = 1;
						contents[k + 1][i] = 0;
						Score += contents[k][i];
					}
					else if (contents[k][i] != contents[k + 1][i])	// 변화X
					{
						if (isFull(contents) == 1)
							success = -1;
					}
				}
			}
		}
	}
	return success;
}
int push_DOWN(int(*contents)[COLUMN]){
	int i, j, k, success = 0;

	for (i = 0; i < COLUMN; i++)
	for (j = ROW - 2; j >= 0; j--)
	{
		if (contents[j][i] != 0)
		{
			for (k = j + 1; k < 4; k++)
			{
				//이동가능
				if (contents[k][i] == 0)
				{
					contents[k][i] = contents[k - 1][i];
					contents[k - 1][i] = 0;
				}
				else
				{
					if (contents[k][i] == contents[k - 1][i])		// 병합
					{
						if ((contents[k][i] *= 2) == 64)
							success = 1;
						contents[k - 1][i] = 0;
						Score += contents[k][i];
					}
					else if (contents[k][i] != contents[k - 1][i])	// 변화X
					{
						if (isFull(contents) == 1)
							success = -1;
					}
				}
			}
		}
	}
	return success;
}
int push_RIGHT(int(*contents)[COLUMN]){
	int i, j, k, success = 0;

	for (i = 0; i < ROW; i++)
	for (j = COLUMN - 2; j >= 0; j--)
	{
		if (contents[i][j] != 0)
		{
			for (k = j + 1; k < 4; k++)
			{
				//이동가능
				if (contents[i][k] == 0)
				{
					contents[i][k] = contents[i][k - 1];
					contents[i][k - 1] = 0;
				}
				else
				{
					if (contents[i][k] == contents[i][k - 1])		// 병합
					{
						if ((contents[i][k] *= 2) == 64)
							success = 1;
						contents[i][k - 1] = 0;
						Score += contents[i][k];
					}
					else if (contents[i][k] != contents[i][k - 1])	// 변화X
					{
						if (isFull(contents) == 1)
							success = -1;
					}
				}
			}
		}
	}
	return success;
}
int push_LEFT(int(*contents)[COLUMN]){
	int i, j, k, success = 0;

	for (i = 0; i < ROW; i++)
	for (j = 1; j < COLUMN; j++)
	{
		if (contents[i][j] != 0)
		{
			for (k = j - 1; k >= 0; k--)
			{
				//이동가능
				if (contents[i][k] == 0)
				{
					contents[i][k] = contents[i][k + 1];
					contents[i][k + 1] = 0;
				}
				else
				{
					if (contents[i][k] == contents[i][k + 1])			// 병합
					{
						if ((contents[i][k] *= 2) == 64)
							success = 1;
						contents[i][k + 1] = 0;
						Score += contents[i][k];
					}
					else if (contents[i][k] != contents[i][k + 1])	// 변화X
					{
						if (isFull(contents) == 1)
							success = -1;
					}
				}
			}
		}
	}
	return success;
}


// 배열이 포화 상태	(0) => return 1
//					(x) => return 0
int isFull(int(*contents)[COLUMN]){
	int i, j;
	for (i = 0; i < ROW; i++)
	for (j = 0; j < COLUMN; j++)
	if (contents[i][j] == 0)
		return 0;
	return 1;
}

// 이동 또는 병합 유		(0) => return 1
//				 무		(x) => return 0
int chk_mvNmerg(int(*contents)[COLUMN], int(*backup)[COLUMN]){
	int i, j;
	for (i = 0; i < ROW; i++)
	for (j = 0; j < COLUMN; j++)
	if (contents[i][j] != backup[i][j])
		return 1;
	return 0;
}

// chk_mvNmerg() -> '참'이면 임의의 빈 공간에 2 또는 4 생성
void random_generate(int(*contents)[COLUMN]){
	int row,
		column;
	do{
		row = rand() % 4;
		column = rand() % 4;
	} while (contents[row][column] != 0);

	contents[row][column] = 2 * (rand() % 2 + 1);
}