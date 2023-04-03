////#include <iostream>
////#include <algorithm>
////#include <vector>
////using namespace std;
////int main()
////{
////	int n = 0;
////	cin >> n;
////	int a_i = 3 * n;
////	int data;
////	vector<long long int> v;
////	vector<vector<long long int>> vv;
////	vector<long long int> v1;
////	for (int i = 0; i < a_i; i++)
////	{
////		cin >> data;
////		v.push_back(data);
////	}
////	sort(v.begin(), v.end(), greater<long long int>());
////
////	vector<long long int>::iterator it = v.begin();
////	vector<long long int>::iterator end = v.end();
////	while (it != end)
////	{
////		v1.push_back(*it);
////		v1.push_back(*(it + 1));
////		v1.push_back(*(end - 1));
////		vv.push_back(v1);
////		v1.clear();
////		end--;
////		it += 2;
////	}
////	long long int sum = 0;
////	for (auto e : vv)
////	{
////		sum += e[1];
////	}
////	cout << sum;
////	return 0;
////}
//
///*暴力查找O(n*N)*/
////#include <iostream>
////#include <string>
////using namespace std;
////
////int main()
////{
////	string s1;
////	string s2;
////	getline(cin, s1);
////	getline(cin, s2);
////	string::iterator it = s2.begin();
////
////	while (it != s2.end())
////	{
////		string::iterator it1 = s1.begin();
////
////		while(it1 != s1.end())
////		{
////			if (*it == *it1)
////			{
////				s1.erase(it1);
////			}
////			if (it1 != s1.end())
////			{
////				it1++;
////			}
////		}
////		it++;
////	}
////	cout << s1 << endl;
////
////}
////哈希映射的思想
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string str1, str2;
//	getline(cin, str1);
//	getline(cin, str2);
//	//使用哈希映射的思想统计str2中字符出现的次数
//	int hashtable[256] = { 0 };
//	for (size_t i = 0; i < str2.size(); ++i)
//	{
//		hashtable[str2[i]]++;
//	}
//
//	string ret;
//	for (size_t i = 0; i < str1.size(); i++)
//	{
//		if (hashtable[str1[i]] == 0)
//			ret += str1[i];
//	}
//
//	cout << ret << endl;
//	return 0;
//}