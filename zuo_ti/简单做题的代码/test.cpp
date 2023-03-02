#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1010;
const int maxm = 10010;
int n, m;//n个顶点，m条边
int p[maxn];//记录i的父节点是p[i]
int ans;//记录最小代价 
int cnt;//记录最小生成树边数 
int k;
struct edge
{
	int u, v, w;
}e[maxm];

bool cmp(edge a, edge b)//升序排序 
{
	return a.w < b.w;
}
int find(int x)//找节点的根节点 
{
	if (p[x] != x) 
		p[x] = find(p[x]);
	return p[x];
}
void kruskal()
{
	for (int i = 1; i <= n; i++)//初始化p[i] 
	{
		p[i] = i;
	}
	sort(e, e + m, cmp);//对边进行从小到达排序 
	for (int i = 0; i < m; i++)
	{
		int root1 = find(e[i].u);
		int root2 = find(e[i].v);
		if (root1 != root2)
		{
			p[root1] = root2;
			ans += e[i].w;
			cnt++;
			if (cnt == n - k)  break;
		}
	}
	if (cnt == n - k) cout << ans << endl;
	else cout << "No Answer";
}
int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	kruskal();
	return 0;
}