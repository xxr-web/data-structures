#pragma once

//Single List
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

typedef int SLNDataType;

typedef struct SListNode
{
	SLNDataType val;
	struct SListNode* next;
	//struct SListNode next;�����ǲ����Ե�
}SLNode;

void SLTprint(SLNode* phead);
SLNode* CreateNode(SLNDataType x);
void SLTpushback(SLNode** phead, SLNDataType x);
void SLTpushFront(SLNode** pphead, SLNDataType x);
void SLTPopBack(SLNode** pphead);
void SLTPopFront(SLNode** pphead);
SLNode* SLTFind(SLNode* phead, SLNDataType x);
void SLTInsert(SLNode** pphead, SLNode* pos, SLNDataType x);//��posǰ����
void SLTErase(SLNode** pphead, SLNode* pos);
void SLTInsertAfter(SLNode* pos, SLNDataType x);
void SLTEraseAfter(SLNode* pos);
void SLTdestroy(SLNode** phead);
