//#include<iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <map>
//using namespace std;
//
//int main()
//{
//	vector<string> v;
//	string s1;
//	cin >> s1;
//	string::iterator it = s1.begin();
//	string::iterator ret = it;
//	while (it != s1.end())
//	{
//		ret = it;
//		while (it != s1.end()-1 && *it + 1 == *(it+1))
//		{
//			it++;
//		}
//		if (it != s1.end())
//		{
//			it++;
//		}
//		string s(ret, it);
//		v.push_back(s);
//		
//	}
//	struct Greater
//	{
//		int operator()(string& s1, string& s2)
//		{
//			return s1.size() > s2.size();
//		}
//	};
//	sort(v.begin(), v.end(), Greater());
//	cout << v[0];
//	return 0;
//}

/*unorder_map*/

//#include <iostream>
//#include <unordered_map>
//#include <vector>
//using namespace std;
//int main()
//{
//	unordered_map<int, int> um;
//
//	int n = 0;
//	cin >> n;
//	vector<int> v;
//	v.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//	}
//	
//	for (int i = 0; i < n; i++)
//	{
//		if (um.count(v[i]))
//		{
//			um[v[i]]++;
//		}
//		else
//		{
//			um.insert(make_pair(v[i], 1));
//		}
//	}
//	for (auto e : um)
//	{
//		if (e.second > v.size() / 2)
//		{
//			cout << e.first;
//			break;
//		}
//	}
//	return 0;
//}
//
//class Solution {
//public:
//	unordered_map<int, int> um;
//
//	int MoreThanHalfNum_Solution(vector<int> numbers)
//	{
//		for (int i = 0; i < numbers.size(); i++)
//		{
//			cin >> numbers[i];
//		}
//
//		for (int i = 0; i < numbers.size(); i++)
//		{
//			if (um.count(numbers[i]))
//			{
//				um[numbers[i]]++;
//			}
//			else
//			{
//				um.insert(make_pair(numbers[i], 1));
//			}
//		}
//		for (auto e : um)
//		{
//			if (e.second > numbers.size() / 2)
//			{
//				return e.first;
//				break;
//			}
//		}
//
//		return 0;
//	}
//};