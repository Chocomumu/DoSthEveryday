#include<stdio.h>
int numberOfArithmeticSlices(int* nums, int numsSize){
    if (numsSize < 3)
    {
        return 0;
    }
    int cur_d = nums[1] - nums[0];      /* 当前等差数列d */
    int count = 0;                      /* 当前等差数列个数 */
    int cur_len = 2;                    /* 当前连续序列的长度 */
    for(int i = 2; i < numsSize; i++)
    {
        if (nums[i] - nums[i - 1] == cur_d)
        {
            count += cur_len ++ - 1;
        }
        else
        {
            cur_len = 2;
            cur_d = nums[i] - nums[i - 1];
        }
    }
    return count;
}