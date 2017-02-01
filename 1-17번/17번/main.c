/*
���� 17. 64 ���� �����ϱ�

��Ʈ �� ���ǻ���
a) ���� �÷������� �����Ǿ� �ִ� ����, ��2048���� Easy ������ �����Ѵ�.
b) �⺻ ������ ��2048���� ������ ���������� ��2048���� �ƴ� ��64���� �ϼ��ϸ� �ȴ�.
c) ���� ���� 4*4, 16���� ĭ���� �����Ǿ� ������ �� �� ���۸��� 16���� ĭ �߿� ���Ƿ� �� ���� ĭ�� ���õǾ� ���õ� ĭ�� 2 �Ǵ� 4�� �����ϰ� �����ȴ�.
d) ����ڴ� �ҹ��� �Է��� �����Ͽ� W,A,S,D Ű�� ���� ������ �� �ִ�. (4���� Ű�� �ƴ� �ٸ� Ű�� ���� �� ������ ���´� ������ �ʴ´�.) ���� �� Ű�� ���� ����(���๮��)�� �Է¹��� �ʾƵ� �����ؾ� �Ѵ�. (���͸� �� �Է��ؾ� �Ǵ� ��� ����ó��)
e) �� �Է½ø��� ����Ǵ� ���� ���� ���¸� ȭ�鿡 �ݿ��ϱ� ���� ��� �� system(��cls��)�� �̿��Ͽ� �� �� ȭ���� �ʱ�ȭ �� �� ���� ���� ����Ѵ�. (ȭ���� ������ �ʰ� ��� ����ϴ� ��� ����ó��)
f) �о�� �������� ������ �� �ִ� ���ڰ� �ִٸ� ��� �����Ѵ�.
* ���տ� ���� �ڼ��� ����� ÷�ε� PDF ������ �����ϼ���.
g) ���� �ÿ��� ������ �߻��Ѵ�. ��� ������ �������� ������ ������ ���̴�. 2�� 2�� ���յǾ� 4�� ������ ��� �÷��̾�� 4���� ��´�.
h) Ű�� ������ �������� ���� ������ ��ġ�� ���ϰų�, ������ �߻����� ��쿡�� ��� �ִ� ĭ�� 2 �Ǵ� 4�� ���ڰ� �����ȴ�. ������ ��ġ�� ������ �ʰ�, ������ �߻����� ���� ��쿡�� ���ڰ� �������� �ʴ´�.
i) ���� 64�� ����� ���� �� ���� ����ȴ�. �� ������ ������� ������ ������ ���� �� ���� ���� ������ ��� Best Score�� �ݿ��ȴ�.
j) �÷��� �� ��� ĭ�� ��������, ���յ� �� ���� ���ڰ� ������ �� ���� ����ȴ�.
k) �� ���� ����� ������ �������� �� �� �� �Ͻðڽ��ϱ�?����� ������ ����ϰ� y/n���� �Է��� �޴´�. �� ���� �Է��� ������� �ʴ´�.
l) ���� ���� �� �÷��̾ ��X���� ���� ��쿡�� ���α׷��� �����Ѵ�.
*/
#include <stdio.h> 
#include <windows.h> 
#include <conio.h> 
#include <time.h>

#define ROW 4		// �� size
#define COLUMN 4	// �� size
#define LEFT 97		// a(97)   A(65)
#define RIGHT 100	// d(100)  D(68)
#define UP 119		// w(119)  W(87)
#define DOWN 115	// s(115)  S(83)
#define EXIT 120	// x(120)  X(88)

// �ܼ� Ŀ�� ������ win32 api �Լ�
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

/* �Լ� ����κ� */
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

/* ���� ����  */
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
	removeCursor();		//Ŀ������������� 

	// �������('X') �Ǵ� ('n' or 'N') �Է¹��������� �ݺ�
	do{
		/* ���� ���� ���۽� �ʱ� ���� */
		for (i = 0; i < ROW; i++)
		for (j = 0; j < COLUMN; j++)
			contents[i][j] = 0;		// 2���� �迭 0���� �ʱ�ȭ

		system("cls");	// ȭ�� ����� 
		Prn_Map();		// ��(����) ���

		row = rand() % 4;	// 0~3
		column = rand() % 4;

		contents[row][column] = 2 * (rand() % 2 + 1);
		Prn_Contents(contents);

		setCursor(0, 18);
		printf("BEST : %d\n", Best_Score);
		printf("SCORE : %d\n\n", Score);
		printf("W : ��� ���� ����\n");
		printf("A : ��� ���� ��������\n");
		printf("S : ��� ���� �Ʒ���\n");
		printf("D : ��� ���� ����������\n");
		printf("X : ���� ����\n");

		success = Score = 0;

		// 64����� �����ϰų� ���� ������ ���̻� ���������� �Ұ����Ҷ����� �ݺ�
		do{
			while (!_kbhit()) // Ű �Է� �ޱ� ������ STOP & WAIT
			{
			}
			kb = _getch();		// Ű �Է�
			system("cls");
			setCursor(0, 0);
			Prn_Map();

			switch (kb)
			{
			case UP:
				Backup(contents, backup);				// push ���� ���� ����
				success = push_UP(contents); // PUSH!
				if (chk_mvNmerg(contents, backup) == 1)	// push ���� ���� ��
					random_generate(contents);	// ���� �߰�
				Prn_Contents(contents);			// �迭 ���
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
			case EXIT:	// ��� ����
				exit(1);
			}
			setCursor(0, 18);
			printf("BEST : %d\n", Best_Score);
			printf("Score : %d\n\n", Score);
			printf("W : ��� ���� ����\n");
			printf("A : ��� ���� ��������\n");
			printf("S : ��� ���� �Ʒ���\n");
			printf("D : ��� ���� ����������\n");
			printf("X : ���� ����\n");
		} while (success != 1 && success != -1);

		switch (success){
		case 1:	// ����
			if (Score > Best_Score)
			{
				Best_Score = Score;
				printf("\n%d������ BEST Score�� �����Ͽ����ϴ�!!\n", Score);
			}
			break;
		case -1: // ����
			printf("\n64�� ������ ���߽��ϴ�.\n");
			break;
		}
		printf("\n������ �� �� �� �Ͻðڽ��ϱ�?(y|n) ");
		fflush(stdin);
		scanf_s("%c", &choice);
	} while (choice != 'n' && choice != 'N');

}

