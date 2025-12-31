#include <stdio.h>
#include <stdlib.h>

int linearSearch(int nums[], int size, int element, int index[]) {
    int match = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i]==element) {
            index[match]=i;
            match++;
        }
    }
    return match;
}

void deletion(int nums[], int size, int index) {
    for (int i = index; i < size-1; i++) {
        nums[i]=nums[i+1];
    }
}

void insertion(int nums[], int size, int element, int index) {
    for(int i = size-1; i>=index; i--) {
        nums[i+1]=nums[i];
    }
    nums[index]=element;
}

void moveZeroes(int* nums, int numsSize) {
    int index[10000]; //index = {0,2}
    int index_size = linearSearch(nums,numsSize,0,index);
    for (int i = index_size-1; i>=0; i--) {
        deletion(nums,numsSize,index[i]);
        numsSize-=1;
    }
    for (int i = 0; i < index_size; i++) {
        insertion(nums, numsSize, 0, numsSize);
        numsSize+=1;
    }
    
}