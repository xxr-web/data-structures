#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

void SLTprint(SLNode* phead)
{
	SLNode* cur = phead;//phead��Ҫ���������Ժ��Ҳ���ͷ��
	while (cur != NULL)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLNode* CreateNode(SLNDataType x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;
	return newnode;
}

void SLTpushback(SLNode** pphead, SLNDataType x)
{
	assert(pphead);
	SLNode* newnode = CreateNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;//�ı�����ṹ��ָNode*,Ҫ��Node**
	}
	else
	{
		//��β
		SLNode* tail = *pphead;
		while (tail->next != NULL)//��һ��ָ���ָ��ľ���β��㡣
		{
			tail = tail->next;
		}
		//while (tail->next != NULL)//��һ��ָ���ָ��ľ���β��㡣
		//{
		//	tail = tail->next;
		//}//����ǲ����Եģ�����ԭ��1.��ǰ����������ˣ�û������������2.�����������tail�����٣����Ҳ����´������������ˣ��ڴ�й©��
		//SLNode newnode//���ǲ����Եģ���Ϊ���Ǿֲ���������ȥ�˾������ˡ�
		SLNode* newnode = CreateNode(x);
		tail->next = newnode;//�ı�����Ľṹ��ĳ�Ա���ýṹ��ָ����ʡ�
	}
}

//��Ҫ�±���ʵ���������Ͷ��ֲ��ң��Ͳ���ʹ�������ˣ���Ϊ����ռ䲻������
//˳�������Ƽ�������ռ����������ģ�����Ҳ�ǣ������洢�������ɾ���ͱȽ��鷳�����Ҳ������free��ĳһ���֡�

void SLTpushFront(SLNode** pphead, SLNDataType x)
{
	assert(pphead);
	SLNode* newnode = CreateNode(x);
	newnode->next = *pphead;
	*pphead = newnode;//������ǳ��ʺ�ͷ��
}

void SLTPopBack(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	if ((*pphead)->next == NULL)//SList1�����
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//SLNode* tail = *pphead;
		//SLNode* tmptail = NULL;
		//while (tail->next != NULL)
		//{
		//	tmptail = tail;
		//	tail = tail->next;
		//}
		//free(tail);
		//tail = NULL;
		//tmptail->next = NULL;//һ�����ʱ�ᱨ��
		SLNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

void SLTPopFront(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	SLNode* phead = *pphead;
	*pphead = phead->next;
	free(phead);
	phead = NULL;
}

SLNode* SLTFind(SLNode* phead, SLNDataType x)//��������Ҳ���Ҳ�ܺ���
{
	SLNode* cur = phead;
	while (cur)
	{
		if (cur->val == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

void SLTInsert(SLNode** pphead, SLNode* pos, SLNDataType x)
{
	assert(pphead);
	//assert((*pphead && pos) || (!pos && !(*pphead)));//Ҫô���ǿգ�Ҫô�����ǿա��ϸ���˵������β�塣���������ϸ��ж�posһ�������������һ����Ч��㡣
	SLNode* cur = *pphead;
	if (*pphead == pos)
	{
		//ͷ��
		SLTpushFront(pphead, x);
	}
	else
	{
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
		if (newnode == NULL)
		{
			perror("malloc");
			exit(-1);
		}
		cur->next = newnode;
		newnode->val = x;
		newnode->next = pos;
	}
}

void SLTErase(SLNode** pphead, SLNode* pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);
	if (*pphead == pos)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLNode* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SLTInsertAfter(SLNode* pos, SLNDataType x)
{
	assert(pos);
	SLNode* newnode = CreateNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLTEraseAfter(SLNode* pos)
{
	assert(pos);
	//free(pos->next);
	//pos->next = pos->next->next;
	SLNode* tmp = pos->next;
	pos->next = pos->next->next;//tmp��ָ�򲻻ᱻ�ı䡣
	free(tmp);
	tmp = NULL;
}

void SLTdestroy(SLNode** pphead)
{
	assert(pphead);
	SLNode* cur = *pphead;
	while (cur)
	{
		SLNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}