/* �Լ� ���� �κ� */

// ��(����) ���
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
// �迭 ���� ���
void Prn_Contents(int(*contents)[COLUMN]){
	int row, column;
	for (row = 0; row < ROW; row++)
	for (column = 0; column < COLUMN; column++)
	if (contents[row][column] != 0)
	{
		// ȭ��󿡼� �迭�� �ε����� �������� ��µ� ��ġ(X,Y) ����� => Ŀ���̵�&��� //
		// X : {5, 15, 25, 35} => 10(n+1)-5	 (n>=0)	
		// Y : {2, 6, 10, 14}  => 4(n+1)-2   (n>=0)
		setCursor(10 * (column + 1) - 5, 4 * (row + 1) - 2);
		printf("%d", contents[row][column]);
	}
}
// chk_mvNmerg()�Լ� ��� ����..
void Backup(int(*contents)[COLUMN], int(*backup)[COLUMN]){
	int i, j;
	for (i = 0; i < ROW; i++)
	for (j = 0; j < COLUMN; j++)
		backup[i][j] = contents[i][j];
}

// PUSH �˰���
// �������� 64�� ���������		=> return 1
// �� �̻� ���� ������ �Ұ����ϸ� => return -1
// �⺻ ��ȯ ��					=> return 0
int push_UP(int(*contents)[COLUMN]){
	int i, j, k, success = 0;

	for (i = 0; i < COLUMN; i++)
	for (j = 1; j < ROW; j++)
	{
		if (contents[j][i] != 0)
		{
			for (k = j - 1; k >= 0; k--)
			{
				// �̵� ���� => "���� ĭ�� ��� ����"
				if (contents[k][i] == 0)
				{
					contents[k][i] = contents[k + 1][i];
					contents[k + 1][i] = 0;
				}
				else
				{
					if (contents[k][i] == contents[k + 1][i])		// ����
					{
						if ((contents[k][i] *= 2) == 64)
							success = 1;
						contents[k + 1][i] = 0;
						Score += contents[k][i];
					}
					else if (contents[k][i] != contents[k + 1][i])	// ��ȭX
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
				//�̵�����
				if (contents[k][i] == 0)
				{
					contents[k][i] = contents[k - 1][i];
					contents[k - 1][i] = 0;
				}
				else
				{
					if (contents[k][i] == contents[k - 1][i])		// ����
					{
						if ((contents[k][i] *= 2) == 64)
							success = 1;
						contents[k - 1][i] = 0;
						Score += contents[k][i];
					}
					else if (contents[k][i] != contents[k - 1][i])	// ��ȭX
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
				//�̵�����
				if (contents[i][k] == 0)
				{
					contents[i][k] = contents[i][k - 1];
					contents[i][k - 1] = 0;
				}
				else
				{
					if (contents[i][k] == contents[i][k - 1])		// ����
					{
						if ((contents[i][k] *= 2) == 64)
							success = 1;
						contents[i][k - 1] = 0;
						Score += contents[i][k];
					}
					else if (contents[i][k] != contents[i][k - 1])	// ��ȭX
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
				//�̵�����
				if (contents[i][k] == 0)
				{
					contents[i][k] = contents[i][k + 1];
					contents[i][k + 1] = 0;
				}
				else
				{
					if (contents[i][k] == contents[i][k + 1])			// ����
					{
						if ((contents[i][k] *= 2) == 64)
							success = 1;
						contents[i][k + 1] = 0;
						Score += contents[i][k];
					}
					else if (contents[i][k] != contents[i][k + 1])	// ��ȭX
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


// �迭�� ��ȭ ����	(0) => return 1
//					(x) => return 0
int isFull(int(*contents)[COLUMN]){
	int i, j;
	for (i = 0; i < ROW; i++)
	for (j = 0; j < COLUMN; j++)
	if (contents[i][j] == 0)
		return 0;
	return 1;
}

// �̵� �Ǵ� ���� ��		(0) => return 1
//				 ��		(x) => return 0
int chk_mvNmerg(int(*contents)[COLUMN], int(*backup)[COLUMN]){
	int i, j;
	for (i = 0; i < ROW; i++)
	for (j = 0; j < COLUMN; j++)
	if (contents[i][j] != backup[i][j])
		return 1;
	return 0;
}

// chk_mvNmerg() -> '��'�̸� ������ �� ������ 2 �Ǵ� 4 ����
void random_generate(int(*contents)[COLUMN]){
	int row,
		column;
	do{
		row = rand() % 4;
		column = rand() % 4;
	} while (contents[row][column] != 0);

	contents[row][column] = 2 * (rand() % 2 + 1);
}