#include <stdio.h>
int N, X, A[100000];

int search(int x)
{
    int L;
    int R;
    int M;

    L = 1;
    R = N;
    while (L <= R)
    {
        M = (L + R) / 2; // 中央のインデックスを計算
        if (X < A[M])
            R = M - 1; // 右側を切り捨てる
        if (X == A[M])
            return M; // Found
        if (X > A[M])
            L = M + 1; // 左側を切り捨てる
    }
    return -1; // Not found
}

int main()
{
    int i;
    int ans;
    scanf("%d %d", &N, &X);
    i = 1;
    while (i <= N)
    {
        scanf("%d", &A[i]);
        i++;
    }
    ans = search(X);
    printf("%d\n", ans);
}