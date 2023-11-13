#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* prev;
	LTDataType x;
	struct ListNode* next;
}LT;

LT* CreateNode(LTDataType x);
//双向带头循环链表要体现出来创建头结点这一步，顺序表和单链表相当于初始时的指针都是指向NULL空间，无所谓，这个必须要体现出创建。
LT* LTIni();
void LTPushBack(LT* phead, LTDataType x);
void LTPopBack(LT* phead);
void LTPushFront(LT* phead, LTDataType x);
void LTPopFront(LT* phead);
void LTPrint(LT* phead);
LT* LTFind(LT* phead, LTDataType x);
void LTInsert(LTDataType x, LT* pos);
void LTErase1(LT* pos);
void LTErase2(LT* pos);
void LTDestroy(LT* phead);

