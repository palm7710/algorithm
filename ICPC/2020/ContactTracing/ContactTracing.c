#include <stdio.h>

int m, n, p; // *利用者の人数、記録の件数、感染した人のID
int a[1000], b[1000];
int ans[256]; // *感染した人のIDを格納する
int infection[256]; // *感染フラグ

int main()
{
    int i;
    int j;
    int cnt;
    j = 0;
    while(1)
    {
        scanf("%d %d %d", &m, &n, &p);
        if(m == 0 && n == 0 && p == 0)
            break;
        i = 0;
        while(i < n)
        {
            scanf("%d %d", &a[i], &b[i]);
            i++;
        }
        i = 1;
        while (i <= m)
        {
            infection[i] = 0;
            i++;
        }
        infection[p] = 1;
        // *直接または間接的に感染した人を記録する
        i = 0;
        while (i < n)
        {
            if (infection[a[i]] && !infection[b[i]])
                infection[b[i]] = 1;
            else if (infection[b[i]] && !infection[a[i]])
                infection[a[i]] = 1;
            i++;
        }
        // *感染した人のIDを格納する
        i = 1;
        cnt = 0;
        while (i <= m)
        {
            if (infection[i])
                cnt++;
            i++;
        }
        ans[j++] = cnt;
    }
    i = 0;
    while (i < j)
    {
        printf("%d\n", ans[i]);
        i++;
    }
    return 0;
}