/**
 * author: 赖弘霖
 * date: 2022/10/2
 * topic: 树的同构
 * */
#include <stdio.h>

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;
}T1[MaxTree],T2[MaxTree]; // 结构数组

Tree BuildTree(struct TreeNode T[]);
int Isomorphic(Tree R1,Tree R2);

int main()
{
    Tree R1,R2;
    R1 = BuildTree(T1);
    R2 = BuildTree(T2);
    if(Isomorphic(R1,R2)) printf("Yes\n");
    else printf("No\n");
    return 0;
}

// 建树
Tree BuildTree(struct TreeNode T[])
{
    int i,N;
    Tree Root = Null;
    scanf("%d\n",&N); // 必须加上\n，防止后面读入回车符
    int check[N]; // 用于选出根结点
    if(N)
    {
        for(i = 0;i < N;i++) check[i] = 0;
        for(i = 0;i < N;i++)
        {
            char cl,cr;
            scanf("%c %c %c\n",&T[i].Element,&cl,&cr);
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
        Root = i;
    }
    return Root;
}

/*判断两棵树是否同构，因为树是同归递归定义的，所以我们很自然的可能就会想到通过递归判断树是否同构，即递归的判断根的子树是否同构
判断树是否同构有以下几种情况：
1：两树均为空树时，我们认为是同构的-->return 1;
2：一棵树为空，一棵树不空，两树不同构-->return 0;
3：两棵树均不空，但是两树的根的键值(关键值)不同，显然这两棵树也是不同构的-->return 0;
4：两棵树的左子树均为空树时，显然只需要判断两树的右子树是否同构即可。-->return (Isomorphic(R1->left,R2->left))
5：两颗树的左子树均不空时，并且两树的左子树的键值相同时，显然需要判断其做左子树是否同构，还要判断其右子树是否同构
6：剩下的所有情况都可以归为判断其左子树与另一棵树的右子树是否同构，其右子树与另一棵树的左子树是否同构
进一步解释：
其实情况五包含了多种情况，左子树均不空且左子树的键值相等时，显然时两颗树的左子树与左子树判断，而此时我们不需要去考虑右子树的情况，因为右子树的情况在对右子树调用Isomorphic函数
判断是否同构时会对右子树存在与否的各种情况进行判断。而如果没有满足条件五的情况，那就说明，可能时一棵树有左子树，一棵树没有左子树，那么这种情况想要
两棵树同构，就只能对左子树和右子树判断是否同构，还有可能时两个左子树均不空，但是两个左子树的键值不等，那就和上面的情况一样了，只能对左子树和右子树进行判断
是否同构，因为根键值不等，这两颗树肯定不同构
条件四其实也包含了比较多种情况，显然的就是，左子树均空时，其右子树会存在多种情况，比如右子树均空，一个空，均不空....但是右子树的情况不需要我们去考虑，因为
在调用Isomorphic函数的时候，会对这些情况进行判断。
*/
int Isomorphic(Tree R1,Tree R2)
{
    if((R1 == Null) && (R2 == Null)) return 1;
    if(((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null))) return 0;
    if(T1[R1].Element != T2[R2].Element) return 0;
    if((T1[R1].Left == Null) && (T2[R2].Left == Null))
        return Isomorphic(T1[R1].Right,T2[R2].Right);
    if(((T1[R1].Left != Null) && (T2[R2].Left != Null)) && ((T1[T1[R1].Left].Element) == T2[T2[R2].Left].Element))
        return (Isomorphic(T1[R1].Left,T2[R2].Left) && Isomorphic(T1[R1].Right,T2[R2].Right));
    else
        return (Isomorphic(T1[R1].Left,T2[R2].Right) && Isomorphic(T1[R1].Right,T2[R2].Left));
}
