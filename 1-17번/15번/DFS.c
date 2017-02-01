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
//////// ���� ���� >>

void createGraph(graphType* g)       //���� �켱 Ž���� ���� �ʱ� ���� �׷��� ���� ����
{
	int v;
	g->n = 0;                      //�׷����� ���� ������ 0���� �ʱ�ȭ
	for (v = 0; v<MAX_VERTEX; v++){
		g->visited[v] = FALSE;        //�׷����� ������ ���� �迭 visited�� FALSE�� �ʱ�ȭ
		g->adjList_H[v] = NULL;       //���� ����Ʈ�� ���� ��� ��� �迭�� NULL�� �ʱ�ȭ
	}
}

void insertVertex(graphType* g, int v)   //�׷��� g�� ���� v�� �����ϴ� ����
{
	if (((g->n) + 1)>MAX_VERTEX){
		printf("\n �׷��� ������ ������ �ʰ��Ͽ����ϴ�!");
		return;
	}
	g->n++;
}

void insertEdge(graphType* g, int u, int v)  //�׷��� g�� ���� (u, v)�� �����ϴ� ����
{
	graphNode* node;
	if (u >= g->n || v >= g->n) {
		printf("\n �׷����� ���� �����Դϴ�!");
		return;
	}
	node = (graphNode *)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u];
	g->adjList_H[u] = node;
}

void print_adjList(graphType* g)    //�׷��� g�� ���� ���� ����Ʈ�� ����ϴ� ����
{
	int i;
	graphNode* p;
	for (i = 0; i<g->n; i++){
		printf("\n\t\t����%c�� ���� ����Ʈ", i + 65);
		p = g->adjList_H[i];
		while (p){
			printf(" -> %c", p->vertex + 65);
			p = p->link;
		}
	}
}

void DFS_adjList(graphType* g, int v)    //�׷��� g���� ���� v�� ���� ���� �켱 Ž�� ����
{

	int idx = 0;
	graphNode* w;
	top = NULL;   // ���� top ����
	push(v);
	g->visited[v] = TRUE;
	//printf(" %c", v + 65);
	ob_Idx[idx++] = v;

	while (top != NULL){      //������ ������ �ƴ� ���� ���� �켱 Ž�� �ݺ�
		w = g->adjList_H[v];
		while (w){    // ���������� �ִ� ���� ����
			if (!g->visited[w->vertex]){   //1) ���� ���� w�� �湮���� ���� ��� 
				push(w->vertex);
				g->visited[w->vertex] = TRUE;
				//printf(" %c", w->vertex + 65); // ���� 0~6�� A~G�� �ٲپ ���
				ob_Idx[idx++] = w->vertex;

				v = w->vertex;
				w = g->adjList_H[v];
			}
			else w = w->link;          //2) ���� ���� w�� �̹� �湮�� ������ ���
		}
		v = pop();     //���� �������� �� �̻� ��ȸ�� ������ ���� ������ ���� ��쿡 ���� pop !
	}
}
