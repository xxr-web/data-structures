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

void Swap(HPDataType* p1, HPDataType* p2)
{
	assert(p1 && p2);
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void HPAdjustUp(HPDataType* p, int child)
{
	assert(p);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (p[child] < p[parent])
		{
			Swap(( & p[child]), ( & p[parent]));
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HPPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : 2 * (php->capacity);
		HPDataType* tmp = (HPDataType*)realloc(php->a, newcapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}
	php->a[php->size] = x;
	php->size++;
	HPAdjustUp(php->a, (php->size - 1));
}

void HPAdjustDown(HP* p, int parent)
{
	assert(p);
	int child = parent * 2 + 1;
	if ((child + 1 < p->size) && (p->a[child + 1] < p->a[child]))
	{
		child = child + 1;
	}
	while (child < (p->size))
	{
		if (p->a[child] < p->a[parent])
		{
			Swap(&(p->a[child]), &(p->a[parent]));
			parent = child;
			child = child * 2 + 1;
			if (p->a[child + 1] < p->a[child])
			{
				child = child + 1;
			}
		}
		else
		{
			break;
		}
	}
}

void HPPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&(php->a[0]), &(php->a[(php->size) - 1]));
	php->size--;
	HPAdjustDown(php, 0);
}

bool HPEmpty(HP* php)
{
	assert(php);
	/*if (php->size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}*/
	return (php->size == 0);
}

HPDataType HPTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}

int HPSize(HP* php)
{
	assert(php);
	return (php->size);
}