#include <stdio.h>
int N, X, A[100000];

int lower_bound(int *arr, int left, int right, int x)
{
    int mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (arr[mid] < x)
            left = mid + 1; // 左側を切り捨てる
        else
            right = mid; // 右側を切り捨てる
    }
    return left;
}

int search(int x)
{
    int pos;
    // A[1]からA[N]までの範囲でx以上の最小の位置を探す
    pos = lower_bound(A, 1, N + 1, x); // [1, N]
    if (pos <= N && A[pos] == x)
        return pos; // Found
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