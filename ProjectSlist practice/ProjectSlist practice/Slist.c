#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

void SLIni(SL** phead)
{
	assert(phead);
	*phead = NULL;
}

void SLPrint(SL* phead)
{
	SL* cur = phead;
	while (cur)//注意此处打印，不需要assert断言，因为空链表也需要打印出一个NULL
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

SL* SLCreateNode(x)
{
	SL* newnode = (SL*)malloc(sizeof(SL));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;
	return newnode;
}

void SLPushBack(SL** phead, SLDataType x)
{
	assert(phead);
	SL* newnode = SLCreateNode(x);
	if (*phead == NULL)
	{
		*phead = newnode;
	}
	else
	{
		SL* tail = *phead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SLPopBack(SL** phead)
{
	assert(phead);
	assert(*phead);
	SL* tail = *phead;
	SL* cur = tail;
	if (cur->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	else
	{
		while (tail->next)
		{
			cur = tail;
			tail = tail->next;
		}
		free(tail);
		cur->next = NULL;
	}
}

void SLPushFront(SL** phead, SLDataType x)
{
	assert(phead);
	SL* newnode = SLCreateNode(x);
	newnode->next = *phead;
	*phead = newnode;
}

void SLPopFront(SL** phead)
{
	assert(phead);
	assert(*phead);
	SL* next = (*phead)->next;
	free(*phead);
	*phead = next;
}

SL* SLFind(SL* phead, SLDataType x)
{
	while (phead)
	{
		if (phead->val == x)
		{
			return phead;
		}
		phead = phead->next;
	}
	return NULL;
}

void SLInsert(SL** phead, SLDataType x, SL* pos)//在pos位置之前插入
{
	assert(pos);
	assert(phead);
	assert(*phead);
	if (*phead == pos)
	{
		SLPushFront(phead, x);
	}
	else
	{
		SL* cur = *phead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		SL* newnode = SLCreateNode(x);
		cur->next = newnode;
		newnode->next = pos;
	}
}

void SLErase(SL** phead, SL* pos)
{
	assert(phead);
	assert(*phead);
	assert(pos);
	if (*phead == pos)
	{
		SLPopFront(phead);
	}
	else
	{
		SL* cur = *phead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SLInsertAfter(SLDataType x, SL* pos)
{
	assert(pos);
	SL* newnode = SLCreateNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLEraseAfter(SL* pos)
{
	assert(pos);
	assert(pos->next);
	SL* tmp = pos->next;
	pos->next = tmp->next;
	free(tmp);
	tmp = NULL;
}

void SLDestroy(SL** phead)
{
	assert(phead);
	SL* cur = *phead;
	while (cur)
	{
		SL* next = cur->next;
		free(cur);
		cur = next;
	}
	*phead = NULL;
}

