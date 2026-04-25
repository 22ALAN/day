/*************************************************************************
	> File Name: SList.c
	> Author: zhh
	> Mail:1497400685@qq.com 
	> Created Time: 二  4月/21 22:28:00 2026
 ************************************************************************/
//
#include<stdio.h>

#include <stdlib.h>
#ifdef __has_include
    #if __has_include(<malloc.h>)
        #include <malloc.h>
    #endif
#endif


//结点
typedef struct SListNode
{
    int data;
    struct SListNode* next;
}SL;

SL* BuySListNode(int x)
{
    SL* newnode = (SL*)malloc(sizeof(SL));
    if(newnode==NULL)
    {
        printf("申请结点失败\n");
        exit(-1);
    }

    newnode->data =x;
    newnode->next = NULL;
    return newnode;
}

void SListPrint(SL* pphead)
{
    SL* cur = pphead;
    while(cur!=NULL)
    {
        printf("%d->",cur->data);
        cur = cur->next;
    }
    printf("NULL");
}

void SListPopBack(SL** pphead)
{
    //1.空
    //2.一个结点
    //3.一个以上结点
    if(*pphead==NULL)
    {
        return;
    }
    else if((*pphead)->next ==NULL)
    {
        free(*pphead);
        *pphead=NULL;
    }
    else
    {
        SL* prev = NULL;
        SL* tail = *pphead;
        while(tail->next!=NULL)
        {
            prev = tail;
            tail = tail->next;
        }

        free(tail);

        prev->next = NULL;

    }
}

void SListPushBack(SL** phead,int x)
{
    SL* newnode = BuySListNode(x);
    if(*phead==NULL)
    {
        *phead = newnode;
    }
    else
    {
        SL* cur = *phead;
        while(cur->next!=NULL)
        {
            cur = cur->next;
        }

        cur->next = newnode;
    }

}

void TestSList()
{
    SL* pList = NULL;
    for(int i=0;i<1000;i++)
    {
        SListPushBack(&pList,i);
    }
    SListPrint(pList);
    SListPopBack(&pList);
    SListPrint(pList);
}


int main(void)
{
    TestSList();
    return 0;
}


