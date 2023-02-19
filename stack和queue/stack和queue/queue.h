#pragma once
#include<iostream>
#include <deque>
#include <vector>
using namespace std;


namespace cao
{

	

	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_front();
		}
		const T& front()
		{
			return _con.front();
		}
		const T& back()
		{
			return _con.back();
		}
		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}


	private:
		Container _con;
	};

	void test_queue()
	{
		queue<int> s;
		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);

		while (!s.empty())
		{
			cout << s.front() << " ";
			s.pop();
		}
		cout << endl;
	}



	//仿函数
	// 或者叫函数对象
	//搞成模板可以支持各种类型
	template<class T>
	struct less
	{
		bool operator()(const T& x, const T& y) const
		{
			return x < y;
		}
	};

	template<class T>
	struct greater
	{
		bool operator()(const T& x, const T& y) const
		{
			return x > y;
		}
	};
	//优先级队列
	//没有仿函数，已经写死了，要按照升序排序就没法排了。
	template<class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{

		
	public:
		//大堆用 <
		Compare comFunc;
		void AdjustUp(int child)
		{

			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (comFunc(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void AdjustDown(int parent)
		{
			Compare comFunc;
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() &&comFunc(_con[child], _con[child + 1]))
				{
					++child;
				}

				if (comFunc(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
		void push(const T& x)
		{
			_con.push_back(x);
			//向上调整
			AdjustUp(_con.size() - 1);
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			//向下调整
			AdjustDown(0);
		}

		const T& top()
		{
			return _con[0];
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}



	private:
		Container _con;
	};

	void test_priority_queue()
	{
		priority_queue<int,vector<int>,greater<int>> pq;

		pq.push(2);
		pq.push(5);
		pq.push(1);
		pq.push(6);
		pq.push(8);
		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
}