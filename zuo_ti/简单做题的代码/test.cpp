#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1010;
const int maxm = 10010;
int n, m;//n�����㣬m����
int p[maxn];//��¼i�ĸ��ڵ���p[i]
int ans;//��¼��С���� 
int cnt;//��¼��С���������� 
int k;
struct edge
{
	int u, v, w;
}e[maxm];

bool cmp(edge a, edge b)//�������� 
{
	return a.w < b.w;
}
int find(int x)//�ҽڵ�ĸ��ڵ� 
{
	if (p[x] != x) 
		p[x] = find(p[x]);
	return p[x];
}
void kruskal()
{
	for (int i = 1; i <= n; i++)//��ʼ��p[i] 
	{
		p[i] = i;
	}
	sort(e, e + m, cmp);//�Ա߽��д�С�������� 
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