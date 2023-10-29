#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
typedef int TypeData;//�����ں������ı������͵�ʱ��ֱ�����⻻int����

typedef struct SQList
{
	TypeData* p;
	int size;
	int capacity;
}SL;

void SLini(SL* psL);//��ʼ��
void SLprinttest(SL* psL);//���Դ�ӡ
void SLpushback(SL* psL, TypeData x);//���
void SLcheck(SL* psL);
void SLprint(SL* psL);
void SLpushfront(SL* psL, TypeData x);//ǰ��
void SLpopback(SL* psL);//��ɾ
void SLpopfront(SL* psL);//ǰɾ
void SLdestroy(SL* psL);//����
void SLinsert(SL* psL, int pos, TypeData x);//�м�λ�ò���
void SLerase(SL* psL, int pos);//�м�λ������
int SLfind(SL* psL, TypeData x);



