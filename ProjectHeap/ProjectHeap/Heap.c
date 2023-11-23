#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"

void HPIni(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}

void HPDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}

void Swap(HDataType* p1, HDataType* p2)
{
	HDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void HPAdjustUp(HDataType* a, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HPPush(HP* php, HDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HDataType* tmp = (HDataType*)realloc(php->a, newcapacity * sizeof(HDataType));
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		php->a = tmp;
	}
	php->a[php->size] = x;
	php->size++;
	HPAdjustUp(php->a, (php->size - 1));
}