#include <stdio.h>
int comp(const void*a, const void*b){
    return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),comp);
    int j;
    for(int i = 0; i<numsSize-1; i++){
        j = i+1;
        if(nums[i]==nums[j]){
            return true;
        }
    }
    return false;
}