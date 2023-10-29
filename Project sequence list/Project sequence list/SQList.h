#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
typedef int TypeData;//可以在后续更改变量类型的时候，直接在这换int就行

typedef struct SQList
{
	TypeData* p;
	int size;
	int capacity;
}SL;

void SLini(SL* psL);//初始化
void SLprinttest(SL* psL);//测试打印
void SLpushback(SL* psL, TypeData x);//后插
void SLcheck(SL* psL);
void SLprint(SL* psL);
void SLpushfront(SL* psL, TypeData x);//前插
void SLpopback(SL* psL);//后删
void SLpopfront(SL* psL);//前删
void SLdestroy(SL* psL);//销毁
void SLinsert(SL* psL, int pos, TypeData x);//中间位置插入
void SLerase(SL* psL, int pos);//中间位置销毁
int SLfind(SL* psL, TypeData x);



