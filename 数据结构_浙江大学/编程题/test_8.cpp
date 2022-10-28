/** author:赖弘霖
 * 	date: 2022/10/28
 * 	topic: Tree Traversals Again 
 * */
#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define MAXN 35
int pre[MAXN],in[MAXN],post[MAXN];

void solve(int preL,int inL,int postL,int n)
{
	int i,L,R,root;
	if(n == 0) return;
	if(n == 1)
	{
		post[postL] = pre[preL];
		return;
	}
	root = pre[preL];
	post[postL + n - 1] = root;
	for(i = 0;i < n;i++)
		if(in[inL + i] == root) break;
	L = i;
	R = n - L - 1;
	solve(preL + 1,inL,postL,L);
	solve(preL + L + 1,inL + L + 1,postL + L,R);
}

int main()
{
	int n,k;
	int i = 0,j = 0;
	stack<int> s;
	string str;
	cin >> n;
	while(cin >> str)
	{
		if(str == "Push")
		{
			cin >> k;
			s.push(k);
			pre[i++] = k;
		}
		else if(str == "Pop")
		{
			k = s.top();
			s.pop();
			in[j++] = k;
		} 
	}
	solve(0,0,0,n);
	for(i = 0;i < n - 1;i++)
		cout << post[i] << " ";
	cout << post[i];
	return 0;
}
