#define _CRT_SECURE_NO_WARNINGS
#include "SQList.h"
void SLini(SL* psL)
{
	psL->p = NULL;
	psL->size = 0;
	psL->capacity = 0;
}

void SLprinttest(SL* psL)
{
	printf("%d %d", psL->size, psL->capacity);
}

void SLprint(SL* psL)
{
	int i = 0;
	for (i = 0; i < psL->size; i++)
	{
		printf("%d ", psL->p[i]);
	}
}
void SLcheck(SL* psL)
{
	if ((psL->size) == (psL->capacity))
	{
		int newcapacity = (psL->capacity == 0) ? 4 : 2 * (psL->capacity);//����
		TypeData* p1 = (TypeData*)realloc(psL->p, sizeof(TypeData) * newcapacity);
		if (p1 == NULL)
		{
			perror("realloc");
			return;
		}
		psL->p = p1;
		psL->capacity = newcapacity;
	}
}

void SLpushback(SL* psL, TypeData x)
{
	SLcheck(psL);
	psL->p[psL->size] = x;
	psL->size++;
}

void SLpushfront(SL* psL, TypeData x)
{
	SLcheck(psL);
	int tmp = psL->size;
	while (tmp > 0)
	{
		psL->p[tmp] = psL->p[tmp - 1];
		--tmp;
	}
	psL->p[tmp] = x;
	psL->size++;
}

void SLpopback(SL* psL)
{
	assert((psL->size) > 0);
	psL->size --;
	//��һ��д����psL->size - 1; û���ð�������
}

void SLpopfront(SL* psL)
{
	assert((psL->size) > 0);
	int tmp = 0;
	while (tmp < (psL->size) - 1)
	{
		psL->p[tmp] = psL->p[tmp + 1];
		++tmp;
	}
	psL->p[tmp] = 0;
	psL->size--;
}

void SLdestroy(SL* psL)
{
	free(psL->p);
	psL->p = NULL;
	psL->size = 0;
	psL->capacity = 0;
}

//����typedef TypeData����ĵط�����������Ҫ�ĵط��Ͳ�Ҫ������������size��capacity����int�͵ľͿ����ˣ�����posλ�õ�ֵ���ģ�pos�൱�������±꣬Ĭ�Ͼ�Ӧ����int����

void SLinsert(SL* psL, int pos, TypeData x)
{
	SLcheck(psL);
	assert((pos >= 0) && (pos <= (psL->size)));
	int tmp = (psL->size) - 1;
	while (tmp >= pos)
	{
		psL->p[tmp + 1] = psL->p[tmp];
		--tmp;
	}
	psL->p[pos] = x;
	psL->size++;
}

void SLerase(SL* psL, int pos)
{
	assert((pos >= 0) && (pos <= (psL->size)));
	int tmp = pos;
	while (tmp < (psL->size) - 1)
	{
		psL->p[tmp] = psL->p[tmp + 1];
		++tmp;
	}
	psL->size--;
}

int SLfind(SL* psL, TypeData x)
{
	int i = 0;
	for (i = 0; i < psL->size; i++)
	{
		if (x == psL->p[i])
		{
			return i;
		}
	}
	return 0;
}
