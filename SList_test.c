/*************************************************************************
	> File Name: SList_test.c
	> Author: zhh
	> Mail:1497400685@qq.com 
	> Created Time: 日  4月/26 13:07:36 2026
 ************************************************************************/

#include<stdio.h>

#include <stdlib.h>
#ifdef __has_include
    #if __has_include(<malloc.h>)
        #include <malloc.h>
    #endif
#endif

typedef struct SList
{
    int data;
    SL* next;
}SL;

SL* reverseList(SL* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    SL* newHead = NULL;
    SL* cur = head;

    while(cur)
    {
        SL* next = cur->next;
        
        cur->next = newHead;
        newHead = cur;

        cur = next;

    }
    return newHead;

}


