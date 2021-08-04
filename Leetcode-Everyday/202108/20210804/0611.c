#include<stdio.h>
#include<stdlib.h>
int compare(void* a, void *b)
{
    return *(int *)a - *(int *)b;
}
int triangleNumber(int* nums, int numsSize){
    if (numsSize < 3) return 0;
    int count = 0;
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i = 0; i < numsSize - 2; i++)
    {
        for (int j = i + 1; j < numsSize - 1;j++)
        {
            int left = j + 1, right = numsSize - 1, k = j;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (nums[mid] < nums[i] + nums[j]) {
                    k = mid;
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            count += k - j;
        }
    }
    return count;
}

int main(){
    return 0;
}