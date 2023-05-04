// #include <iostream>
// using namespace std;

// const int N = 100010;
// int tt, stk[N];

// int main()
// {

// 	int n;
// 	cin >> n;
// 	for (int i = 0; i < n; i++)
// 	{
// 		int x;
// 		cin >> x;
// 		// 栈不空&&不满足要求        删除栈顶元素
// 		while(tt && stk[tt] >= x) tt--;
// 		// 栈不空	找到正确答案,输出
// 		if(tt) cout << stk[tt] << " ";
// 		// 找不到
// 		else cout << -1 << " ";
// 		stk[++t] = x;
// 	}
// 	return 0;
// }

// #include <iostream>
// #include <stack>
// using namespace std;
// const int N = 100010;
// int n, a[N];
// int tmp[N];
// int main()
// {
// 	stack<pair<int, int>> s;
// 	cin >> n;
// 	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
// 	for (int i = n - 1; i >= 0; i--)
// 	{
// 		while(!s.empty() && s.top().first <= a[i]) s.pop();
// 		if(!s.empty()) tmp[i] = s.top().second;
// 		else tmp[i] = 0;

// 		s.push({a[i], i + 1});
// 	}
// 	for(int i = 0; i < n; i++) printf("%d ", tmp[i]);
// 	return 0;
// }


#include <iostream>
using namespace std;
const int N = 100010;
int n, tt, a[N];
int stk[N];
int ans[N];


int main()
{
	cin >> n;
	for(int i = 0 ; i < n; i++) scanf("%d", &a[i]);
	for(int i = n - 1; i >= 0; i --)
	{
		while(tt && stk[tt] <= a[i]) tt--;
		if(tt) ans[i] = i;
		else ans[i] = 0;

		stk[++tt] = i;
	}
	for(int i = 0; i < 2*n; i++) printf("%d ", ans[i]);
	return 0;
}