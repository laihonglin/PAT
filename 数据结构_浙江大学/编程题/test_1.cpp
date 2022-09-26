/*
 * author: 赖弘霖
 * date: 2022/9/26
 * topic: 最大子列和问题
 * */

#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int a[N];

int main()
{
    int n,tSum = 0,mSum = 0;
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++)
    {
        tSum += a[i];
        if(tSum > mSum) mSum = tSum;
        else if(tSum < 0) tSum = 0; // 如果tSum加上一个数小于0,它就不可能是最大子列和,把tSum置0
    }
    cout << mSum << endl;
    return 0;
}
