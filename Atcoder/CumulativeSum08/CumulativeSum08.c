#include <stdio.h>

int N; // *紙の数
int x, y; // *長方形の紙の座標
int A[1500], B[1500], C[1500], D[1500]; // *紙の座標
int X[1500][1500], Z[1500][1500]; // *差分配列と累積和

int main() {
    int t;
    int i, j;
    scanf("%d", &N);
    scanf("%d %d", &x, &y);
    t = 1;
    while (t <= N) {
        scanf("%d %d %d %d", &A[t], &B[t], &C[t], &D[t]);
        t++;
    }
    t = 1;
    // *差分配列
    while (t <= N) {
        X[A[t]][B[t]] += 1; // *A[t]行B[t]列
        X[A[t]][D[t] + 1] -= 1; // *A[t]行D[t] + 1列
        X[C[t] + 1][B[t]] -= 1; // *C[t] + 1行B[t]列
        X[C[t] + 1][D[t] + 1] += 1; // *C[t] + 1行D[t] + 1列
        t++;
    }
    // *初期化
    i = 0;
    while (i <= x) {
        j = 0;
        while (j <= y) {
            Z[i][j] = 0;
            j++;
        }
        i++;
    }
    // *累積和
    i = 1;
    while (i <= x) {
        j = 1;
        while (j <= y) {
            Z[i][j] = Z[i][j - 1] + X[i][j];
            j++;
        }
        i++;
    }
    j = 1;
    while (j <= y) {
        i = 1;
        while (i <= x) {
            Z[i][j] = Z[i - 1][j] + Z[i][j];
            i++;
        }
        j++;
    }
    // *出力
    i = 1;
    while (i <= x) {
        j = 1;
        while (j <= y) {
            printf("%d ", Z[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}
