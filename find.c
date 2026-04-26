/*************************************************************************
	> File Name: find.c
	> Author: zhh
	> Mail:1497400685@qq.com 
	> Created Time: 日  4月/26 21:48:21 2026
 ************************************************************************/

#include<stdio.h>

#include <stdlib.h>
#ifdef __has_include
    #if __has_include(<malloc.h>)
        #include <malloc.h>
    #endif
#endif

//找到倒数第k个节点
struct ListNode* FindKthToTail(struct ListNode* pListHead,int k)
{
    SL* fast = pListHead,*slow = pListHead;
    while(k--)
    {
        if(fast)
        {
            fast = fast->next;
        }
        else{
            printf("链表长度小于第k的节点的范围\n");
            return NULL;
        }
    }

    while(fast)
    {
        slow = slow->next;
        fast = fast->next;

    }
    return slow;
}
