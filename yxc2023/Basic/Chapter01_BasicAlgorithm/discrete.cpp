const int N = 300010;
int a[N], s[N];        // 存储坐标插入的值;a[]的前缀和数组
vector<int> alls;      // 保存所有输入的下标
// add保存插入时的{位置, 常数}
// query保存的查询时的区间边界{l, r}
vector<pair<int, int>> add, query;

int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l + 1; // 从1下标开始映射
}

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    // 保存"+c"操作
    for(int i = 1; i <= n; i++)
    {
        int x = 0, c = 0; // 位置 常数
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    // 保存"查询"操作
    for(int i = 1; i <= m; i++)
    {
        int l = 0, r = 0; // [l, r]边界下标
        cin >> l >> r;
        add.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }
    // 排序+去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    // "+c"
    for(auto it : alls)
    {
        int x = find(it.first); // 找到原序列元素在新数组alls[]中的下标
        a[x] += it.second;      // "+c"
    }
    // 计算a[]的前缀和
    for (int i = 1; i <= alls.size(); i++) s[i] = s[i-1] + a[i];
    // "查询"
    for (auto it : query) 
    {
        int l = find(it.first);
        int r = find(it.second);
        cout << s[r] - s[l-1] << endl;
    }

    return 0;
}