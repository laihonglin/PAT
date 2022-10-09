/**
 * author: 赖弘霖
 * date: 2022/10/9
 * topic: 是否同一棵二叉搜索树 
 * */
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *Tree;
struct TreeNode
{
    int v;
    Tree Left, Right;
    int flag; //标记这个结点是否被访问过
};

Tree NewNode(int V)
{
    Tree T = (Tree)malloc(sizeof(struct TreeNode));
    T->v = V;
    T->Left = T->Right = NULL;
    T->flag = 0;
    return T;
}

//插入结点
Tree insert(Tree T, int V)
{
    if (!T)
        T = NewNode(V);
    else
    {
        if (V > T->v)
            T->Right = insert(T->Right, V);
        else
            T->Left = insert(T->Left, V);
    }
    return T;
}

//建树
Tree MakeTree(int N)
{
    Tree T;
    int i, V;
    scanf("%d", &V);
    T = NewNode(V); //构造根结点
    for (int i = 1; i < N; i++)
    {
        scanf("%d", &V);
        T = insert(T, V);
    }
    return T;
}

int check(Tree T, int V)
{
    if (T->flag) //如果已经被标记
    {
        if (V < T->v)
            check(T->Left, V);
        else if (V > T->v)
            check(T->Right, V);
        else
            return 0;
    }
    else //未被标记
    {
        if (V == T->v)
        {
            T->flag = 1;
            return 1;
        }
        else
            return 0;
    }
}

int Judge(Tree T, int N)
{
    int i, V, flag = 0;
    scanf("%d", &V);
    if (V != T->v)
        flag = 1; // flag：0代表目前还一致，1代表已经不一致
    else
        T->flag = 1;
    for (i = 1; i < N; i++)
    {
        scanf("%d", &V);
        if ((!flag) && (!check(T, V)))
            flag = 1;
    }
    if (flag)
        return 0;
    else
        return 1;
}

void ResetT(Tree T)
{
    if(T->Left) ResetT(T->Left);
    if(T->Right) ResetT(T->Right);
    T->flag = 0;
}

void FreeTree(Tree T)
{
    if(T->Left) FreeTree(T->Left);
    if(T->Right) FreeTree(T->Right);
    free(T);
}

int main()
{
    int N, L, i;
    Tree T;

    scanf("%d", &N);
    while (N)
    {
        scanf("%d", &L);
        T = MakeTree(N);
        for (i = 0; i < L; i++)
        {
            if (Judge(T, N))
                printf("Yes\n");
            else
                printf("No\n");
            ResetT(T); //清楚T中的标记flag
        }
        FreeTree(T);
        scanf("%d", &N);
    }
    return 0;
}
