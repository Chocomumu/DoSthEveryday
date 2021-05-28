int totalHammingDistance(int* nums, int numsSize){
    int num[32] = {0};
    for(int i=0;i<numsSize;i++){
        for(int j=0;j<32;j++){
            if(nums[i]&1)
                num[j]++;
            nums[i]>>=1;
        }
    }
    int count = 0;
    for(int i=0;i<32;i++){
        count += num[i]*(numsSize-num[i]);
    }
    return count;    
}
