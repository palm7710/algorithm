#include <stdio.h>

int N;
int main()
{
    while(1)
    {
        int ans = 0;
        scanf("%d", &N);
        if (N == 0)
            break;
        int i = 1;
        while(i <= N)
        {
            int j = 1;
            while(j <= N)
            {
                ans += (i * j);
                j++;
            }
            i++;
        }
        printf("%d\n", ans);
    }
}