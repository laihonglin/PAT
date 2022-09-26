/*
 * author: 赖弘霖
 * date: 2022/9/26
 * topic: 一元多项式的乘法与加法运算
 * */

#include <stdio.h>
#include <stdlib.h>

struct PolyNode
{
    int coef; // 系数
    int expon; // 指数
    struct PolyNode *link; // 指向下一个节点的指针
};

typedef struct PolyNode *Polynomial;
Polynomial P1,P2;

int Compare(int e1,int e2)
{
    if(e1 > e2) return 1;
    else if(e1 < e2) return -1;
    else return 0;
}

void Attach(int c,int e,Polynomial *pRear)
{
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = c;
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P;
    *pRear = P;
}

// 读入函数
Polynomial ReadPoly()
{
    Polynomial P,rear,t;
    int c,e,n;
    scanf("%d",&n);
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    rear = P;
    while(n--)
    {
        scanf("%d %d", &c, &e);
        if(c != 0) Attach(c,e,&rear);
    }
    t = P;
    P = P->link;
    free(t);
    return P;
}

// 输出函数
void PrintPoly(Polynomial P)
{
    int flag = 0; // 调整输出格式
    if(!P)
    {
        printf("0 0\n");
        return;
    }
    while(P)
    {
        if(!flag) flag = 1;
        else printf(" ");
        printf("%d %d",P->coef,P->expon);
        P = P->link;
    }
    printf("\n");
}

// 多项式相乘
Polynomial PolyMult(Polynomial P1,Polynomial P2)
{
    Polynomial P,rear,t1,t2,t;
    int c,e;
    if(!P1 || !P2) return NULL;
    t1 = P1,t2 = P2;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    rear = P;
    while(t2)
    {
        // 先用P1的第一项乘以P2,得到初始结果多项式
        Attach(t1->coef * t2->coef,t1->expon + t2->expon,&rear);
        t2 = t2->link;
    }
    t1 = t1->link;
    while(t1)
    {
        t2 = P2,rear = P; // 将尾节点置到头结点来
        while(t2)
        {
            c = t1->coef * t2->coef;
            e = t1->expon + t2->expon;
            while(rear->link && rear->link->expon > e)
                rear = rear->link;
            if(rear->link && rear->link->expon == e)
            {
                if(rear->link->coef + c) rear->link->coef += c; //判系数是否为0
                else // 为0删除节点
                {
                    t = rear->link;
                    rear->link = t->link;
                    free(t);
                }
            }
            else // 插入位置
            {
                t = (Polynomial)malloc(sizeof(struct PolyNode));
                t->coef = c;
                t->expon = e;
                t->link = rear->link;
                rear->link = t;
                rear = rear->link;
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }
    t2 = P;
    P = P->link;
    free(t2);
    return P;
}

// 多项式相加
Polynomial PolyAdd(Polynomial P1,Polynomial P2)
{
    Polynomial front,rear,temp;
    int sum;
    rear = (Polynomial)malloc(sizeof(struct PolyNode));
    front = rear;
    while(P1 && P2)
    {
        switch(Compare(P1->expon,P2->expon))
        {
            case 1:
                Attach(P1->coef,P1->expon,&rear);
                P1 = P1->link;
                break;
            case -1:
                Attach(P2->coef,P2->expon,&rear);
                P2 = P2->link;
                break;
            case 0: 
                sum = P1->coef + P2->coef;
                if(sum) Attach(sum,P1->expon,&rear); // 系数不为0时添加到尾节点
                P1 = P1->link;
                P2 = P2->link;
                break;
        }
    }
    for(;P1;P1 = P1->link) Attach(P1->coef,P1->expon,&rear);
    for(;P2;P2 = P2->link) Attach(P2->coef,P2->expon,&rear);
    rear->link = NULL;
    temp = front;
    front = front->link;
    free(temp);
    return front;
}

// 主函数
int main()
{
    Polynomial P1, P2, PP, PS;
    P1 = ReadPoly();
    P2 = ReadPoly();
    PP = PolyMult(P1,P2);
    PS = PolyAdd(P1,P2);
    PrintPoly(PP);
    PrintPoly(PS);
    return 0;
}

