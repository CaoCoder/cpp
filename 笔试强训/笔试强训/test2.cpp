#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	vector<int> v;
	v.resize(n +1);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	int count = 0;
	int i = 0;
	while (i < n)
	{
		//非递减序列
		if (v[i] < v[i + 1])
		{
			while (i < n && v[i] <= v[i + 1])
			{
				i++;
			}
			count++;
			i++;
		}
		//不递增也不递减
		else if (v[i] == v[i + 1])
		{
			i++;
		}
		else
		{
			while (i < n && v[i] >= v[i + 1])
			{
				i++;
			}
			count++;
			i++;
		}
	}
	
	cout << count << " ";
	
	return 0;
}