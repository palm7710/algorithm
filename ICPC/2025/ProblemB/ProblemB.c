#include <stdio.h>

int n;
char s[256];

int main()
{
    while (1)
    {
        int cnt = 0;
        int k = 0;
        scanf("%d", &n);
        if (n == 0)
            break;
        int i = 0;
        while (i < n)
        {
            scanf(" %c", &s[i]);
            i++;
        }
        i = 1;
        while (i < n)
        {
            int match = 1;
            int j = 0;
            while (j < n - i)
            {
                if (s[j] != s[i + j])
                {
                    match = 0;
                    break;
                }
                j++;
            }
            if (match)
                break;
            i++;
        }
        int j = 0;
        while(j < n)
        {
            printf("%c", s[j]);
            j++;
        }
        j = n - i;
        while (j < n)
        {
            printf("%c", s[j]);
            j++;
        }
        printf("\n");
    }
}