/*
 * author: 赖弘霖
 * date: 2022/9/28
 * topic: 月饼 
 * */

#include <iostream>
#include <algorithm>

using namespace std;

struct mooncake
{
    double mount,print,unit;
}cake[1005];

bool cmp(mooncake a,mooncake b)
{
    return a.unit > b.unit;
}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> cake[i].mount;
    for(int i = 0;i < n;i++) cin >> cake[i].print;
    for(int i = 0;i < n;i++) cake[i].unit = cake[i].print / cake[i].mount; // 求出每个月饼的单价
    sort(cake,cake + n,cmp); // 按单价从大到小排序
    double ans = 0;
    for(int i = 0;i < n;i++)
    {
        if(m > cake[i].mount) ans += cake[i].print,m -= cake[i].mount; // 需求量 > 库存量。按库存量从高到低进行购买。
        else // 需求量 < 库存量
        {
            ans += cake[i].unit * m; // 全部买单价最高的月饼
            break;
        }
    }
    printf("%.2lf",ans);
    return 0;
}
