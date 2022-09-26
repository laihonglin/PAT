/*
 * author: 赖弘霖
 * date: 2022/9/26
 * topic: 数组元素循环右移问题
 * */

#include <bits/stdc++.h>

using namespace std;
const int N = 105;
int q1[N],q2[N];

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        cin >> q1[i];
        q2[(i + m) % n] = q1[i]; // 可以将数组后m个数移到数组前m个
    }
    cout << q2[0];
    for(int i = 1;i < n;i++) cout << " " << q2[i];
    return 0;
}
