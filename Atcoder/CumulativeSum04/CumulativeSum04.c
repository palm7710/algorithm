#include <stdio.h>

int T; // *閉店時間
int N; // *従業員の人数
int L[256], R[256]; // *出勤と退勤時間
int diff[256]; // *差分配列
int ans[256]; // *各時間帯の人数

int main()
{
    scanf("%d", &T);
    scanf("%d", &N);

    int i;
    i = 0;
    while (i < N)
    {
        scanf("%d %d", &L[i], &R[i]);
        diff[L[i]] += 1; // *出勤時間の前日比を足す
        diff[R[i]] -= 1; // *退勤時間の前日比を引く
        i++;
    }
    ans[0] = diff[0];
    int t;
    t = 1; // *時刻における人数
    while (t <= T)
    {
        ans[t] = ans[t - 1] + diff[t];
        t++;
    }
    t = 0;
    while (t < T)
    {
        printf("%d\n", ans[t]);
        t++;
    }
    return 0;
}