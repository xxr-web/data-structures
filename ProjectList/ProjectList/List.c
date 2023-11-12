#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

LTNode* CreateNode(ListDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

LTNode* LTIni()
{
	LTNode* phead = CreateNode(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void LTPrint(LTNode* phead)
{
	assert(phead);
	printf("ÉÚ±øÎ»<=>");
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=>", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

void LTPushback(LTNode* phead, ListDataType x)
{
	assert(phead);
	LTNode* tail = phead->prev;
	LTNode* newnode = CreateNode(x);
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

void LTPopback(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* tail = phead->prev;
	LTNode* newtail = tail->prev;
	phead->prev = newtail;
	newtail->next = phead;
	free(tail);
	tail = NULL;
}
