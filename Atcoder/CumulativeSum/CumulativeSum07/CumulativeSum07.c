#include <stdio.h>

int H, W, N; // *マス目と日数
int A[100000], B[100000], C[100000], D[100000]; //*マス目(i,j)の座標
int X[1500][1500], Z[1500][1500];

int main() {
    int t;
    int i;
    int j;
    scanf("%d %d %d", &H, &W, &N);
    t = 1;
    while (t <= N)
    {
        scanf("%d %d %d %d", &A[t], &B[t], &C[t], &D[t]);
        t++;
    }
    t = 1;
    // *差分配列
    while (t <= N)
    {
        X[A[t]][B[t]] += 1; // *A[t]行B[t]列
        X[A[t]][D[t] + 1] -= 1; // *A[t]行D[t] + 1列
        X[C[t] + 1][B[t]] -= 1; // *C[t] + 1行B[t]列
        X[C[t] + 1][D[t] + 1] += 1; // *C[t] + 1行D[t] + 1列
        t++;
    }

    // *初期化
    i = 0;
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
    // *累積和
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
    i = 1;
    while (i <= H)
    {
        j = 1;
        while (j <= W)
        {
            if (j >= 2)
                printf(" ");
            printf("%d", Z[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}