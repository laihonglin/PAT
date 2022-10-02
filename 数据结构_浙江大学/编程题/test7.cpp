/**
 * author: 赖弘霖
 * date: 2022/10/2
 * topic: List Leaves(C++版本) 
 * */
#include <cstdio>
#include <queue>

using namespace std;

#define MaxTree 10
#define ElementType int
#define Tree int
#define Null -1

struct TreeNode
{
    ElementType ELement;
    Tree Left;
    Tree Right;
}T[MaxTree]; // 结构数组

Tree BuildTree(struct TreeNode T[],int N);
void PrintLeaves(Tree R,int N);

int main()
{
    int N;
    Tree R;
    scanf("%d\n",&N);
    R = BuildTree(T,N);
    PrintLeaves(R,N);
    return 0;
}

// 建树
Tree BuildTree(struct TreeNode T[],int N)
{
    int i;
    Tree root = Null; // 根结点
    int check[N];
    if(N)
    {
        for(i = 0;i < N;i++) check[i] = 0;
        for(i = 0;i < N;i++)
        {
            char cl,cr;
            scanf("%c %c\n",&cl,&cr);
            T[i].ELement = i;
            if(cl != '-')
            {
                T[i].Left = cl - '0';
                check[T[i].Left] = 1;
            }
            else T[i].Left = Null;
            if(cr != '-')
            {
                T[i].Right = cr - '0';
                check[T[i].Right] = 1;
            }
            else T[i].Right = Null;
        }
        for(i = 0;i < N;i++)
            if(!check[i]) break;
        root = i;
    }
    return root;
}

// 打印叶子结点(使用STL)层序遍历
void PrintLeaves(Tree R,int N)
{
    queue<TreeNode> q;
    int k = 0;
    int leaves[N]; // 保存叶子结点，方便格式化打印
    q.push(T[R]);
    while(!q.empty())
    {
        TreeNode t = q.front();
        q.pop();
        if(t.Left == Null && t.Right == Null) // 叶子结点 
            leaves[k++] = t.ELement;
        if(t.Left != Null) q.push(T[t.Left]);
        if(t.Right != Null) q.push(T[t.Right]);
    }
    for(int i = 0;i < k - 1;i++) printf("%d ",leaves[i]);
    printf("%d",leaves[k - 1]);
}
