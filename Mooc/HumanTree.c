/** author: 赖弘霖
 *  date: 2022/10/13
 *  topic: 哈夫曼树 
 * */
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 1000
#define MinData -1000
int A[] = {13, 1, 45, 7, 20, 4, 19, 13, 40, 33, 38}; // 预先定义好一组权值
int A_length = 11;                                   // 定义其长度
typedef struct HeapStruct *MinHeap;
typedef struct TreeNode *HuffmanTree;
struct HeapStruct
{
    HuffmanTree *Data; //存值的数组
    int Size;          //堆的当前大小
    int Capacity;      //堆的容量
};
struct TreeNode
{
    int Weight;        //权值
    HuffmanTree Left;  //左子树
    HuffmanTree Right; //右子树
};

MinHeap create();                         // 初始化堆
HuffmanTree Create();                     // 初始化哈夫曼树
void sort(MinHeap H, int i);              // 调整子最小堆
void adjust(MinHeap H);                   // 调整最小堆
void BuildMinHeap(MinHeap H);             // 建堆
HuffmanTree Delete(MinHeap H);            // 删除最小堆元素
void Insert(MinHeap H, HuffmanTree Huff); // 插入最小堆元素
void PreOrderTraversal(HuffmanTree Huff); // 先序遍历
HuffmanTree Huffman(MinHeap H);           // 哈夫曼树的构建

MinHeap create()
{
    MinHeap H;
    HuffmanTree Huff;
    H = (MinHeap)malloc(sizeof(struct HeapStruct));
    H->Data = (HuffmanTree *)malloc(sizeof(struct TreeNode) * (MaxSize + 1));
    H->Size = 0;
    H->Capacity = MaxSize;
    // 给堆置哨兵 
    Huff = Create();
    Huff->Weight = MinData;
    H->Data[0] = Huff;
    return H;
}

HuffmanTree Create()
{
    HuffmanTree Huff;
    Huff = (HuffmanTree)malloc(sizeof(struct TreeNode));
    Huff->Weight = 0;
    Huff->Left = NULL;
    Huff->Right = NULL;
    return Huff;
}

void sort(MinHeap H, int i)
{
    int Parent, Child, Tmp;
    Tmp = H->Data[i]->Weight;// 取出当前"根结点"值
    for (Parent = i; Parent * 2 <= H->Size; Parent = Child)
    {
        Child = Parent * 2;
        if ((Child != H->Size) && (H->Data[Child]->Weight > H->Data[Child + 1]->Weight))
            Child++;
        if (Tmp <= H->Data[Child]->Weight)
            break;
        else
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent]->Weight = Tmp;
}

void adjust(MinHeap H)
{
    int i;
    for (i = H->Size / 2; i > 0; i--)
        sort(H, i);// 每个"子最小堆"调整 
}

void BuildMinHeap(MinHeap H)
{
    // 将权值读入堆中
    int i;
    HuffmanTree Huff;
    for (i = 0; i < A_length; i++)
    {
        Huff = Create();
        Huff->Weight = A[i];
        H->Data[++H->Size] = Huff;
    }
    //调整堆
    adjust(H);
}

HuffmanTree Delete(MinHeap H)
{
    int Parent, Child;
    HuffmanTree T, Tmp;
    T = H->Data[1];// 取出根结点的哈夫曼树 
    Tmp = H->Data[H->Size--];// 取出最后一个结点哈夫曼树的权值 
    for (Parent = 1; Parent * 2 <= H->Size; Parent = Child)
    {
        Child = Parent * 2;
        if ((Child != H->Size) && (H->Data[Child]->Weight > H->Data[Child + 1]->Weight))
            Child++;
        if (Tmp->Weight <= H->Data[Child]->Weight)
            break;
        else
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = Tmp;
    // 构造一个 HuffmanTree 结点，附上刚才取出来的权值，返回该结点 
    return T;
}

void Insert(MinHeap H, HuffmanTree Huff)
{
    int Weight, i;
    Weight = Huff->Weight;// 取出权值
    i = ++H->Size;
    for (; H->Data[i / 2]->Weight > Weight; i /= 2)
        H->Data[i] = H->Data[i / 2];
    H->Data[i] = Huff;
}

void PreOrderTraversal(HuffmanTree Huff)
{
    if (Huff)
    {
        printf("%d ", Huff->Weight);
        PreOrderTraversal(Huff->Left);
        PreOrderTraversal(Huff->Right);
    }
}

HuffmanTree Huffman(MinHeap H)
{
    HuffmanTree T;
    int i, times;
    BuildMinHeap(H);// 建堆 
    // 做 times-1 次合并 
    times = H->Size;
    for (i = 1; i < times; i++)
    {
        T = (HuffmanTree)malloc(sizeof(struct TreeNode));
        T->Left = Delete(H);// 从堆中删除一个结点，作为新 T 的左子结点 
        T->Right = Delete(H);// 从堆中删除一个结点，作为新 T 的右子结点 
        T->Weight = T->Left->Weight + T->Right->Weight; // 重新计算权值 
        Insert(H, T);// 再加进堆中 
    }
    T = Delete(H);
    return T;
}

int main()
{
    MinHeap H;
    HuffmanTree Huff;
    H = create();
    Huff = Huffman(H);
    PreOrderTraversal(Huff);
    return 0;
}
