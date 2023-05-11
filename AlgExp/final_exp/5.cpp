#include <iostream>
using namespace std;
int k, x1, y1, x2, y2;
int a[1050][1050];
int cnt = 0;
void solve(int x, int y, int n)
{
    for (int i = n; i > 1; i /= 2)
    {
        cnt++;
        int mid = i / 2;
        if (x1 <= x + mid - 1 && y1 <= y + mid - 1)
        {
            a[x + mid][y + mid - 1] = a[x + mid][y + mid] = a[x + mid - 1][y + mid] = cnt;
        }
        else if (x1 <= x + mid - 1 && y1 >= y + mid)
        {
            a[x + mid - 1][y + mid - 1] = a[x + mid][y + mid] = a[x + mid][y + mid - 1] = cnt;
        }
        else if (x1 >= x + mid && y1 <= y + mid - 1)
        {
            a[x + mid - 1][y + mid - 1] = a[x + mid - 1][y + mid] = a[x + mid][y + mid] = cnt;
        }
        else
        {
            a[x + mid - 1][y + mid - 1] = a[x + mid][y + mid] = a[x + mid][y + mid - 1] = cnt;
        }
    }
}
int main()
{
    cin >> k >> x1 >> y1 >> x2 >> y2;
    int n = (1 << k);
    solve(0, 0, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}