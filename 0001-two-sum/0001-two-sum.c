#include <stdio.h>
#include <stdlib.h>

struct numsIndex{
    int element;
    int index;
};

int comp(const void *a, const void *b) {
    return (((struct numsIndex*)a)->element - ((struct numsIndex*)b)->element);
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    struct numsIndex numbers[numsSize];
    //sorting
    for (int i = 0; i < numsSize; i++) {
        numbers[i].element = nums[i];
        numbers[i].index=i;
    }

    qsort(numbers, numsSize, sizeof(struct numsIndex), comp);
    //Two pointer
    int i = 0;
    int sum;
    int j = numsSize-1;
    while (i<j) {
        sum = numbers[i].element+numbers[j].element;
        if (sum == target) {
            result[0]=numbers[i].index;
            result[1]=numbers[j].index;
            return result;
        }
        else if (sum<target) {
            i++;
        }
        else {
            j--;
        }
    }
    *returnSize=0;
    return NULL;
}
