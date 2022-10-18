/**
 * author: 赖弘霖
 * date: 2022/10/18
 * topic: File Transfer
 * */
#include <stdio.h>
#define MaxSize 10001
typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MaxSize];

void Initiaiization(SetType S,int n)
{
    int i;
    for(i = 0;i < n;i++) S[i] = -1;
}

SetName Find(SetType S,ElementType X)
{
    for(;S[X] >= 0;X = S[X]);
    return X;
}

void Union(SetType S,SetName Root1,SetName Root2)
{
    if(S[Root2] < S[Root1])
        S[Root1] = Root2;
    else
    {
        if(S[Root1] == S[Root2]) S[Root1]--;
        S[Root2] = Root1;
    }
}

void Input_connection(SetType S)
{
    ElementType u,v;
    SetName Root1,Root2;
    scanf("%d %d\n",&u,&v);
    Root1 = Find(S,u - 1);
    Root2 = Find(S,v - 1);
    if(Root1 != Root2)
        Union(S,Root1,Root2);
}

void Check_connection(SetType S)
{
    ElementType u,v;
    SetName Root1,Root2;
    scanf("%d %d\n",&u,&v);
    Root1 = Find(S,u - 1);
    Root2 = Find(S,v - 1);
    if(Root1 == Root2)
        printf("yes\n");
    else
        printf("no\n");
}

void Check_network(SetType S,int n)
{
    int i,cnt = 0;
    for(i = 0;i < n;i++)
    {
        if(S[i] < 0) cnt++;
    }
    if(cnt == 1)
        printf("The network is connected.");
    else
        printf( "There are %d components.", cnt);
}

int main()
{
    SetType S;
    int n;
    char in;
    scanf("%d",&n);
    Initiaiization(S,n);
    do{
        scanf("%c",&in);
        switch(in){
            case 'I':Input_connection(S);break;
            case 'C':Check_connection(S);break;
            case 'S':Check_network(S,n);break;
        }
    }while(in != 'S');
    return 0;
}
