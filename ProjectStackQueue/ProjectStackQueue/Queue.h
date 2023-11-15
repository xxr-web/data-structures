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
void QPush(q* p, QDataType x);//���������Ҫ�Ӷ�β��ģ��������ǲ������һ���ṹ����Գ�����ͷָ��֮�⣬�ٰ���һ��βָ�롣
void QPop(q* p);
QDataType QFront(q* p);
QDataType QBack(q* p);
bool QEmpty(q* p);
int QSize(q* p);//��Ϊ����˳�����������һ��size�ĳ��Ⱦͻ�Ƚ��鷳������ֱ��Ҳ��size�Ž�ָ���