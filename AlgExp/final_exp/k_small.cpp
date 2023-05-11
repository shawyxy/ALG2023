#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int N = 1010;
struct node
{
    double l, r;
    bool operator<(const node &w) const
    {
        return r < w.r;
    }
} a[N];
int n, d;
int main() {
    int t = 0;
    while (cin >> n >> d, n || d)
    {
        t++;
        int flag = 0;
        for (int i = 1; i <= n; i++)
        {
            int x, y;
            cin >> x >> y;
            if (y > d)
                flag = 1;
            double len = sqrt(d * d - y * y);
            a[i].l = x - len, a[i].r = x + len;
        }
        if (flag)
        {
            printf("Case %d: -1\n", t);
            continue;
        }
        sort(a + 1, a + n + 1);
        int ans = 0;
        double now = -2e9;
        for (int i = 1; i <= n; i++)
        {
            if (a[i].l > now)
            {
                ans++;
                now = a[i].r;
            }
        }
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}