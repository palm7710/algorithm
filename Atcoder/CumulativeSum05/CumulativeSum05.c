#include <stdio.h>

int H, W, Q; // *HxWのマス目と質問の数
int X[1500][1500], Z[1500][1500]; // *マス目の位置を表す整数と二次元の累積和
int A[100000], B[100000], C[100000], D[100000]; // *長方形領域

int main()
{
    scanf("%d %d", &H, &W);

    int i;
    int j;
    i = 1;
    while (i <= H)
    {
        j = 1;
        while (j <= W)
        {
            scanf("%d", &X[i][j]);
            j++;
        }
        i++;
    }
    scanf("%d", &Q);
    i = 1;
    while (i <= Q)
    {
        scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
        i++;
    }
    i = 0;
    // *二次元配列の初期化
    while (i <= H)
    {
        j = 0;
        while (j <= W)
        {
            Z[i][j] = 0;
            j++;
        }
        i++;
    }
    // *横の累積和
    i = 1;
    while (i <= H)
    {
        j = 1;
        while (j <= W)
        {
            Z[i][j] = Z[i][j - 1] + X[i][j];
            j++;
        }
        i++;
    }
    // *縦の累積和
    j = 1;
    while (j <= W)
    {
        i = 1;
        while (i <= H)
        {
            Z[i][j] = Z[i - 1][j] + Z[i][j];
            i++;
        }
        j++;
    }
    int result;
    i = 1;
    while (i <= Q)
    {
        // *整数の総和
        result = Z[C[i]][D[i]] - Z[A[i] - 1][D[i]] - Z[C[i]][B[i] - 1] + Z[A[i] - 1][B[i] - 1];
        printf("%d\n", result);
        i++;
    }
    return 0;
}