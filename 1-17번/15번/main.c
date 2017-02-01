/*
문제 15. 팔찌 만들기
힌트 및 유의사항
a) 구슬을 이용하여 팔찌를 만들려고 한다. 한 구슬에는 두 가지 색이 들어갈 수 있다.
b) 색의 종류는 a,b,c, … , z 까지 26개가 있다고 가정한다. 주머니에서 랜덤으로 구슬를 꺼내어 팔찌를 만든다.
c) 팔찌를 만들 때 무조건 구슬과 구슬이 접하는 부분의 색은 서로 같도록 구슬을 이어 팔찌를 만든다. 또한 첫 구슬과 마지막 구슬을 마지막에 이을 때도 닿는 부분의 색은 같도록 한다. (아래 그림 참조)
d) 구슬은 둥글기 때문에 입력한 색 순을 바꿔서 이을 수 있으며, 중복 색도 허락된다. 또한 한 구슬에 같은 색이 두 개 들어간 구슬도 존재한다.
e) 만약 팔찌 만들기 규칙에 어긋나는 팔찌를 만들면 Fail 메세지를 띄운다.
f) 팔찌가 만들어지고 나면, 'One More?' 메세지를 띄우고 y/n로 값을 받아 y를 누른 경우 다시 팔찌를 만들도록 한다.
g) 모든 구슬은 다 사용해야하고, 결과예시는 한가지 경우만 보여주면 된다.
예시)
자신이 생각하는 구슬의 개수(N)를 먼저 입력하고 (5<N<100), 뽑은 구슬의 색을 하나씩 입력한다.
예1)
구슬의 개수 입력: 5
구슬 색 입력(2개씩 입력)
b c
c d
d a
a b
d b
팔찌 결과:  (b c) – (c d) - (d a) – (a b) (d b)
*/

#include <stdio.h>
#include <malloc.h>
#include "DFS.h"

/* DFS(깊이 우선 탐색)한 순서대로 정렬된 구슬들의 INDEX */
extern int * ob_Idx;	//	[Ordered Bead]_Index 

typedef struct Bead{
	char C1;	// Color1
	char C2;	// Color2
}BEAD;

typedef struct Bracelet{
	BEAD * pBead;
}BRACELET;

int Rull_checking(BRACELET *, int);	// 팔찌 규칙 검사
int cmpToRight(BRACELET *, int);	// Compare To the Right Bead
void prnBracelet(BRACELET *, int);	// 팔찌 출력

void main()
{
	graphType *G9;	// 그래프
	BRACELET Br;	// (공백) 팔찌 생성
	int num,		// 사용자 입력 (구슬 개수)
		i, j;		// 제어 변수;
	char choice;	// 사용자 입력 (추가 진행 여부 'y/n')

	do{
		printf("Insert the number of bead you're gonna choose<5~100>: ");
		scanf_s("%d", &num);

		// 입력받은 num개 만큼 공간 할당
		Br.pBead = (BEAD *)malloc(sizeof(BEAD)* num);
		ob_Idx = (int *)malloc(sizeof(int)* num);

		printf("Insert tow colors of each bead <%d>\n", num);
		for (i = 0; i < num; i++)
		{
			printf("=> %d. : ", i+1);
			fflush(stdin);
			scanf_s("%c %c", &(Br.pBead)[i].C1, 1,
				&(Br.pBead)[i].C2, 1);
		}

		printf("\nThis is YOUR BEADS you picked.\n");
		for (i = 0; i < num; i++)
			printf("[%c, %c] ", (Br.pBead)[i].C1, (Br.pBead)[i].C2);
		printf("\n");

		G9 = (graphType *)malloc(sizeof(graphType));
		// 공백 그래프 생성 후
		createGraph(G9);

		// 입력받은 num개만큼 정점 삽입 후
		for (i = 0; i < num; i++)        //그래프 G9 구성
			insertVertex(G9, i);

		// 정점간에 연결성이 존재하면 간선을 삽입해준다.
		for (i = 0; i < num; i++)
		for (j = i + 1; j < num; j++)
		{
			if ((Br.pBead)[i].C1 == (Br.pBead)[j].C1 ||
				(Br.pBead)[i].C1 == (Br.pBead)[j].C2)
			{
				insertEdge(G9, i, j);
				insertEdge(G9, j, i);
			}
			if ((Br.pBead)[i].C2 == (Br.pBead)[j].C1 ||
				(Br.pBead)[i].C2 == (Br.pBead)[j].C2)
			{
				insertEdge(G9, i, j);
				insertEdge(G9, j, i);
			}
		}

		//printf("\n G9의 인접 리스트 ");
		//print_adjList(G9);

		//printf("\n\n///////////////\n\n깊이 우선 탐색 >> ");
		DFS_adjList(G9, 0);     //0번 정점인 정점 A에서 깊이 우선 탐색 시작


		// 팔찌 규칙 검사
		switch (Rull_checking(&Br, num))
		{
		case 0:
			printf("\nIt's IMPOSSIBLE to make complete Bracelet!!\n");
			break;
		case 1:
			printf("\nIt's Possible to make complete Bracelet as follows!!\n");
			prnBracelet(&Br, num);
			break;
		}

		printf("\nOne MORE?? ;->  :  ");
		fflush(stdin);
		scanf_s("%c", &choice);
		printf("\n================================================\n\n");
	} while (choice != 'n' && choice != 'N');


	// 동적 할당 받았던 공간 해제
	free(G9);
	free(Br.pBead);
	free(ob_Idx);
}

