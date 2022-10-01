/*
 * author: 赖弘霖
 * date: 2022/10/1
 * topic: 二叉树的遍历 
 * */

#define ElementType int
typedef struct TreeNode *BinTree;
struct TreeNode
{
    BinTree Left;
    BinTree Right;
    ElementType Data;
};

// 中序遍历(递归)
void InorderTraversal( BinTree BT )
{
    if( BT ) {
        InorderTraversal( BT->Left );
        /* 此处假设对BT结点的访问就是打印数据 */
        printf("%d ", BT->Data); /* 假设数据为整型 */
        InorderTraversal( BT->Right );
    }
}

// 中序遍历(非递归)
void InOrderTraversal(BinTree BT)
{
    BinTree T = BT;
    Stack S = CreakStack(MaxSize); // 创建并初始化栈S
    while(T || !IsEmpty(S))
    {
        while(T) // 一直向左并把沿途结点压入栈
        {
            Push(S,T);
            T = T->Left;
        }
        if(!IsEmpty(S))
        {
            T = Pop(S); // 结点弹出堆栈
            printf("%5d",T->Data); // 访问结点
            T = T->Right; // 转向右子树
        }
    }
}

// 先序遍历(递归)
void PreorderTraversal( BinTree BT )
{
    if( BT ) {
        printf("%d ", BT->Data );
        PreorderTraversal( BT->Left );
        PreorderTraversal( BT->Right );
    }
}

// 先序遍历(非递归)
void PreOrderTraversal(BinTree BT)
{
    BinTree T = BT;
    Stack S = CreatStack(Maxsize); // 创建并初始化堆栈S
    while(T || !IsEmpty(S))
    {
        while(T) // 一直向左并将沿途结点压入堆栈
        {
            printf("%5d",T->Data); // 访问结点
            Push(S,T);
            T = T->Left;
        }
        if(!IsEmpty(S))
        {
            T = Pop(S); // 结点弹出堆栈
            T = T->Right; // 转向右子树
        }
    }
}

// 后序遍历(递归)
void PostorderTraversal( BinTree BT )
{
    if( BT ) {
        PostorderTraversal( BT->Left );
        PostorderTraversal( BT->Right );
        printf("%d ", BT->Data);
    }
}

// 后序遍历(非递归)
// 将先序遍历的左右子顺序倒置后，逆序将输出结果
void PostOrderTreaversal(BinTree BT)
{
    BinTree T = BT;
    Stack TS = CreatStack(MaxSize); // 创建并初始化堆栈S
    Stack TSR = CreatStack(MaxSize); // 保存结果用于逆序输出的堆栈TS
    while(T || !IsEmpty(TS))
    {
        while(T)
        {
            Push(TS,T);
            Push(TSR,T);
            T = T->Right;
        }
        if(!IsEmpty(TS))
        {
            T = Pop(TS);
            T = T->Left;
        }
    }
    while(!IsEmpty(TSR))
    {
        T = Pop(TSR);
        printf("%5d",T->Data);
    }
}

// 层序遍历
void LevelOrderTraversal(BinTree BT)
{
    Queue Q;
    BinTree T;
    if(!BT) return; // 为空树直接返回
    Q = CreakQueue(MaxSize); // 创建并初始化队列
    AddQ(Q,BT);
    while(!IsEmpty(Q))
    {
        T = Delete(Q);
        printf("%d\n",T->Data); // 访问取出队列的结点
        if(T->Left) AddQ(Q,T->Left);
        if(T->Right) AddQ(Q,T->Right);
    }
}



