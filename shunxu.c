/*************************************************************************
	> File Name: 顺序表.c
	> Author: zhh
	> Mail:1497400685@qq.com 
	> Created Time: 日  4月/19 18:29:22 2026
 ************************************************************************/
 //创建一个顺序表

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
    SeqListPrint(&s);

}

int main(void)
{
    TestSeqList();
    return 0;
}
