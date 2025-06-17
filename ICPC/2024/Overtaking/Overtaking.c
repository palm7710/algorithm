#include <stdio.h>

int N;
int A[1000], B[1000];

int main()
{
    int i;
    int count;
    int scoreA;
    int scoreB;
    int flag;
    int prev;
    while (1)
    {
        scanf("%d", &N);
        if (N == 0)
            break ;
        i = 0;
        while (i < N)
        {
            scanf("%d", &A[i]);
            i++;
        }
        i = 0;
        while (i < N)
        {
            scanf("%d", &B[i]);
            i++;
        }
        i = 0;
        count = 0;
        scoreA = 0;
        scoreB = 0;
        flag = 0;
        prev = -1;
        while (i < N)
        {
            scoreA += A[i];
            scoreB += B[i];
            if (scoreA > scoreB)
                flag = 0;
            else if (scoreA < scoreB)
                flag = 1;
            else
                flag = -1;
            if (flag != -1)
            {
                if(prev != -1 && flag != -1 && prev != flag)
                    count++;
                prev = flag;
            }
            i++;
        }
        printf("%d\n", count);
    }
    return 0;
}