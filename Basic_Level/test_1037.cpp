#include <iostream>

using namespace std;

int main()
{
    int a,b,c,p,q,t,x,y,z;
    scanf("%d.%d.%d %d.%d.%d",&a,&b,&c,&p,&q,&t);
    if(a > p || (a == p && b > q) || (a == p && b == q && c > t)) // 钱不够，将a和p、b和q、c和t调换,并在前面添加-。
    {
        swap(a,p);
        swap(b,q);
        swap(c,t);
        printf("-");
    }
    
    // 从低位向高位计算
    z = t < c ? t - c + 29 : t - c; // 要向前借位，借一位后自己加上29
    q = t < c ? q - 1 : q; // 借位后q要减1
    y = q < b ? q - b + 17 : q - b; // 同上
    x = q < b ? p - a - 1 : p - a;
    printf("%d.%d.%d",x,y,z);
    return 0;
}
