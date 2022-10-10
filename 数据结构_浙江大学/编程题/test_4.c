/**
 * author: 赖弘霖
 * date: 2022/10/10
 * topic: Reversing Linked List 
 * */
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100005

typedef struct LNode *PtrToLNode;
struct LNode
{
    int Address;
    int Data;
    int NAddress;
    PtrToLNode Next;
};
typedef PtrToLNode List;

/*反转链表模版*/
List Reverse(List head, int K)
{
    int cnt = 1;
    List new, old, tmp;
    new = head->Next;
    old = new->Next;
    while (cnt < K)
    {
        tmp = old->Next;
        old->Next = new;
        old->NAddress = new->Address;
        new = old;
        old = tmp;
        cnt++;
    }
    head->Next->Next = old;
    if (old != NULL)
        head->Next->NAddress = old->Address;
    else
        head->Next->NAddress = -1;
    return new;
}

int main()
{
    int FirstAdd, N, K;
    int i, j, tmp, num;
    num = 0;
    int data[MaxSize];
    int next[MaxSize];
    List L, p, q;
    scanf("%d %d %d", &FirstAdd, &N, &K);
    L = (List)malloc(sizeof(struct LNode)); //构造一个空结点，没任何意义(个人习惯)
    L->NAddress = FirstAdd;
    q = L;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &tmp);
        scanf("%d %d", &data[tmp], &next[tmp]);
    }
    i = 1;
    while (1) /*构建链表(不一定为N个结点)*/
    {
        if (q->NAddress == -1)
        {
            q->Next = NULL;
            num = i - 1;
            break;
        }
        p = (List)malloc(sizeof(struct LNode));
        p->Address = q->NAddress;
        p->Data = data[q->NAddress];
        p->NAddress = next[q->NAddress];
        q->Next = p;
        q = p;
        i++;
    }
    List rp, t; /*rp为反转后返回的根结点*/
    rp = NULL;
    t = L;
    if (K <= num) /*按每K个结点(只有K<=num才需要反转)*/
    {
        for (i = 0; i < (num / K); i++)
        {
            rp = Reverse(t, K);
            t->Next = rp;
            t->NAddress = rp->Address;
            j = 0;
            while (j < K)
            {
                t = t->Next;
                j++;
            }
        }
    }
    while (L->Next)
    {
        L = L->Next;
        if (L->NAddress == -1)
            printf("%.5d %d %d\n", L->Address, L->Data, L->NAddress);
        else
            printf("%.5d %d %.5d\n", L->Address, L->Data, L->NAddress);
    }
    return 0;
}
