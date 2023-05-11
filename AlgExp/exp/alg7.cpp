// 这个问题是一个经典的背包问题，也称为分数背包问题。这个问题可以使用贪心算法来解决。首先，我们可以计算每个物品的单位重量价值（即vi/wi），然后按照单位重量价值从大到小的顺序将物品装入背包，直到背包装满或者所有物品都被考虑过。如果最后一个物品不能全部装入背包，那么我们可以取它的一部分装入背包，使得背包恰好装满。
// 这个算法的时间复杂度主要取决于排序的时间复杂度。其中使用了STL中的sort函数，它的时间复杂度为O(nlogn)，其中n为物品的数量。除了排序之外，其他操作的时间复杂度都是O(n)。因此，整个算法的时间复杂度为O(nlogn)。
// #include <iostream>
// #include <algorithm>
// using namespace std;
// struct item
// {
//     int w;
//     int v;
//     double vw;
// };
// bool cmp(item a, item b)
// {
//     return a.vw > b.vw;
// }
// int main()
// {
//     int n, W;
//     cin >> n >> W;
//     item items[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> items[i].w >> items[i].v;
//         items[i].vw = (double)items[i].v / items[i].w;
//     }
//     sort(items, items + n, cmp);
//     double ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (W >= items[i].w)
//         {
//             ans += items[i].v;
//             W -= items[i].w;
//         }
//         else
//         {
//             ans += W * items[i].vw;
//             break;
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }

// 首先，我们可以将田忌和齐王的马按照速度从大到小排序。然后，我们可以从速度最快的马开始比较。如果田忌的马比齐王的马快，那么就让这两匹马比赛，田忌可以赢得200两黄金。如果田忌的马比齐王的马慢，那么就让田忌最慢的马和齐王最快的马比赛，这样可以尽量减少损失。
// 这个算法的时间复杂度主要取决于排序的时间复杂度。其中使用了STL中的sort函数，它的时间复杂度为O(nlogn)，其中n为马的数量。除了排序之外，其他操作的时间复杂度都是O(n)。因此，整个算法的时间复杂度为O(nlogn)。

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int tian[n], qi[n];
    for (int i = 0; i < n; i++) cin >> tian[i];
    for (int i = 0; i < n; i++) cin >> qi[i];
    sort(tian, tian + n);
    sort(qi, qi + n);
    int ans = 0;
    int t1 = 0, t2 = n - 1, q1 = 0, q2 = n - 1;
    while (t1 <= t2)
    {
        if (tian[t2] > qi[q2])
        {
            ans += 200;
            t2--;
            q2--;
        }
        else if (tian[t2] < qi[q2])
        {
            ans -= 200;
            t1++;
            q2--;
        }
        else
        {
            if (tian[t1] > qi[q1])
            {
                ans += 200;
                t1++;
                q1++;
            }
            else
            {
                if (tian[t1] < qi[q2]) ans -= 200;
                t1++;
                q2--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
