struct ListNode {
    int val;
    struct ListNode *next;
};

// 最大公約数を求める関数
int gcd(int x, int y)
{
    int r;
    if (x == 0 || y == 0)
        return 0;
    while ((r = x % y) != 0)
    {
        x = y;
        y = r;
    }
    return y;
}

#include <stdlib.h>
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head)
{
    struct ListNode *cur = head;
    while (cur && cur->next)
    {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = gcd(cur->val, cur->next->val);
        newNode->next = cur->next;
        cur->next = newNode;
        cur = newNode->next;
    }
    return head;
}

#include <stdio.h>
int main()
{
    int data[] = {18, 6, 10, 3};
    int size = sizeof(data) / sizeof(int);
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    int i = 0;
    while (i < size)
    {
        struct ListNode *node = malloc(sizeof(struct ListNode));
        node->val = data[i];
        node->next = NULL;
        if (!head)
            head = node;
        else
            tail->next = node;
        tail = node;
        i++;
    }
    struct ListNode *result = insertGreatestCommonDivisors(head);

    struct ListNode *cur = result;
    while (cur)
    {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    return 0;
}