/*
팔찌 생성 규칙에 부합하는지 검사하는 알고리즘
규칙 통과(o) => return 1
규칙 통과(x) => return 0
*/
int Rull_checking(BRACELET * Br, int num){
	char tmp;	// 구슬의 색 순서 바꾸기 위한 임시 저장 공간

	// ##가정## : "첫번째 구슬의 색 순서가 맞다!!"
	if (!cmpToRight(Br, num))
	{

		// 가정이 틀림 => 첫번째 구슬의 색 순서 바꿔주고
		tmp = (Br->pBead)[ob_Idx[0]].C1;
		(Br->pBead)[ob_Idx[0]].C1 = (Br->pBead)[ob_Idx[0]].C2;
		(Br->pBead)[ob_Idx[0]].C2 = tmp;

		// 다시~.
		if (!cmpToRight(Br, num))
			return 0;
	}
	return 1;
}

/*
오른쪽에 위치한 구슬과 연결이 가능한지 차례차례 검사한후
가능		=>	return 1
불가능	=>	return 0
*/
int cmpToRight(BRACELET * Br, int num){
	int i, j;	// 제어 변수
	char tmp;	// 구슬의 색 순서 바꾸기 위한 임시 저장 공간

	for (i = 0; i < num - 1; i++)
	{
		j = i + 1;
		// 짝이 안맞으면
		if ((Br->pBead)[ob_Idx[i]].C2 != (Br->pBead)[ob_Idx[j]].C1)
		{
			// 오른쪽 구슬이 가지고 있는 다른 색과도 비교후에도 다르면 [꽝!!]
			if ((Br->pBead)[ob_Idx[i]].C2 != (Br->pBead)[ob_Idx[j]].C2)
				return 0;
			else
			{
				// 같으면 오른쪽 구슬 색 순서 바꾸기
				tmp = (Br->pBead)[ob_Idx[j]].C1;
				(Br->pBead)[ob_Idx[j]].C1 = (Br->pBead)[ob_Idx[j]].C2;
				(Br->pBead)[ob_Idx[j]].C2 = tmp;
			}
		}
	}
	// 마지막으로 처음과 끝이 연결 되는지 검사
	if ((Br->pBead)[ob_Idx[num - 1]].C2 != (Br->pBead)[ob_Idx[0]].C1)
		return 0;

	return 1;
}

/* 연결된 팔찌 출력 */
void prnBracelet(BRACELET * Br, int num){
	int i;
	printf("\n");
	printf("[%c, %c]", (Br->pBead)[ob_Idx[0]].C1, (Br->pBead)[ob_Idx[0]].C2);
	for (i = 1; i < num; i++)
		printf("-[%c, %c]", (Br->pBead)[ob_Idx[i]].C1, (Br->pBead)[ob_Idx[i]].C2);
	printf("\n");
}