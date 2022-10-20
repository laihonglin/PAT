/** author: 赖弘霖
 *  date: 2022/10/20
 *  topic: 图的存储(邻接矩阵) 
 * */
#include <stdio.h>
#define MAXN 100
int G[MAXN][MAXN],Nv,Ne;

//建图
void BuildGraph()
{
    int i,j,v1,v2,w;
    scanf("%d",&Nv);
    for(i = 0;i < Nv;i++)
        for(j = 0;j < Nv;j++)
            G[i][j] = 0;
    scanf("%d",&Ne);
    for(i = 0;i < Ne;i++)
    {
        scanf("%d %d %d",&v1,&v2,&w);
        G[v1][v2] = w;
        G[v2][v1] = w;
    }
}

//遍历图
void Print()
{ 
    int i,j;
    for(i = 0;i < Nv;i++)
    {
        for(j = 0;j < Nv;j++)
            printf("%d ",G[i][j]);
        printf("\n");
    }
}

int main()
{
    BuildGraph();
    Print();
    return 0;
}
