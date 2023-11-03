const N = 100010, M = N * 2; // 无向图需要两条有向边
int head[N], ver[M], edge[M], Next[M], idx;

// 插入一条从 x 到 y 长度为 z 的有向边
void add(int x, int y, int z)
{
    idx++;
    ver[idx] = y;
    edge[idx] = z;
    // 头插
    Next[idx] = head[x];
    head[x] = idx;
}

// 读入一条有向边
add(x, y, z);

// 读入一条无向边(一对有向边==一条无向边)
add(x, y, z);
add(y, x, z);

// 枚举从 x 顶点出发的所有边
for (int i = head[x]; i != 0; i = Next[i])
{
    // 能提供循环条件, 则说明还有边
    int y = ver[i];
    int z = edge[i];
    // 后续操作
}

// 清零只需要处理链表和计数器
memset(head, 0, sizeof(head));
idx = 0;
