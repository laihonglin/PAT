/*
 * author: 赖弘霖
 * date: 2022/9/26
 * topic: 矩阵行平移
 * */

#include <iostream>

using namespace std;

int n,k,x,cnt = 1,Sum[100],a[100][100];

int main()
{
    cin >> n >> k >> x;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            cin >> a[i][j];
            if(i & 1) Sum[j] += a[i][j]; // 将偶数行的每列元素之和先累加后保存在Sum数组中(i&1的解释：是判断i为奇偶数的一种更快方法，因为奇数的二进制最低位为1，偶数为0，那么和1按位与，奇数结果为1，偶数结果为0）。
        }
    }
    for(int i = 0;i < n;i += 2)
    {
        for(int j = 0;j < cnt;j++) Sum[j] += x;
        for(int j = cnt;j < n;j++) Sum[j] += a[i][j - cnt];
        cnt = cnt % k + 1; // 可实现整体右移的循环
    }
    cout << Sum[0];
    for(int i = 1;i < n;i++)
        cout << " " << Sum[i];
    return 0;
}
