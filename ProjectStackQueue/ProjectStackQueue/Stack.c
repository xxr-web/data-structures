#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
void STIni(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->capacity = 0;
	//topָ��ջ��Ԫ��
	pst->top = -1;
	//topָ��ջ��Ԫ�ص���һ��
	//pst->top = 0;
}

void STDestroy(ST* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = 0;
	pst->top = 0;
}

void STPush(ST* pst, STDataType x)
{
	assert(pst);
	if (pst->capacity == pst->top + 1)
	{
		int newcapacity = pst->capacity == 0 ? 4 : 2 * pst->capacity;
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("malloc");
			exit(-1);
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}
	pst->a[pst->top + 1] = x;
	pst->top += 1;
}

void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > -1);
	/*free(pst->a[pst->top]);
	pst->a[pst->top] = NULL;*///�������free������ջ�������һ������´μ����������
	pst->top -= 1;
}

STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > -1);
	return pst->a[pst->top];
}

bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == -1;
}

int STSize(ST* pst)
{
	assert(pst);
	return (pst->top + 1);
}
