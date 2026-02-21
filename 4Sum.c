#include <stdlib.h>

int cmp(const void* a, const void* b) {
    long x = *(int*)a;
    long y = *(int*)b;
    return (x > y) - (x < y);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int cap = 1000;
    int** res = malloc(cap * sizeof(int*));
    *returnColumnSizes = malloc(cap * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            int l = j + 1;
            int r = numsSize - 1;

            while (l < r) {
                long sum = (long)nums[i] + nums[j] + nums[l] + nums[r];

                if (sum == target) {
                    res[*returnSize] = malloc(4 * sizeof(int));
                    res[*returnSize][0] = nums[i];
                    res[*returnSize][1] = nums[j];
                    res[*returnSize][2] = nums[l];
                    res[*returnSize][3] = nums[r];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;

                    l++;
                    r--;
                }
                else if (sum < target) l++;
                else r--;
            }
        }
    }

    return res;
}