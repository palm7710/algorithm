#include <stdio.h>

int N, Q; // *点の数と質問の数
int X[100000], Y[100000]; // *座標X,Y
int A[100000], B[100000], C[100000], D[100000]; // *点の範囲

int sum[1500][1500]; // *各座標にある点の数
int ans[1500][1500]; // *二次元の累積和

int main()
{
    int i;
    int j;
    int result;
    scanf("%d", &N);
    i = 1;
    while (i <= N)
    {
        scanf("%d %d", &X[i], &Y[i]);
        i++;
    }
    scanf("%d", &Q);
    i = 1;
    while (i <= Q)
    {
        scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
        i++;
    }
    i = 1;
    // *点を数える
    while (i <= N)
    {
        sum[X[i]][Y[i]]++;
        i++;
    }
    // *累積和の初期化
    i = 0;
    while (i <= 1500)
    {
        j = 0;
        while (j <= 1500)
        {
            ans[i][j] = 0;
            j++;
        }
        i++;
    }
    // *横の累積和
    i = 1;
    while (i <= 1500)
    {
        j = 1;
        while (j <= 1500)
        {
            ans[i][j] = ans[i][j - 1] + sum[i][j];
            j++;
        }
        i++;
    }
    // *縦の累積和
    j = 1;
    while (j <= 1500)
    {
        i = 1;
        while (i <= 1500)
        {
            ans[i][j] += ans[i - 1][j];
            i++;
        }
        j++;
    }
    i = 1;
    while (i <= Q)
    {
        result = ans[C[i]][D[i]] - ans[A[i] - 1][D[i]] - ans[C[i]][B[i] - 1] + ans[A[i] - 1][B[i] - 1];
        printf("%d\n", result);
        i++;
    }
    return 0;
}