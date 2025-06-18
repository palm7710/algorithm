int dfs(int* nums, int numsSize, int index, int currentXOR)
{
    if (index == numsSize)
        return currentXOR;
    return dfs(nums, numsSize, index + 1, currentXOR ^ nums[index]) + dfs(nums, numsSize, index + 1, currentXOR);
}

int subsetXORSum(int* nums, int numsSize)
{
    return dfs(nums, numsSize, 0, 0);
}

#include <stdio.h>
int main()
{
    int nums1[] = {1, 3};
    int nums2[] = {5, 1, 6};
    int nums3[] = {3, 4, 5, 6, 7, 8};
    printf("%d\n", subsetXORSum(nums1, 2));
    printf("%d\n", subsetXORSum(nums2, 3));
    printf("%d\n", subsetXORSum(nums3, 6));
}