#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100010, M = N * 2;

int n;
int head[N], ver[M], Next[M], idx;
bool visited[N];

int centroidVal = N; // 重心的值
int subNum[N]; // 保存每个节点最大子树的个数
vector<int> centroids; // 用一个向量来存储所有的重心
void add(int x, int y)
{
	idx++;
	ver[idx] = y;
	Next[idx] = head[x];
	head[x] = idx;
}

int dfs(int x)
{
	visited[x] = true; // 标记x点已经被访问过
	// sum 用来保存x子树的大小(默认包含它本身), subMax用来保存当删除节点x后，剩下较大的孩子子树的大小
	int sum = 1, subMax = 0; 
	for (int i = head[x]; i != -1; i = Next[i]) // 遍历x的孩子
	{
		int j = ver[i], subNum;
		if (visited[j] != true) // 如果当前节点没有被访问过
		{ 
			subNum = dfs(j); // 对它进行DFS,并且取出这棵子树的大小
			subMax = max(subMax, subNum); // 当删除当前节点x后，保存较大的那个孩子子树的大小
			sum += subNum; // 更新x的孩子数量
		}
	}
	// 每个节点只会执行一次
	subMax = max(subMax, n - sum); // 求出当删除节点x后,剩下最大连通块的大小
	centroidVal = min(centroidVal, subMax); //  重心的值更新为{每个节点的最大连通块的大小}这个集合中的最小值
	subNum[x] = subMax; // 记录x的最大子树大小
	
	return sum; // 返回x的父节点,告诉它x这棵子树的大小
}

int main()
{
	cin >> n;
	memset(head, -1, sizeof(head));
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n - 1; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	if (n == 1) // 处理n为1的特殊情况
	{
		// cout << 1 << endl;
		cout << 1 << endl;
		return 0;
	}
	dfs(1); // 入口可以任意
	// cout << centroidVal << endl; // 输出重心的值
	for (int i = 1; i <= n; i++)
	{
		if (subNum[i] == centroidVal) // 如果i的最大子树大小等于重心的值
		{
			centroids.push_back(i); // 将i加入到重心的向量中
		}
	}
	for (int i = 0; i < centroids.size(); i++) // 输出所有的重心
	{
		cout << centroids[i] << endl;
	}
	return 0;
}