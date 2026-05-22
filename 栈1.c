/*************************************************************************
	> File Name: 栈1.c
	> Author: zhh
	> Mail:1497400685@qq.com 
	> Created Time: 四  5月/14 20:13:05 2026
 ************************************************************************/

#include<stdio.h>
#include <assert.h>

#include <stdlib.h>
#ifdef __has_include
    #if __has_include(<malloc.h>)
        #include <malloc.h>
    #endif
#endif

//栈和队列属于线性表
//n格元素构成的集合，逻辑结构上呈现线性
//顺序表
//链表
//栈和队列
//串(字符串)
//
//栈，一种特殊的线性表，其允许在固定的一端进行插入和删除元素的操作，进行数据插入和删除的操作的一端称为栈顶，另一端称为栈底

//压栈，栈的插入操作叫做进栈/压栈/入栈
//出栈，栈的删除操作叫做出栈

//栈中的数据元素遵守后进先出LIFO（Last In First Out）的原则

typedef struct Stack
{
    int* _a;

    int _top;
    int _capacity;
}Stack;

void StackInit(Stack* pst)
{
    assert(pst);
    pst->_a = (int*)malloc(sizeof(int)*4);
    pst->_top = 0;
    pst->_capacity = 4;

}

void StackDestory(Stack* pst)
{
    assert(pst);
    free(pst->_a);
    pst->_a = NULL;
    pst->_top = pst->_capacity = 0;
}

void StackPush(Stack* pst,int x)
{
    assert(pst);

    if(pst->_top == pst->_capacity)
    {
        pst->_capacity *= 2;
        int* tmp = (int*)realloc(pst->_a,sizeof(int)*pst->_capacity);
        if(tmp==NULL)
        {
            printf("内存不足!!\n");
            exit(-1);
        }
        else
        {
            pst->_a = tmp;
        }
    }
    pst->_a[pst->_top] = x;
    pst->_top++;
}

//出栈

void StackPop(Stack* pst)
{
    assert(pst);
    assert(pst->_top>0);
    pst->_top--;
}

int StackSize(Stack* pst)
{
    assert(pst);
    return pst->_top;
}

int StackEmpty(Stack* pst)
{
    assert(pst);

    return pst->_top == 0 ? 1 : 0;
    
}

//获取栈顶的数据

int StackTop(Stack* pst)
{
    assert(pst);
    assert(pst->_top>0);

    return pst->_a[pst->_top-1];
}

//如果是双向链表，那么哪边是栈顶，哪边是栈底，其实都可以那么如果是单链表


int main(void)
{
    return 0;        
}
