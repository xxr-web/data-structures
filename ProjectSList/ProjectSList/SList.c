#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

void SLprint(SLNode* phead)
{
	SLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
}
