#include <stdlib.h>

int* getConcatenation(int* nums, int numsSize, int* returnSize) 
{
    int i = 0;
    int *ans = (int *)malloc(sizeof(int) * numsSize * 2);
    while (i < numsSize)
    {
        ans[i] = nums[i];
        ans[i + numsSize] = nums[i];
        i++;
    }
    if (returnSize != NULL)
        *returnSize = numsSize * 2;
    return ans;
}

#include <stdio.h>
int main()
{
    int *ans01 = getConcatenation((int []){1,2,1}, 3, NULL);
    int *ans02 = getConcatenation((int []){1,3,2,1}, 4, NULL);

    int i = 0;
    while(i < 6)
    {
        printf("%d ", ans01[i]);
        i++;
    }
    printf("\n");
    i = 0;
    while(i < 8)
    {
        printf("%d ", ans02[i]);
        i++;
    }
}