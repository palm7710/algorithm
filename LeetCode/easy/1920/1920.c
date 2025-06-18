#include <stdio.h>
#include <stdlib.h>

int* buildArray(int* nums, int numsSize, int* returnSize)
{
    int *ans = (int *)malloc(sizeof(int) * numsSize);
    int i = 0;
    while (i < numsSize)
    {
        ans[i] = nums[nums[i]];
        i++;
    }
    if (returnSize != NULL)
        *returnSize = numsSize;
    return ans;
}

int main(void)
{
    int *ans01 = buildArray((int[]){0,2,1,5,3,4}, 6, NULL);
    int *ans02 = buildArray((int[]){5,0,1,2,3,4}, 6, NULL);
    int i = 0;
    while (i < 6)
    {
        printf("%d", ans01[i]);
        i++;
    }
    printf("\n");
    i = 0;
    while (i < 6)
    {
        printf("%d", ans02[i]);
        i++;
    }
    free(ans01);
    free(ans02);
}