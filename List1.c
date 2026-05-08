/*************************************************************************
	> File Name: List1.c
	> Author: zhh
	> Mail:1497400685@qq.com 
	> Created Time: 五  5月/ 8 21:46:35 2026
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef __has_include
    #if __has_include(<malloc.h>)
        #include <malloc.h>
    #endif
#endif

typedef struct SList
{
    int val;
    struct SList* next;
}SList;


SList* partition(SList* phead,int x)
{
    SList* lessHead,*lessTail;
    SList* greaterHead,*greaterTail;
    lessHead = lessTail = (SList*)malloc(sizeof(SList));
    greaterHead = greaterTail = (SList*)malloc(sizeof(SList));
    lessHead->next = greaterHead->next = NULL;

    SList* cur = phead;
    while(cur)
    {
        if(cur->val<x)
        {
            lessTail->next = cur;
            lessTail = lessTail->next;

        }
        else
        {
            greaterTail->next = cur;
            greaterTail = greaterTail->next;

        }
        cur = cur->next;
    }

    lessTail->next = greaterHead->next;
    SList* list = lessHead->next;
    free(lessHead);
    free(greaterHead);

    return list;
}

int main(void)
{

    return 0;
}



