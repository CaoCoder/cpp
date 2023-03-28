#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <map>
using namespace std;
struct Goods
{
	string _name;//名字
	double _price;//价格
	int _evaluate;//评价
	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{}
};

int main()
{
	vector<Goods> v = { {"苹果",2.1,5}, {"香蕉",3,4}, 
		{"橙子",2.2,3},Goods("菠萝", 1.5, 4)};

	auto com1 = [](const Goods& g1, const Goods& g2) {return g1._price < g2._price; };
	sort(v.begin(), v.end(), com1);
}