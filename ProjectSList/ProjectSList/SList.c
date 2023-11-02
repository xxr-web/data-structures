#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

void SLTprint(SLNode* phead)
{
	SLNode* cur = phead;//phead不要动，避免以后找不到头。
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
		*pphead = newnode;//改变外面结构体指Node*,要用Node**
	}
	else
	{
		//找尾
		SLNode* tail = *pphead;
		while (tail->next != NULL)//下一个指向空指针的就是尾结点。
		{
			tail = tail->next;
		}
		//while (tail->next != NULL)//下一个指向空指针的就是尾结点。
		//{
		//	tail = tail->next;
		//}//这个是不可以的，两点原因，1.和前面的连不上了，没有链接起来。2.出了作用域后，tail被销毁，就找不到新创建的这个结点了，内存泄漏。
		//SLNode newnode//这是不可以的，因为这是局部变量，出去了就销毁了。
		SLNode* newnode = CreatNode(x);
		tail->next = newnode;//改变外面的结构体的成员，用结构体指针访问。
	}
}

//需要下标访问的例如排序和二分查找，就不能使用链表了，因为物理空间不连续。
//顺序表的优势既是物理空间连续带来的，劣势也是，连续存储，插入和删除就比较麻烦，并且不能随便free掉某一部分。

void SLTpushFront(SLNode** pphead, SLNDataType x)
{
	SLNode* newnode = CreateNode(x);
	newnode->next = *pphead;
	*pphead = newnode;//单链表非常适合头插
}

