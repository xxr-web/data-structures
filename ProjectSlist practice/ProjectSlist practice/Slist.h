#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

typedef int SLDataType;

typedef struct SLNode
{
	SLDataType val;
	struct SLNode* next;
}SL;

void SLIni(SL** phead);
void SLPrint(SL* phead);
SL* SLCreateNode(x);
void SLPushBack(SL** phead, SLDataType x);
void SLPopBack(SL** phead);
void SLPushFront(SL** phead, SLDataType x);
void SLPopFront(SL** phead);
SL* SLFind(SL* phead, SLDataType x);
void SLInsert(SL** phead, SLDataType x, SL* pos);
void SLErase(SL** phead, SL* pos);
void SLInsertAfter(SLDataType x, SL* pos);
void SLEraseAfter(SL* pos);
void SLDestroy(SL** phead);
