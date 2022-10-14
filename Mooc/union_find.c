#include <stdio.h>
#define MaxSize 1000     /* 集合最大元素个数 */
typedef int ElementType; /* 默认元素可以用非负整数表示 */
typedef struct
{
    ElementType Data; //存值
    int Parent;       //指向父结点
} SetType;

// 查找
int Find(SetType S[], ElementType X)
{
    int i;
    // 找到数组中该值对应的下标
    for (i = 0; i < MaxSize && S[i].Data != X; i++);
    if (i > MaxSize) // 如果没有找到，返回 -1
        return -1;
    // 找到该结点的根结点
    for (; S[i].Parent >= 0; i = S[i].Parent);
    return i;
}

// 并
void Union(SetType S[], ElementType X1, ElementType X2)
{
    int Root1 = Find(S, X1);
    int Root2 = Find(S, X2);
    // 如果根结点的下标不同，说明不是一个集合
    if (Root1 != Root2)
        S[Root1].Parent = Root2; // 把 x1 挂到 x2 的集合
}

int main()
{
    SetType S[MaxSize];
    // 初始化数组，父结点全部指向 -1
    for (int i = 0; i < MaxSize; i++)
    {
        S[i].Data = i + 1;
        S[i].Parent = -1;
    }
    printf("%d\n",Find(S,5));
    Union(S, 3, 5);
    printf("%d\n",Find(S,4));
    printf("%d\n",Find(S,3));
    Union(S, 1, 3);
    Union(S, 2, 4);
    Union(S, 8, 6);
    printf("%d\n",Find(S,6));
    printf("%d\n",Find(S,8));
    return 0;
}

