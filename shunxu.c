/*************************************************************************
	> File Name: 顺序表.c
	> Author: zhh
	> Mail:1497400685@qq.com 
	> Created Time: 日  4月/19 18:29:22 2026
 ************************************************************************/
 //创建一个顺序表
//顺序表的优点：随机访问，缓存利用率比较高

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include <stdlib.h>
#ifdef __has_include
    #if __has_include(<malloc.h>)
        #include <malloc.h>
    #endif
#endif

typedef struct SeqList
{
    int* _a;
    size_t _size;
    size_t _capacity;
}SL;


void SeqListCheckCapacity(SL* ps)
{
    assert(ps);
    if(ps->_size >=ps->_capacity)
    {
        ps->_capacity*=2;
        ps->_a = (int*)realloc(ps->_a,sizeof(int)*ps->_capacity);
        if(ps->_a == NULL)
        {
            printf("申请内存失败!\n");
            exit(-1);
        }
    }
    
}

void SeqListInit(SL* ps)
{
    assert(ps);
    ps->_a = (int*)malloc(sizeof(int)*4);
    if(ps->_a ==NULL)
    {
        printf("申请内存失败!\n");
        exit(-1);
    }

    ps->_size =0;
    ps->_capacity = 4;
}

void SeqListPushBack(SL* ps,int x)
{
    assert(ps);
    SeqListCheckCapacity(ps);
    ps->_a[ps->_size] = x;
    ps->_size++;
}

void SeqListPrint(SL* ps)
{
    assert(ps);
    for(int i=0;i<ps->_size;i++)
    {
        printf("%d ",ps->_a[i]);
    }
    printf("\n");
}

void SeqListPopBack(SL* ps)
{
    assert(ps);

    ps->_a[ps->_size-1] = 0;
    ps->_size--;

}

void SeqListPopFront(SL* ps)
{
    assert(ps);

    int start = 0;
    while(start<ps->_size-1)
    {
        ps->_a[start] = ps->_a[start+1];
        start++;
    }

}

void SeqListPushFront(SL* ps,int x)
{
    assert (ps);

    int end = ps->_size-1;
    while(end>=0)
    {
        ps->_a[end+1] = ps->_a[end];
        end--;
    }

    ps->_a[0] = x;
    ps->_size++;
}


void SeqListDestory(SL* ps)
{
    free(ps->_a);
    ps->_a = NULL;
    ps->_size = 0;
    ps->_capacity  =0;

}

void SeqListInsert(SL* ps,int pos,int x)
{
    assert(ps);
    assert(pos<ps->_size&& pos>=0);
    SeqListCheckCapacity(ps);
    int end = ps->_size-1;
    while(end>=pos)
    {
        ps->_a[end+1] = ps->_a[end];
        --end;
    }
    ps->_a[pos] = x;
    ps->_size++;

}


void SeqListErase(SL* ps,int pos)
{
    assert(pos);
    assert(pos>ps->_size&& pos>=0);

    int start = pos;
    while(start<ps->_size-1)
    {
        ps->_a[start] = ps->_a[start+1];
        ++start;
    }
    ps->_size--;
    
}

int SeqListFind(SL* ps,int x)
{
    assert(ps);
    for(int i=0;i<ps->_size-1;i++)
    {
        if(ps->_a[i] == x)
        {
            return i;
        }
    }
    return -1;

}

void TestSeqList()
{
    SL s;
    SeqListInit(&s);
    SeqListPushBack(&s,1);
    SeqListPushBack(&s,2);
    SeqListPushBack(&s,3);
    SeqListPushBack(&s,4);
    SeqListPushBack(&s,5);
    SeqListPushBack(&s,6);
    SeqListPushBack(&s,7);
    SeqListPushBack(&s,8);
    for(int i=-100;i<0;i++)
    {
        SeqListPushFront(&s,i);
    }
    SeqListPopFront(&s);
    SeqListPrint(&s);

}

int main(void)
{
    TestSeqList();
    return 0;
}
