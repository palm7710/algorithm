#include <stdio.h>
#include <stdlib.h>

int scoreOfString(char *s)
{
    int i;
    i = 0;
    int score = 0;
    while (s[i + 1])
    {
        score += abs(s[i] - s[i + 1]);
        i++;
    }
    return score;
}

int main()
{
    printf("%d\n",scoreOfString("hello"));
    printf("%d\n",scoreOfString("zaz"));
}