#pragma once

//Single List
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

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
