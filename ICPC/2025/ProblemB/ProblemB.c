#include <stdio.h>

int n;
char s[256];

int main()
{
    int tmp[256] = {0};
    int k = 0;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        int i = 0;
        while (i < n)
        {
            scanf(" %c", &s[i]);
            i++;
        }
        i = n - 1;
        while (i > 0)
        {
            int j = 0;
            while (j < n)
            {
                if (s[i] == s[j])
                {
                    tmp[k++] = i;
                    break;
                }
                j++;
            }
            i--;
        }
        i = 0;
        int index = 0;
        while(i < n)
        {
            if (tmp[i] + 1 != tmp[i + 1])
                index = tmp[i];
            else
                break;
            i++;
        }
        i = 0;
        while(i < n)
        {
            printf("%c", s[i]);
            i++;
        }
        i = index + 1;
        while (i <= n)
        {
            printf("%c", s[i]);
            i++;
        }
        printf("\n");
    }
}