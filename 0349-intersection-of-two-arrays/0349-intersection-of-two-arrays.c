#include <stdlib.h>

int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int removeDups(int arr[], int size) {
    if (size == 0) return 0;

    int i = 0;
    for (int j = 1; j < size; j++) {
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}

int* intersection(int* nums1, int nums1Size,
                  int* nums2, int nums2Size,
                  int* returnSize) {

    // sort both arrays
    qsort(nums1, nums1Size, sizeof(int), comp);
    qsort(nums2, nums2Size, sizeof(int), comp);

    // remove duplicates
    nums1Size = removeDups(nums1, nums1Size);
    nums2Size = removeDups(nums2, nums2Size);

    // allocate result array
    int *result = (int *)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));

    int i = 0, j = 0, count = 0;

    // two pointers intersection
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] == nums2[j]) {
            result[count++] = nums1[i];
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    *returnSize = count;
    return result;
}
