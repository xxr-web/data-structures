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
		SLNode* newnode = CreatNode(x);
		tail->next = newnode;//�ı�����Ľṹ��ĳ�Ա���ýṹ��ָ����ʡ�
	}
}

//��Ҫ�±���ʵ���������Ͷ��ֲ��ң��Ͳ���ʹ�������ˣ���Ϊ����ռ䲻������
//˳�������Ƽ�������ռ����������ģ�����Ҳ�ǣ������洢�������ɾ���ͱȽ��鷳�����Ҳ������free��ĳһ���֡�

void SLTpushFront(SLNode** pphead, SLNDataType x)
{
	SLNode* newnode = CreateNode(x);
	newnode->next = *pphead;
	*pphead = newnode;//������ǳ��ʺ�ͷ��
}

