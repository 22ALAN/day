/*************************************************************************
	> File Name: 快慢指针_test.c
	> Author: zhh
	> Mail:1497400685@qq.com 
	> Created Time: 日  4月/26 19:50:23 2026
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


SL* middleNode(SL* head)
{
    SL* slow = head;
    SL* fast = head->next;

    while(fast&&fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
