#include <stdio.h>
#include <stdlib.h>

int elementIndex(int nums[], int size, int target, int index_arr[]) {
    int index = 0;
    for (int i = 0; i<size; i++) {
        if (nums[i]==target) {
            index_arr[index]=i;
            index++;
        }
    }
    return index;
}

void indDeletion(int arr[], int size, int index) {
    for (int i = index; i<size-1; i++) {
        arr[i]=arr[i+1];
    }
}

int removeElement(int* nums, int numsSize, int val) {
    int index_arr[100];
    int index_size = elementIndex(nums,numsSize,val,index_arr);
    for (int i = index_size-1; i>=0; i--) {
        indDeletion(nums,numsSize,index_arr[i]);
        numsSize-=1;
    }
    return numsSize;
}