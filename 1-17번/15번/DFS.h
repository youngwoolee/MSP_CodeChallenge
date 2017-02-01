#ifndef DFS
#define DFS

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define MAX_VERTEX 10
#define FALSE 0
#define TRUE 1

int * ob_Idx;

typedef struct graphNode{    //�׷����� ���� ���� ����Ʈ�� ��� ���� ����
	int vertex;
	struct graphNode* link;
} graphNode;

typedef struct graphType{
	int n;                   //������ ����
	graphNode* adjList_H[MAX_VERTEX];   //������ ���� ���� ����Ʈ�� ��� ��� �迭
	int visited[MAX_VERTEX];              //������ ���� �湮 ǥ�ø� ���� �迭
}graphType;

//////// << ���� ����
typedef struct stackNode {
	int data;
	struct stackNode *link;
}stackNode;

stackNode* top;

void push(int);

int pop();

void createGraph(graphType*);       //���� �켱 Ž���� ���� �ʱ� ���� �׷��� ���� ����

void insertVertex(graphType*, int);   //�׷��� g�� ���� v�� �����ϴ� ����


void insertEdge(graphType*, int, int);  //�׷��� g�� ���� (u, v)�� �����ϴ� ����

void print_adjList(graphType*);    //�׷��� g�� ���� ���� ����Ʈ�� ����ϴ� ����

void DFS_adjList(graphType*, int);    //�׷��� g���� ���� v�� ���� ���� �켱 Ž�� ����

#endif
