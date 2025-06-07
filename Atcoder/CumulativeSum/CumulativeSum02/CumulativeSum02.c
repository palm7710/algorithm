#include <stdio.h>

int N, Q;
int A[256];
int sum[256];

int main()
{
    // *くじを引く数
    scanf("%d", &N);

    int i;
    i = 0;
    while (i < N)
    {
        scanf("%d", &A[i]);
        i++;
    }
    sum[0] = 0;
    i = 1;
    // *累積和の計算 O(N)
    while (i <= N)
    {
        sum[i] = sum[i - 1] + A[i - 1];
        i++;
    }
    // *質問の数
    scanf("%d", &Q);
    int L, R;
    int atari;
    int hazure;
    i = 0;
    // *LとRの範囲の和 O(Q)
    while (i < Q)
    {
        // *L~Rまでの中で考える
        scanf("%d %d", &L, &R);
        atari = sum[R] - sum[L - 1];
        hazure = (R - L + 1) - atari;
        printf("%d %d\n", atari, hazure);
        i++;
    }
    return 0;
}