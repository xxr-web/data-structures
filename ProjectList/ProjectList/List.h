#pragma once
#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <stdlib.h>
typedef int ListDataType;
typedef struct ListNode
{
	ListDataType val;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;

LTNode* LTIni();
LTNode* CreateNode(ListDataType x);
void LTPrint(LTNode* phead);
void LTPushback(LTNode* phead, ListDataType x);
void LTPopback(LTNode* phead);

