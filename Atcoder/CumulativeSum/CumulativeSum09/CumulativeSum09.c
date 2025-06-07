#include <stdio.h>

int N; //*部屋の数
int A[100]; //*人部屋
int D; //*日間工事
int L[100000], R[100000]; // *部屋の範囲
int P[100000], Q[100000]; // *部屋の累積和

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int i;
    scanf("%d", &N);
    i = 1;
    while (i <= N) {
        scanf("%d", &A[i]);
        i++;
    }
    scanf("%d", &D);
    i = 1;
    while (i <= D) {
        scanf("%d %d", &L[i], &R[i]);
        i++;
    }
    P[1] = A[1];
    i = 2;
    while (i <= N) {
        P[i] = max(P[i - 1], A[i]);
        i++;
    }
    Q[N] = A[N];
    i = N - 1;
    while (i >= 1) {
        Q[i] = max(Q[i + 1], A[i]);
        i--;
    }
    i = 1;
    while (i <= D) {
        printf("%d\n", max(P[L[i] - 1], Q[R[i] + 1]));
        i++;
    }
    return 0;
}