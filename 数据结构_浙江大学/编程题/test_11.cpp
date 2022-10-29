/** author: 赖弘霖
 * 	date: 2022/10/29
 * 	topic: Complete Binary Search Tree 
 * */
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAXN 1005
int A[MAXN],T[MAXN];

int Min(int a,int b)
{
	return a > b ? b : a;
}

int GetLeftLength(int n)
{
	int h,x,L;
	h = log2(n + 1);
	x = n + 1 - pow(2,h);
	x = Min(x, pow(2, h-1));
	L = pow(2,h - 1) - 1 + x;
	return L;
}

void solve(int ALeft,int ARight,int TRoot)
{
	int n,L,LeftTRoot,RightTRoot;
	n = ARight - ALeft + 1;
	if(n == 0) return;
	L = GetLeftLength(n);
	T[TRoot] = A[ALeft + L];
	LeftTRoot = TRoot * 2 + 1;
	RightTRoot = LeftTRoot + 1;
	solve(ALeft,ALeft + L - 1,LeftTRoot);
	solve(ALeft + L + 1,ARight,RightTRoot);
}

int main()
{
	int n,i;
	cin >> n;
	for(i = 0;i < n;i++)
		cin >> A[i];
	sort(A,A + n);
	solve(0,n - 1,0);
	for(i = 0;i < n - 1;i++)
		cout << T[i] << " ";
	cout << T[i];
	return 0;
}
