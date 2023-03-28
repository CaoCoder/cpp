#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <map>
using namespace std;
struct Goods
{
	string _name;//����
	double _price;//�۸�
	int _evaluate;//����
	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{}
};

int main()
{
	vector<Goods> v = { {"ƻ��",2.1,5}, {"�㽶",3,4}, 
		{"����",2.2,3},Goods("����", 1.5, 4)};

	auto com1 = [](const Goods& g1, const Goods& g2) {return g1._price < g2._price; };
	sort(v.begin(), v.end(), com1);
}