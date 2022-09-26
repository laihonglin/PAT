/*
 * author: 赖弘霖
 * date: 2022/9/26
 * topic: 两个有序链表序列的合并
 * */

List Merge( List L1, List L2 )
{
    if(!L1 && !L2) return NULL;
    List p = L1->Next,q = L2->Next;
    List L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    List rear = L; // 代表链表最后一个节点 
    while(p != NULL && q != NULL)
    {
        if(p->Data <= q->Data) // L1比L2小
        {
            rear->Next = p;
            p = p->Next;
        }
        else // L1比L2大
        {
            rear->Next = q;
            q = q->Next;
        }
        rear = rear->Next;
    }
    if(p) rear->Next = p; // 将L1剩余节点加入L
    if(q) rear->Next = q; // 将L2剩余节点加入L;
    L1->Next = NULL;
    L2->Next = NULL;
    return L;
}
