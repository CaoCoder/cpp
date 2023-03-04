#include <iostream>
using namespace std;

int main()
{
	//拷贝构造函数 用a拷贝一个b
	Rectangle(Rectangle  obj)
	{
		h = obj.h;
		w = obj.w;
	}
	//用a拷贝b
	Rectangle b(a);

	Rectangle obj(a);
	return 0;
}
