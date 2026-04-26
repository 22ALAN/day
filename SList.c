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

void SListPushFront(SL** pphead,int x)
{
    SL* newnode = BuySListNode(x);
    newnode->next = *pphead;
    *pphead = newnode;
}

void SListInsertAfter(SL* pos,int x)
{
    assert(pos);
    SL* newnode = BuySListNode(x);

    newnode->next = pos->next;
    pos->next = newnode;

}

void SListEraseAfter(SL* pos)
{
    assert(pos);

    if(pos->next)
    {
        SL* next = pos->next;
        SL* nextnext = next->next;
        pos->next = nextnext;
        free(next);
    }
}

void SListPopFront(SL** pphead)
{
    //1.空
    //2.一个节点
    //3.一个以上的节点
    if(*pphead==NULL)
    {
        return;
    }
    else
    {
        SL* next = (*pphead)->next;
        free(*pphead);

        *pphead=next;

    }
}

SL* SListFind(SL* phead,int x)
{
    SL* cur = phead;
    while(cur)
    {
        if(cur->data==x)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
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

    SL* pos = SListFind(pList,3);
    if(pos)
    {
        pos->data = 30;
    }
    SListPrint(pList);
}

SL* reverseList(SL* phead)
{
    if(phead==NULL || phead->next ==NULL)
    {
        return phead;
    }
    SL* n1= NULL;
    SL* n2 = phead;
    SL* n3 = phead->next;

    while(n2)
    {
        //反转
        n2->next = n1;
        
        //迭代
        n1 = n2;
        n2 = n3;

        if(n3)
        {
            
            n3 = n3->next;
        }

    }
    return n1;

}

int main(void)
{
    TestSList();
    return 0;
}


