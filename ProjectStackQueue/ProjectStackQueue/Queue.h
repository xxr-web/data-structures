#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <assert.h>

typedef int QDataType;
typedef struct Queue
{
	struct Queue* next;
	QDataType val;
}QU;

typedef struct qunode
{
	QU* phead;
	QU* tail;
	int size;
}q;

void QIni(q* p);
void QDestroy(q* p);
void QPush(q* p, QDataType x);//入队列是需要从队尾入的，所以我们不妨设计一个结构体可以除了有头指针之外，再包含一个尾指针。
void QPop(q* p);
QDataType QFront(q* p);
QDataType QBack(q* p);
bool QEmpty(q* p);
int QSize(q* p);//因为不是顺序表，所以再算一遍size的长度就会比较麻烦，所以直接也把size放进指针里。