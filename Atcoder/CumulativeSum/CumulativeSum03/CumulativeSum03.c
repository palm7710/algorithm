#include <stdio.h>

int N, L[256], R[256]; // *人数と期間
int D, B[256]; // *日数と差分配列
int ans[256]; // *各日にちの参加人数

int main(void)
{
    scanf("%d", &D);
    scanf("%d", &N);

    int i;
    i = 0;
    // *1と-1だけでマークする O(N)
    while (i < N)
    {
        scanf("%d %d", &L[i], &R[i]);
        B[L[i] - 1] += 1; // *L[i]の前日比を足す
        B[R[i] - 1] -= 1; // *R[i]の前日比を引く
        i++;
    }
    ans[0] = 0;
    i = 1;
    // *O(D)
    while (i < D)
    {
        ans[i] = ans[i - 1] + B[i - 1];
        printf("%d\n", ans[i]);
        i++;
    }
    return 0;
}

