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
//˫���ͷѭ������Ҫ���ֳ�������ͷ�����һ����˳���͵������൱�ڳ�ʼʱ��ָ�붼��ָ��NULL�ռ䣬����ν���������Ҫ���ֳ�������
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

