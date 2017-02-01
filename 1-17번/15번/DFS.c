#include "DFS.h"

void push(int item)
{
	stackNode* ob_Idx = (stackNode *)malloc(sizeof(stackNode));
	ob_Idx->data = item;
	ob_Idx->link = top;
	top = ob_Idx;
}

int pop()
{
	int item;
	stackNode* ob_Idx = top;

	if (top == NULL) {
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {
		item = ob_Idx->data;
		top = ob_Idx->link;
		free(ob_Idx);
		return item;
	}
}
//////// 스택 연산 >>

void createGraph(graphType* g)       //깊이 우선 탐색을 위한 초기 공백 그래프 생성 연산
{
	int v;
	g->n = 0;                      //그래프의 정점 개수를 0으로 초기화
	for (v = 0; v<MAX_VERTEX; v++){
		g->visited[v] = FALSE;        //그래프의 정점에 대한 배열 visited를 FALSE로 초기화
		g->adjList_H[v] = NULL;       //인접 리스트에 대한 헤드 노드 배열을 NULL로 초기화
	}
}

void insertVertex(graphType* g, int v)   //그래프 g에 정점 v를 삽입하는 연산
{
	if (((g->n) + 1)>MAX_VERTEX){
		printf("\n 그래프 정점의 개수를 초과하였습니다!");
		return;
	}
	g->n++;
}

void insertEdge(graphType* g, int u, int v)  //그래프 g에 간선 (u, v)를 삽입하는 연산
{
	graphNode* node;
	if (u >= g->n || v >= g->n) {
		printf("\n 그래프에 없는 정점입니다!");
		return;
	}
	node = (graphNode *)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u];
	g->adjList_H[u] = node;
}

void print_adjList(graphType* g)    //그래프 g에 대한 인접 리스트를 출력하는 연산
{
	int i;
	graphNode* p;
	for (i = 0; i<g->n; i++){
		printf("\n\t\t정점%c의 인접 리스트", i + 65);
		p = g->adjList_H[i];
		while (p){
			printf(" -> %c", p->vertex + 65);
			p = p->link;
		}
	}
}

void DFS_adjList(graphType* g, int v)    //그래프 g에서 정점 v에 대한 깊이 우선 탐색 연산
{

	int idx = 0;
	graphNode* w;
	top = NULL;   // 스택 top 설정
	push(v);
	g->visited[v] = TRUE;
	//printf(" %c", v + 65);
	ob_Idx[idx++] = v;

	while (top != NULL){      //스택이 공백이 아닌 동안 깊이 우선 탐색 반복
		w = g->adjList_H[v];
		while (w){    // 인접정점이 있는 동안 수행
			if (!g->visited[w->vertex]){   //1) 현재 정점 w를 방문하지 않은 경우 
				push(w->vertex);
				g->visited[w->vertex] = TRUE;
				//printf(" %c", w->vertex + 65); // 정점 0~6을 A~G로 바꾸어서 출력
				ob_Idx[idx++] = w->vertex;

				v = w->vertex;
				w = g->adjList_H[v];
			}
			else w = w->link;          //2) 현재 정점 w가 이미 방문한 정점인 경우
		}
		v = pop();     //현재 정점에서 더 이상 순회를 진행할 인접 정점이 없는 경우에 스택 pop !
	}
}
