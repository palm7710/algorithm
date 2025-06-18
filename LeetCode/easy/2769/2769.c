#include <stdio.h>

int theMaximumAchievableX(int num, int t)
{
    int x = num + t * 2;
    return x;
}

int main()
{
    printf("%d\n", theMaximumAchievableX(4, 1));
    printf("%d\n", theMaximumAchievableX(3, 2));
}