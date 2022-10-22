/** author: 赖弘霖
 * 	date: 2022/10/22
 * 	topic: Saving James Bond - Easy Version 
 * */
#include <cstdio>
using namespace std;
#define MAX 100
int N,D;
int visit[MAX];

struct CNode
{
	int x, y;
} COORD[MAX];

bool FirstJump(int a)
{
	int x, y;
	x = COORD[a].x;
	y = COORD[a].y;
	if ((D + 7.5) * (D + 7.5) >= x * x + y * y)
		return true;
	else
		return false;
}

bool Jump(int a, int b)
{
	int x1, x2, y1, y2;
	x1 = COORD[a].x;
	x2 = COORD[b].x;
	y1 = COORD[a].y;
	y2 = COORD[b].y;
	if (D * D >= (y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1))
		return true;
	else
		return false;
}

bool IsEscape(int a)
{
	int x, y;
	if (COORD[a].x < 0)
		x = -COORD[a].x;
	else
		x = COORD[a].x;
	if (COORD[a].y < 0)
		y = -COORD[a].y;
	else
		y = COORD[a].y;
	if (D >= (50 - x) || D >= (50 - y))
		return true;
	else
		return false;
}

int DFS(int a)
{
	int answer = 0;
	visit[a] = 1;
	if (IsEscape(a))
		answer = 1;
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (!visit[i] && Jump(a, i))
			{
				answer = DFS(i);
			}
		}
	}
	return answer;
}

void Save007()
{
	int answer = 0;
	if (D >= 42.5)
		answer = 1;
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (!visit[i] && FirstJump(i))
			{
				answer = DFS(i);
				if (answer)
					break;
			}
		}
		if (answer)
			printf("Yes");
		else
			printf("No");
	}
}

int main()
{
	scanf("%d %d", &N, &D);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &COORD[i].x, &COORD[i].y);
	}
	Save007();
	return 0;
}
