#include <stdio.h>

int findCandidate(int *arr, int size){
    int maj_index = 0;
    int count = 1;
    for(int i = 1; i<size; i++){
        if(arr[maj_index]==arr[i]){
            count++;
        }
        else{
            count--;
        }
        if (count==0){
            maj_index=i;
            count = 1;

        }
    }
    return arr[maj_index];
}

int isMajority(int *arr, int size, int cand){
    int count=0;
    for(int i = 0; i<size; i++){
        if(arr[i]==cand){
            count++;
        }
    }
    if (count>(size/2)){
        return 1;
    }
    else{
        return 0;
    }
}

int majorityElement(int* nums, int numsSize) {
    int cand = findCandidate(nums,numsSize);
    if (isMajority(nums,numsSize,cand)){
        return cand;
    }
    return -1;
}