#include <stdio.h>

int n; // *整数の個数
int d[1000]; // *整数の配列
int ans[256]; // *結果を格納する

int main()
{
    int i;
    int j;
    int cnt;
    j = 0;
    while (1)
    {
        scanf("%d", &n);
        // *入力の終わりは0を入力する
        if (n == 0)
            break;
        i = 0;
        while (i < n)
        {
            scanf("%d", &d[i]);
            i++;
        }
        i = 0;
        cnt = 0;
        // * 2,0,2,0 のパターンを数える
        while (i < n - 3)
        {
            if (d[i] == 2 && d[i + 1] == 0 && d[i + 2] == 2 && d[i + 3] == 0)
                cnt++;
            i++;
        }
        ans[j++] = cnt;
    }
    i = 0;
    while(i < j)
    {
        printf("%d\n", ans[i]);
        i++;
    }
    return 0;
}