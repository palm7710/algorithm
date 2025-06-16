#include <stdio.h>
#include <stdlib.h> // qsort用

int N, A[100000];
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b; //小さい順（昇順）にソート
}

int main()
{
    int i;
    scanf("%d", &N);
    i = 1;
    while (i <= N)
    {
        scanf("%d", &A[i]);
        i++;
    }
    // A[L] から A[R - 1]までの部分をソートする
    qsort(A + 1, N, sizeof(int), cmp);
    i = 1;
    while (i <= N)
    {
        printf("%d ", A[i]);
        i++;
    }
}