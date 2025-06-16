#include <stdio.h>

int N, K;
int A[100000], R[100000];

int main()
{
    int i;
    long long ans;
    scanf("%d %d", &N, &K);

    i = 1;
    while (i <= N)
    {
        scanf("%d", &A[i]);
        i++;
    }
    i = 1;
    // R はA[i] + K を満たす最大のインデックス
    while (i < N)
    {
        if (i == 1)
            R[i] = 1;
        else
            R[i] = R[i - 1];
        while (R[i] < N && A[R[i] + 1] - A[i] <= K)
            R[i]++;
        // printf("R[%d] = %d\n", i, R[i]);
        i++;
    }
    ans = 0;
    i = 1;
    while (i < N)
    {
        // printf("ans[%d] = %lld + %d\n", i, ans, R[i] - i);
        ans += (R[i] - i);
        i++;
    }
    printf("%lld\n", ans);
}