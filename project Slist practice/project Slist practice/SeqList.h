#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

typedef int SeQDataType;
typedef struct SeqListNode
{
	SeQDataType* psl;
	int size;
	int capacity;
}SqL;

void SqLIni(SqL* p);
void SqLPushBack(SqL* p, SeQDataType x);
void SqLCreate(SqL* p);
void SqLPrint(SqL* p);
void SqLPopBack(SqL* p);
void SqLPushFront(SqL* p, SeQDataType x);
void SqLPopFront(SqL* p);
int SqLFind(SqL* p, SeQDataType x);
void SqLInsert(SqL* p, int pos, SeQDataType x);
void SqLDelete(SqL* p, int pos);
void SqLDestroy(SqL* p);
