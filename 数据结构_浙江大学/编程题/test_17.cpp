/** author: 赖弘霖
 * 	date: 2022/10/23
 * 	topic: 六度空间 
 * */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 1005
int visited[MAXN];
typedef struct VNode *Vertex;
struct VNode
{
	Vertex Next;
	int V;
};
typedef struct LNode
{
	Vertex FirstEdge;
} List[MAXN];
typedef struct GNode *Graph;
struct GNode
{
	int Nv, Ne;
	List head;
};
Graph G;

void Insert(int v, int w)
{
	Vertex NewNode = (Vertex)malloc(sizeof(struct VNode));
	NewNode->V = v;
	NewNode->Next = G->head[w].FirstEdge;
	G->head[w].FirstEdge = NewNode;

	NewNode = (Vertex)malloc(sizeof(struct VNode));
	NewNode->V = w;
	NewNode->Next = G->head[v].FirstEdge;
	G->head[v].FirstEdge = NewNode;
}

void BFS(int s)
{
	int Q[MAXN], front = 0, rear = 0, v;
	int tail, last = s, cnt = 0, level = 0, kase = s;
	Vertex p;
	double perc;
	Q[++rear] = s;
	visited[s] = 1;
	cnt++;
	while (rear != front)
	{
		v = Q[++front];
		for (p = G->head[v].FirstEdge; p; p = p->Next)
		{
			if (!visited[p->V])
			{
				Q[++rear] = p->V;
				visited[p->V] = 1;
				cnt++;
				tail = p->V;
			}
		}
		if (v == last)
		{
			level++;
			last = tail;
		}
		if (level == 6)
			break;
	}
	perc = ((double)cnt) / ((double)G->Nv) * 100;
	printf("%d: %.2lf%%\n", kase, perc);
}

int main()
{
	int i;
	int v,w;
	G = (Graph)malloc(sizeof(struct GNode));
	scanf("%d %d",&G->Nv,&G->Ne);
	for(i = 1;i <= G->Nv;i++)
		G->head[i].FirstEdge = NULL;
	for(i = 1;i <= G->Ne;i++)
	{
		scanf("%d %d",&v,&w);
		Insert(v,w);
	}
	for(i = 1;i <= G->Nv;i++)
	{
		memset(visited,0,sizeof(visited));
		BFS(i);
	}
	return 0;
}
