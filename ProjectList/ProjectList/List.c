#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

LT* CreateNode(LTDataType x)
{
	LT* newnode = (LT*)malloc(sizeof(LT));
	if (newnode == NULL)
	{
		printf("malloc");
		exit(-1);
	}
	newnode->x = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
LT* LTIni()
{
	LT* newnode = CreateNode(-1);
	LT* phead = newnode;
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void LTPushBack(LT* phead, LTDataType x)
{
	assert(phead);
	/*LT* tail = phead->prev;
	LT* newnode = CreateNode(x);
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;*/
	LTInsert(x, phead);
}

void LTPopBack(LT* phead)
{
	assert(phead);
	assert(phead->next != phead);
	/*LT* tail = phead->prev;
	LT* newtail = tail->prev;
	newtail->next = phead;
	phead->prev = newtail;
	free(tail);
	tail = NULL;*/
	LTErase1(phead);
	LTErase2(phead->prev);
}

void LTPushFront(LT* phead, LTDataType x)
{
	assert(phead);
	/*LT* newnode = CreateNode(x);
	LT* tmp = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = tmp;
	tmp->prev = newnode;*/
	LTInsert(x, phead->next);
}

void LTPopFront(LT* phead)
{
	assert(phead);
	assert(phead->next != phead);
	/*LT* node = phead->next;
	phead->next = node->next;
	node->next->prev = phead;
	free(node);
	node = NULL;*/
	LTErase1(phead->next);
	LTErase2(phead->next);
}

void LTPrint(LT* phead)
{
	assert(phead);
	LT* cur = phead->next;
	printf("<=>哨兵位<=>");
	while (cur != phead)
	{
		printf("%d<=>", cur->x);
		cur = cur->next;
	}
	printf("\n");
}

LT* LTFind(LT* phead, LTDataType x)
{
	assert(phead);
	LT* cur = phead->next;
	while (cur != phead)
	{
		if (cur->x == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void LTInsert(LTDataType x, LT* pos)//在pos位置前插入一个结点
{
	assert(pos);
	//assert(pos->next != pos);//尾插
	LT* tmp = pos->prev;
	LT* newnode = CreateNode(x);
	tmp->next = newnode;
	newnode->prev = tmp;
	newnode->next = pos;
	pos->prev = newnode;
}

void LTErase1(LT* pos)//删除pos位置前的结点
{
	assert(pos);
	LT* tmp = pos->prev;
	tmp->prev->next = pos;
	pos->prev = tmp->prev;
	free(tmp);
	tmp = NULL;
}

void LTErase2(LT* pos)
{
	assert(pos);
	LT* tmp1 = pos->next;
	LT* tmp2 = pos->prev;
	tmp2->next = tmp1;
	tmp1->prev = tmp2;
	free(pos);
	//pos = NULL;
}

void LTDestroy(LT* phead)
{
	assert(phead);
	LT* cur = phead->next;
	while (cur != phead)
	{
		LT* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	//phead = NULL;//外面自己置空，形参的改变不影响实参。
}