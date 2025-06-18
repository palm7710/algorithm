#include <stdio.h>
#include <stdlib.h>

int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) 
{
    int *ans = (int *)malloc(sizeof(int) * wordsSize);
    int i = 0;
    int k =0;
    while (i < wordsSize)
    {
        int j = 0;
        while (words[i][j])
        {
            if (words[i][j] == x)
            {
                ans[k++] = i;
                break;
            }
            j++;
        }
        i++;
    }
    if (returnSize != NULL)
        *returnSize = k;
    return ans;
}

int main()
{
    int *ans01 = findWordsContaining((char*[]){"leet", "code"}, 2, 'e', NULL);
    int *ans02 = findWordsContaining((char*[]){"abc", "bcd", "aaaa", "cbc"}, 4, 'a', NULL);
    int *ans03 = findWordsContaining((char*[]){"abc", "bcd", "aaaa", "cbc"}, 4, 'z', NULL);
    int i = 0;
    while(i < 2)
    {
        printf("%d ", ans01[i]);
        i++;
    }
    printf("\n");
    i = 0;
    while(i < 2)
    {
        printf("%d ", ans02[i]);
        i++;
    }
    printf("\n");
    i = 0;
    while(i < 0)
    {
        printf("%d ", ans03[i]);
        i++;
    }
}
