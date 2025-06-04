#include <stdio.h>
#include <stdlib.h>

unsigned long long P; // *荷物の体積
unsigned long long W, D, H; // *荷物の幅, 奥行き, 高さ
unsigned long long S; // *W ＋ D + H　の合計
unsigned long long ans[256];

typedef struct s_luggage
{
    unsigned long long p;
    unsigned long long min_sum;
    struct s_luggage *next;
} t_luggage;

int main()
{
    // *P = W x D x H となる数と見つけて、
    // *S = W + D + H の最小値を求める
    t_luggage *head = NULL;
    t_luggage *current = NULL;
    unsigned long long minS;
    unsigned long long rest; // *D × H = PDを満たすようなD, Hを求めるための変数
    while (1)
    {
        t_luggage *new_node = (t_luggage *)malloc(sizeof(t_luggage));
        if (new_node == NULL)
            return 0;
        scanf("%llu", &new_node->p);
        if (new_node->p == 0)
        {
            free(new_node);
            break;
        }
        new_node->min_sum = 0;
        new_node->next = NULL;
        if (head == NULL)
        {
            head = new_node;
            current = head;
        }
        else
        {
            current->next = new_node;
            current = new_node;
        }
    }
    t_luggage *temp = head;
    while (temp != NULL)
    {
        P = temp->p;
        minS = 9223372036854775807;
        W = 1;
        while (W * W * W <= P)
        {
            if (P % W == 0)
            {
                rest = P / W;
                D = 0;
                while (D * D <= rest)
                {
                    if (rest % D == 0)
                    {
                        H = rest / D; // * H = PD / D によって求まる
                        S = W + D + H;
                        if (S < minS)
                        {
                            minS = S;
                        }
                        if (D == 0 || H == 0 || W * D * H > P)
                            break;
                        if (W * D * H == P && S < minS)
                        {
                            minS = S;
                        }
                    }
                    D++;
                }
            }
            W++;
        }
        temp->min_sum = minS;
        temp = temp->next;
    }
    current = head;
    int i = 0;
    while (current != NULL)
    {
        ans[i++] = current->min_sum;
        current = current->next;
    }

    current = head;
    int j = 0;
    while (j < i)
    {
        printf("%llu\n", ans[j]);
        j++;
    }
    current = head;
    while (current != NULL)
    {
        t_luggage *temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
}