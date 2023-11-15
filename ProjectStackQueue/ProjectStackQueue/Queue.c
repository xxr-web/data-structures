#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"

void QIni(q* p)
{
	assert(p);
	p->phead = p->tail = NULL;
	p->size = 0;
}

void QPush(q* p, QDataType x)
{
	assert(p);
	QU* newnode = (QU*)malloc(sizeof(QU));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	newnode->next = NULL;
	newnode->val = x;
	if (p->tail == NULL)
	{
		p->phead = p->tail = newnode;
	}
	else
	{
		p->tail->next = newnode;
		p->tail = newnode;
	}
	p->size++;
}

void QPop(q* p)
{
	assert(p);
	assert(p->phead);
	QU* tmp = p->phead->next;
	free(p->phead);
	p->phead = tmp;
	if (p->phead == NULL)
	{
		p->tail = NULL;
	}
	p->size--;
}

QDataType QFront(q* p)
{
	assert(p);
	assert(p->phead);
	return p->phead->val;
}

QDataType QBack(q* p)
{
	assert(p);
	assert(p->tail);
	return p->tail->val;
}

bool QEmpty(q* p)
{
	assert(p);
	return p->phead == NULL;
}

int QSize(q* p)
{
	assert(p);
	return p->size;
}

void QDestroy(q* p)
{
	assert(p);
	//assert(p->phead);
	QU* tmp = p->phead;
	while (tmp)
	{
		QU* tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	p->phead = p->tail = NULL;
	p->size = 0;
}

