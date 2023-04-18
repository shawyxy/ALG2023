// 高精度减法：https://www.luogu.com.cn/problem/P2142
#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool check(vector<int>& A, vector<int>& B) // A > B?
{
    if(A.size() != B.size()) return A.size() > B.size();
    else // ==
    {       
        int i = A.size() - 1;
        while(A[i] != B[i] && i >= 0) i--;
        return A[i] >= B[i]; // 注意必须取等，否则0-0=-0
    }
    return true;
}

vector<int> Sub(vector<int>& A, vector<int>& B)
{
    vector<int> c;
    int t = 0; // 借位，0/1两种状态表示
    for(int i = 0; i < A.size(); i++)
    {
        t = A[i] - t;   
        if(i < B.size()) t -= B[i];
        c.push_back((t + 10) % 10);
        if(t < 0) t = 1;
        else t = 0;
    }
    
    // 处理前导0
    while(c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}
int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    
    if(check(A, B))
    {
        vector<int> res = Sub(A, B);
        for(int i = res.size() - 1; i >= 0; i--) cout << res[i];
        cout << endl;
    }
    else
    {
        vector<int> res = Sub(B, A);
        cout << '-';
        for(int i = res.size() - 1; i >= 0; i--) cout << res[i];
        cout << endl;
    }
    
    return 0;
}