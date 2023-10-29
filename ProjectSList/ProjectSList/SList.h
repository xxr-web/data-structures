#pragma once

//Single List
#include <stdio.h>

typedef int SLNDataType;

typedef struct SListNode
{
	SLNDataType val;
	struct SListNode* next;
}SLNode;

void SLprint(SLNode* phead);
