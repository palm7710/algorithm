#include <stdio.h>

int N, A[256], S[256];
int Q, L[256], R[256];

int main()
{
    scanf("%d %d", &N, &Q);

    int i;
    i = 0;
    // *Aの配列を入力用
    while (i < N)
    {
        scanf("%d", &A[i]);
        i++;
    }
    int j;
    j = 0;
    // *LとRを入力用
    while (j < Q)
    {
        scanf("%d %d", &L[j], &R[j]);
        j++;
    }
    S[0] = 0; // *初期化 O(1)
    i = 1;
    // *累積和の計算
    while(i <= N)
    {
        S[i] = S[i - 1] + A[i - 1];
        i++;
    }
    j = 0;
    // *LとRの範囲の和を出力 O(Q)
    while (j < Q)
    {
        printf("%d\n", S[R[j]] - S[L[j] - 1]);
        j++;
    }
    return 0;
}