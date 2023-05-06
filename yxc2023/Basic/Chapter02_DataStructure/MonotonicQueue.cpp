#include <iostream>
using namespace std;
const int N = 100010;
int tt = -1, hh;
int a[N], q[N];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (int i = 0; i < n; i++)
    {
        // 1. 队头是否在窗口中
        if (hh <= tt && i - k + 1 > q[hh]) hh++;
        // 2. 最新元素和队头的关系
        while (hh <= tt && a[q[tt]] >= a[i]) tt--;
        // 3. 入队
        q[++tt] = i;
        if (i >= k - 1) printf("%d ", a[q[hh]]);
    } 
    
    cout << endl;
    tt = -1, hh = 0;
    for (int i = 0; i < n; i++)
    {
        // 1. 队头是否在窗口中
        if (hh <= tt && i - k + 1 > q[hh]) hh++;
        // 2. 最新元素和队头的关系
        while (hh <= tt && a[q[tt]] <= a[i]) tt--;
        // 3. 入队
        q[++tt] = i;
        if (i >= k - 1) printf("%d ", a[q[hh]]);
    } 
    
    return 0;
}