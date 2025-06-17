#include <stdio.h>
int N;
int A[1000];

int main()
{
    int i;
    int ans;
    while (1)
    {
        scanf("%d", &N); // *お菓子の数
        if (N == 0)
            break ;
        i = 0;
        while (i < N)
        {
            scanf("%d", &A[i]); // *お菓子の値段
            i++;
        }
        i = 0;
        ans = 0;
        while (i < N)
        {
            if (ans + A[i] > 300)
                i++;
            else
            {
                ans += A[i];
                i++;
            }
        }
        printf("%d\n", ans);
    }
}