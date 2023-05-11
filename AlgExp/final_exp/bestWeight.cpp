// #include <iostream>
// #include <vector>
// using namespace std;

// int n, W;
// vector<int> w;
// vector<int> x;
// int bestW = 0;
// vector<int> bestX;

// void backtrack(int i, int cw)
// {
//     if (i == n)
//     {
//         if (cw > bestW)
//         {
//             bestW = cw;
//             bestX = x;
//         }
//         return;
//     }
//     if (cw + w[i] <= W)
//     {
//         x[i] = 1;
//         backtrack(i + 1, cw + w[i]);
//     }
//     x[i] = 0;
//     backtrack(i + 1, cw);
// }

// int main()
// {
//     cin >> n >> W;
//     w.resize(n);
//     for (int i = 0; i < n; i++)
//         cin >> w[i];
//     x.resize(n);
//     backtrack(0, 0);
//     cout << bestW << endl;
//     for (int i = 0; i < n; i++)
//         cout << bestX[i] << " ";
//     cout << endl;
//     return 0;
// }

// 优化版本
// #include <algorithm>
// #include <iostream>
// #include <vector>
// using namespace std;

// int n, W;
// vector<int> w;
// vector<int> x;
// int bestW = 0;
// vector<int> bestX;
// vector<int> r;

// bool cmp(int a, int b)
// {
//     return a > b;
// }

// void backtrack(int i, int cw, int rw)
// {
//     if (i == n)
//     {
//         if (cw > bestW)
//         {
//             bestW = cw;
//             bestX = x;
//         }
//         return;
//     }
//     if (cw + w[i] <= W)
//     {
//         x[i] = 1;
//         backtrack(i + 1, cw + w[i], rw - w[i]);
//     }
//     if (cw + rw > bestW)
//     {
//         x[i] = 0;
//         backtrack(i + 1, cw, rw - w[i]);
//     }
// }

// int main()
// {
//     cin >> n >> W;
//     w.resize(n);
//     for (int i = 0; i < n; i++)
//         cin >> w[i];
//     sort(w.begin(), w.end(), cmp);
//     r.resize(n);
//     r[n - 1] = w[n - 1];
//     for (int i = n - 2; i >= 0; i--)
//         r[i] = r[i + 1] + w[i];
//     x.resize(n);
//     backtrack(0, 0, r[0]);
//     cout << bestW << endl;
//     for (int i = 0; i < n; i++)
//         cout << bestX[i] << " ";
//     cout << endl;
//     return 0;
// }

// 栈优化
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node
{
    int i;
    int cw;
    int rw;
    int x;
};

int n, W;
vector<int> w;
vector<int> x;
int bestW = 0;
vector<int> bestX;
vector<int> r;

bool cmp(int a, int b)
{
    return a > b;
}

void backtrack()
{
    stack<Node> s;
    Node e = {0, 0, r[0], 0};
    s.push(e);
    while (!s.empty())
    {
        Node e = s.top();
        s.pop();
        if (e.i == n)
        {
            if (e.cw > bestW)
            {
                bestW = e.cw;
                bestX = x;
            }
            continue;
        }
        if (e.cw + w[e.i] <= W)
        {
            x[e.i] = 1;
            Node ne = {e.i + 1, e.cw + w[e.i], e.rw - w[e.i], 1};
            s.push(ne);
        }
        if (e.cw + e.rw > bestW)
        {
            x[e.i] = 0;
            Node ne = {e.i + 1, e.cw, e.rw - w[e.i], 0};
            s.push(ne);
        }
    }
}

int main()
{
    cin >> n >> W;
    w.resize(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    sort(w.begin(), w.end(), cmp);
    r.resize(n);
    r[n - 1] = w[n - 1];
    for (int i = n - 2; i >= 0; i--)
        r[i] = r[i + 1] + w[i];
    x.resize(n);
    backtrack();
    cout << bestW << endl;
    for (int i = 0; i < n; i++)
        cout << bestX[i] << " ";
    cout << endl;
    return 0;
}