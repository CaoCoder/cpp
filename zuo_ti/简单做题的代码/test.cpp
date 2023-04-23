#include<iostream>
#include<string>
using namespace std;

int getPos(char c, string inStr)
{
	int pos;
	for (pos = 0; pos < inStr.size(); pos++)
	{
		if (inStr[pos] == c)
			break;
	}
	return pos;
}
void func(int inlidx, int inridx, int postlidx, int postridx, string inStr, string postStr, string& ans)
{
	int pos = getPos(postStr[postridx], inStr);
	ans.push_back(postStr[postridx]);
	int tmpl = pos - inlidx;
	int tmpr = inridx - pos;
	if (pos > inlidx)
		func(inlidx, pos - 1, postlidx, postridx - tmpr - 1, inStr, postStr, ans);
	if (pos < inridx)
		func(pos + 1, inridx, postlidx + tmpl, postridx - 1, inStr, postStr, ans);
}
string preorderString(string inorderString, string postorderString)
{
	int sz = inorderString.size();
	string ans;
	func(0, sz - 1, 0, sz - 1, inorderString, postorderString, ans);
	return ans;
}

int main()
{
	string inStr = "JGDHKBAELIMCF";
	string postStr = "JGKHDBLMIEFCA";
	string ans = preorderString(inStr, postStr);
	cout << "前序遍历：";
	cout << ans << endl;
	return 0;
}
