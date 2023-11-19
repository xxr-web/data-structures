#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"

void SqLIni(SqL* p)
{
	assert(p);
	p->psl = NULL;
	p->size = 0;
	p->capacity = 0;
}

void SqLCreate(SqL* p)
{
	if ((p->size) == (p->capacity))
	{
		int newcapacity = p->capacity == 0 ? 4 : 2 * (p->capacity);
		SeQDataType* tmp = (SeQDataType*)realloc(p->psl, newcapacity * sizeof(SeQDataType));
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		p->psl = tmp;
		p->capacity = newcapacity;
	}
}

void SqLPushBack(SqL* p, SeQDataType x)
{
	assert(p);
	SqLCreate(p);
	p->psl[p->size] = x;
	p->size++;
}

void SqLPrint(SqL* p)
{
	assert(p);
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		printf("%d ", p->psl[i]);
	}
	printf("\n");
}

void SqLPopBack(SqL* p)
{
	assert(p);
	assert(p->size > 0);
	p->size--;
}

void SqLPushFront(SqL* p, SeQDataType x)
{
	assert(p);
	SqLCreate(p);
	int i = p->size;
	while (i > 0)
	{
		p->psl[i] = p->psl[i - 1];
		i -= 1;
	}
	p->psl[i] = x;
	p->size++;
}
void SqLPopFront(SqL* p)
{
	assert(p);
	assert(p->size > 0);
	int i = 0;
	while (i < (p->size - 1))
	{
		p->psl[i] = p->psl[i + 1];
		i += 1;
	}
	p->size--;
}

int SqLFind(SqL* p, SeQDataType x)
{
	assert(p);
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		if (p->psl[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SqLInsert(SqL* p, int pos, SeQDataType x)
{
	assert(p);
	assert((pos >= 0) && (pos <= p->size));
	SqLCreate(p);
	int i = p->size;
	while (i != pos)
	{
		p->psl[i] = p->psl[i - 1];
		i -= 1;
	}
	p->psl[i] = x;
	p->size++;
}
void SqLDelete(SqL* p, int pos)
{
	assert(p);
	assert((p->size) > 0);
	assert((pos >= 0) && (pos <= p->size));
	int i = pos;
	while (i < (p->size - 1))
	{
		p->psl[i] = p->psl[i + 1];
		i += 1;
	}
	p->size--;
}

void SqLDestroy(SqL* p)
{
	free(p->psl);
	p->psl = NULL;
	p->size = 0;
	p->capacity = 0;
}