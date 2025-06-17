#include <stdio.h>

int N;
int x, y;

int max(int a, int b, int c)
{
    if (a < b)
        a = b;
    if (a < c)
        a = c;
    return a;
}

int main()
{
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d %d", &x, &y);
        int dx = x;
        int dy = y;
        int dz = -x - y; // *z座標は -x - y で計算する

        if (dx < 0)
            dx = -dx;
        if (dy < 0)
            dy = -dy;
        if (dz < 0)
            dz = -dz;

        int step = max(dx, dy, dz);
        printf("%d\n", step);
    }
    return 0;
}