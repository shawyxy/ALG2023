#include <iostream>
using namespace std;
const int N = 100010;

char s[N];
int ch[N][26], cnt[N], idx;

void insert(char *s)
{
	int p = 0;
	for (int i = 0; s[i]; i++)
	{
		int j = s[i] - 'a'; // 字符--映射-->整数
		if (!ch[p][j]) ch[p][j] = ++idx; // 不存在孩子, 创建之
		p = ch[p][j]; // 插入
	}
	cnt[p]++; // 更新以p结尾的字符串次数
}

int find(char *s)
{
	int p = 0;
	for (int i = 0; s[i]; i++)
	{
		int j = s[i] - 'a';
		if (!ch[p][j]) return 0;
		p = ch[p][j];
	}
	return cnt[p];
}