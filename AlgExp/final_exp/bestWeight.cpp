#include <iostream>
#include <vector>
using namespace std;

int n, W;
vector<int> w;
vector<int> x;
int bestW = 0;
vector<int> bestX;

void backtrack(int i, int cw)
{
    if (i == n)
    {
        if (cw > bestW)
        {
            bestW = cw;
            bestX = x;
        }
        return;
    }
    if (cw + w[i] <= W)
    {
        x[i] = 1;
        backtrack(i + 1, cw + w[i]);
    }
    x[i] = 0;
    backtrack(i + 1, cw);
}

int main()
{
    cin >> n >> W;
    w.resize(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    x.resize(n);
    backtrack(0, 0);
    cout << bestW << endl;
    for (int i = 0; i < n; i++)
        cout << bestX[i] << " ";
    cout << endl;
    return 0;
}