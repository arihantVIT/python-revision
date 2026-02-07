int removeDuplicates(int* nums, int numsSize) {
    int i = 0;

    while (i < numsSize - 1) {
        if (nums[i] == nums[i + 1]) {
            // delete nums[i+1] by shifting left
            for (int j = i + 1; j < numsSize - 1; j++) {
                nums[j] = nums[j + 1];
            }
            numsSize--;
        } else {
            i++;
        }
    }
    return numsSize;
}
