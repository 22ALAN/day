/*************************************************************************
	> File Name: 删除元素.c
	> Author: zhh
	> Mail:1497400685@qq.com 
	> Created Time: 六  4月/25 13:14:10 2026
 ************************************************************************/

#include<stdio.h>

#include <stdlib.h>
#ifdef __has_include
    #if __has_include(<malloc.h>)
        #include <malloc.h>
    #endif
#endif
//一个数组内，删除一个特定的数字
int removeElement(int* nums,int numsSize,int val)
{
    int src=0,dst = 0;
    while(src<numsSize)
    {
        if(nums[src] != val)
        {
            nums[dst] = nums[src];
            ++src;
            dst++;

        }
        else
        {
            src++;
        }
    }
    return dst;

}


//删除排序数组中的重复项

int removeDuplicates(int* nums,int numsSize)
{
    if(numsSize==0)
    {
        return 0;
    }
    int prev=0,cur = 1；
    
    while(cur<numsSize)
    {
        if(nums[prev] != nums[cur])
        {
            nums[dst] = nums[prev];
            prev++;
            cur++;
            dst++;
        }
        else
        {
            prev++;
            cur++;
        }
    }

    nums[dst] = nums[prev];
    dst++;
    prev++;

}


