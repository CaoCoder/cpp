#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

typedef pair<int, int> PII;  // 定义类型，存储距离和节点编号

int n, m;
int h[N], e[N], ne[N], w[N], idx;  // 邻接表存储方式
int dist[N];  // 存储起点到各点的最短距离
bool st[N];  // 存储每个点是否已经确定最短路

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);  // 初始化，将所有距离都设为无穷大
    dist[1] = 0;  // 起点到自己的距离为0

    priority_queue<PII, vector<PII>, greater<PII>> q;  // 堆优化，存储距离和节点编号

    q.push({ 0, 1 });  // 将起点压入堆中，距离为0

    while (q.size())
    {
        auto t = q.top();  // 取出堆顶元素
        q.pop();

        int ver = t.second, distance = t.first;

        if (st[ver]) continue;  // 如果该点已经确定最短路，则直接跳过

        st[ver] = true;  // 标记该点已经确定最短路

        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];  // 取出当前节点的出边指向的节点
            if (dist[j] > distance + w[i])  // 如果起点到j点的距离可以被更新
            {
                dist[j] = distance + w[i];  // 更新起点到j点的距离
                q.push({ dist[j], j });  // 将更新过的j点压入堆中
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);  // 初始化邻接表

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);  // 存储边的信息
    }

    dijkstra();

    for (int i = 1; i <= n; i++) cout << dist[i] << ' ';  // 输出起点到各点的最短距离

    return 0;
}
