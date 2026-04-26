/*************************************************************************
	> File Name: removeElements.c
	> Author: zhh
	> Mail:1497400685@qq.com 
	> Created Time: 日  4月/26 15:55:39 2026
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

SL* removeElements(SL* head,int x)
{
    SL* prev = NULL;
    SL* cur = head;
    while(cur)
    {
        if(cur->data == x)
        {
            if(cur==head)
            {
                head = cur->next;
                free(cur);
            }
            else
            {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        }
        else{
            prev = cur;
            cur = cur->next;
        }

    }
    return head; 


}

int main(void)
{
    SL* n1 = (SL*)malloc(sizeof(SL));
    n1->data = 1;

    SL* n2 = (SL*)malloc(sizeof(SL));
    n2->data = 2;
    SL* n3 = (SL*)malloc(sizeof(SL));
    n3->data = 3;
    SL* n4 = (SL*)malloc(sizeof(SL));
    n4->data = 4;

    SL* n5 = (SL*)malloc(sizeof(SL));
    n5->data = 5;
    SL* n6 = (SL*)malloc(sizeof(SL));
    n6->data = 6;
    SL* n7 = (SL*)malloc(sizeof(SL));
    n7->data = 7;
    SL* n8 = (SL*)malloc(sizeof(SL));
    n8->data = 8;


    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = NULL;

    SL* head = removeElements(n1,6);

    return 0;

}
