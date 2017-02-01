#ifndef DFS
#define DFS

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define MAX_VERTEX 10
#define FALSE 0
#define TRUE 1

int * ob_Idx;

typedef struct graphNode{    //그래프에 대한 인접 리스트의 노드 구조 정의
	int vertex;
	struct graphNode* link;
} graphNode;

typedef struct graphType{
	int n;                   //정점의 갯수
	graphNode* adjList_H[MAX_VERTEX];   //정점에 대한 인접 리스트의 헤드 노드 배열
	int visited[MAX_VERTEX];              //정점에 대한 방문 표시를 위한 배열
}graphType;

//////// << 스택 연산
typedef struct stackNode {
	int data;
	struct stackNode *link;
}stackNode;

stackNode* top;

void push(int);

int pop();

void createGraph(graphType*);       //깊이 우선 탐색을 위한 초기 공백 그래프 생성 연산

void insertVertex(graphType*, int);   //그래프 g에 정점 v를 삽입하는 연산


void insertEdge(graphType*, int, int);  //그래프 g에 간선 (u, v)를 삽입하는 연산

void print_adjList(graphType*);    //그래프 g에 대한 인접 리스트를 출력하는 연산

void DFS_adjList(graphType*, int);    //그래프 g에서 정점 v에 대한 깊이 우선 탐색 연산

#endif
