#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

typedef pair<int, int> PII;  // �������ͣ��洢����ͽڵ���

int n, m;
int h[N], e[N], ne[N], w[N], idx;  // �ڽӱ�洢��ʽ
int dist[N];  // �洢��㵽�������̾���
bool st[N];  // �洢ÿ�����Ƿ��Ѿ�ȷ�����·

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);  // ��ʼ���������о��붼��Ϊ�����
    dist[1] = 0;  // ��㵽�Լ��ľ���Ϊ0

    priority_queue<PII, vector<PII>, greater<PII>> q;  // ���Ż����洢����ͽڵ���

    q.push({ 0, 1 });  // �����ѹ����У�����Ϊ0

    while (q.size())
    {
        auto t = q.top();  // ȡ���Ѷ�Ԫ��
        q.pop();

        int ver = t.second, distance = t.first;

        if (st[ver]) continue;  // ����õ��Ѿ�ȷ�����·����ֱ������

        st[ver] = true;  // ��Ǹõ��Ѿ�ȷ�����·

        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];  // ȡ����ǰ�ڵ�ĳ���ָ��Ľڵ�
            if (dist[j] > distance + w[i])  // �����㵽j��ľ�����Ա�����
            {
                dist[j] = distance + w[i];  // ������㵽j��ľ���
                q.push({ dist[j], j });  // �����¹���j��ѹ�����
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);  // ��ʼ���ڽӱ�

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);  // �洢�ߵ���Ϣ
    }

    dijkstra();

    for (int i = 1; i <= n; i++) cout << dist[i] << ' ';  // �����㵽�������̾���

    return 0;
}
