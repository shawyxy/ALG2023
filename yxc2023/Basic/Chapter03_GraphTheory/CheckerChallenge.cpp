#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 20;
int n;
bool col[N], dg[N], antidg[N];
int res[N];
vector<vector<int>> ans; // 用一个二维数组来保存所有的解

// 枚举每一行, x 表示一列中第 x 格
void dfs(int x)
{
	if (x == n) 
	{
		ans.push_back(vector<int>(res, res + n)); // 把当前解放入数组中
		return;
	}
	// 枚举x格所在行的这一列
	for (int i = 0; i < n; i++)
	{
		// 如果 x 格在它所在列/对角线/反对角线都没有被访问过
		if (col[i] != true && dg[x + i] != true && antidg[n - x + i] != true)
		{
			res[x] = i; // 记录到路径中
			col[i] = dg[x + i] = antidg[n - x + i] = true; // 标记
			dfs(x + 1); // 进入递归
			col[i] = dg[x + i] = antidg[n - x + i] =  false; // 回溯 
		}
	}
}

int main()
{
	cin >> n;
	dfs(0);
	sort(ans.begin(), ans.end()); // 对所有的解进行排序
	for (int i = 0; i < min(3, (int)ans.size()); i++) // 输出前三个解，或者所有的解（如果小于三个）
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", ans[i][j] + 1);
		}
		cout << endl;
	}
	if (ans.empty()) cout << "No Solution" << endl; 
	else cout << ans.size() << endl;
	return 0;
}
