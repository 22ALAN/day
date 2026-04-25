/*************************************************************************
	> File Name: 数组形式的加法.c
	> Author: zhh
	> Mail:1497400685@qq.com 
	> Created Time: 六  4月/25 17:38:40 2026
 ************************************************************************/

#include<stdio.h>

#include <stdlib.h>
#ifdef __has_include
    #if __has_include(<malloc.h>)
        #include <malloc.h>
    #endif
#endif
//数组形式的整数加法
//A=[1,2,0,0],K =34
//得到[1,2,3,4]

int* addToArrayForm(int* A,int ASize,int K,int* returnSize)
{
    int KSize = 0;
    int KNUm = K;
    while(K)
    {
        ++KSize;
        K/=10;
    }
    
    int len = ASize>KSize?ASize:KSize;
    int* retArr = (int*)malloc(sizeof(int)*(len+1));
    
    int Ai =ASize-1;
    int Ki = KSize-1;
    int reti = 0;
    int nextNum = 0;//表示进位的数值
    while(len--)
    {
        int a = 0;
        if(Ai>=0)
        {
            a = A[Ai];
            Ai--;
        }
        int ret = a+K%10+nextNum;
        K/=10;

        if(ret>9)
        {
            ret -= 10;
            nextNum = 1;
        }
        else
        {
            nextNum = 0;
        }
        retArr[reti] = ret;
        ++reti;
    }

    if(nextNum==1)
    {
        retArr[reti] = 1;
        ++reti;
    }

    int left =0,right = reti-1;
    while(left<right)
    {
        int tmp = retArr[left];
        retArr[left] = retArr[right];
        retArr[right]= tmp;
        ++left;
        --right;
    }
    *returnSize= reti;

    return retArr;

}
