//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> v;
//	v.resize(n +1);
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> v[i];
//	}
//	int count = 0;
//	int i = 0;
//	while (i < n)
//	{
//		//�ǵݼ�����
//		if (v[i] < v[i + 1])
//		{
//			while (i < n && v[i] <= v[i + 1])
//			{
//				i++;
//			}
//			count++;
//			i++;
//		}
//		//������Ҳ���ݼ�
//		else if (v[i] == v[i + 1])
//		{
//			i++;
//		}
//		else
//		{
//			while (i < n && v[i] >= v[i + 1])
//			{
//				i++;
//			}
//			count++;
//			i++;
//		}
//	}
//	
//	cout << count << " ";
//	
//	return 0;
//}

//#include <iostream>
//#include <algorithm>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string s1;
//	getline(cin, s1);
//	reverse(s1.begin(), s1.end());
//
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		string::iterator b = it;
//		while (it < s1.end() && *it != ' ')
//		{
//			++it;
//		}
//		reverse(b, it);
//		//string�ĵ���������Խ��
//		if (it < s1.end())
//		{
//			++it;
//		}
//	}
//	cout << s1;
//	return 0;
//}
//
//#include <iostream>
//#include <string>
//using namespace std;
//// cin��ȡstringʱ�Զ��ᱻ�ո�ָ���������һ���ַ����洢�����������
//int main()
//{
//	string s1, s2;
//	cin >> s2;
//	while (cin >> s1)
//		s2 = s1 + " " + s2;
//	cout << s2 << endl;
//	return 0;
//}