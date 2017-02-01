#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;    //char을 스택 element의 자료형으로 정의

typedef struct stackNode {
	element data;
	struct stackNode *link;
}stackNode;

stackNode* top;

void push(element item)     //연결리스트 스택의 삽입 연산
{
	stackNode* temp = (stackNode *)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

element pop()              //연결리스트 스택의 삭제 후 반환 연산
{
	element item;
	stackNode* temp = top;

	if (top == NULL) {
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

/* 쌍이 맞는 괄호 판별 연산 */
int testPair(char *exp)
{
	char symbol, open_pair;
	int i, length = strlen(exp);
	top = NULL;

	for (i = 0; i<length; i++)
	{
		symbol = exp[i];
		switch (symbol)
		{
		case '(':
			push(symbol);
			break;
		case ')':
			if (top == NULL)
				return 0;
			else
			{
				open_pair = pop();
				if (open_pair == '(' && symbol != ')')
					return 0;
				else
					break;
			}
		}
	}
	if (top == NULL)
		return 1;
	else
		return 0;
}

void main(void)
{
	char express[80];

	printf("코드 한 줄(80자 이내)을 입력해주세요.\n");
	gets_s(express, 80);

	if (testPair(express) == 1)
		printf("YES");
	else
		printf("NO");

	getchar();
}