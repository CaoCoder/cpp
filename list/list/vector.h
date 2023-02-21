#pragma once
#include<assert.h>

namespace cao
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstoage(nullptr)
		{}
		//��ģ�����滹����������ģ�����
		//Ŀ����ֻΪ������������á������ڵ�һ����ģ���м��롣
		//������ģ���ԭ���ǣ�������vector�ĵ��������Ե��ã�list�ĵ�����Ҳ���Ե��ã�string��Ҳ�С�
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstoage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		void swap(vector<T>& v)
		{
			//���ÿ����swap���ִ�д�������
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstoage, v._endofstoage);
		}

		//��������
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstoage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}
		//��ֵ����
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		//int���޷�������size_t����������ת����
		vector(/*size_t*/int n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstoage(nullptr)
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstoage = nullptr;
			}
		}
		
		//����֧�ַ��������
		typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;

		typedef Reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}


		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}
		size_t size() const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _endofstoage - _start;
		}
		void reserve(size_t n)
		{
			size_t sz = size();
			if (n > capacity())
			{
				T* tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0; i < size(); i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}

				_start = tmp;
			}

			//����_finish��_endofstoage
			_finish = _start + sz;
			_endofstoage = _start + n;

		}
		//����+��ʼ��
		void resize(size_t n, T val = T())
		{
			if (n > capacity())
			{
				reserve(n);
			}
			if (n > size())
			{
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
			//����
			else
			{
				_finish = _start + n;
			}
		}
		//����������Ϊ�˿ɶ���д
		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}
		const T& operator[](size_t pos) const
		{
			assert(pos < size());

			return _start[pos];
		}
		void push_back(const T& x)
		{
			/*if (_finish == _endofstoage)
			{
				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);
			}
			*_finish = x;
			++_finish;*/
			insert(end(), x);
		}
		void pop_back()
		{
			if (_finish > _start)
			{
				--_finish;
			}
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);

			//�����Ժ�pos��ʧЧ����Ҫ����pos
			if (_finish == _endofstoage)
			{
				size_t n = pos - _start;//�������λ��

				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);

				pos = _start + n;//����pos
			}

			//Ų������
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}	

			*pos = x;
			++_finish;

			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				++it;
			}
			//����it�ߵ�finish����it����finish����ֱ�Ӽ����Ϳ���βɾ��
			--_finish;

			return pos;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstoage;
	};
	//void test1()
	//{
	//	vector<int> v;
	//	v.push_back(1);
	//	v.push_back(2);
	//	v.push_back(3);
	//	v.push_back(4);
	//	v.push_back(5);
	//	v.pop_back();
	//	v.pop_back();
	//	vector<int>::iterator it = v.begin();
	//	while (it != v.end())
	//	{
	//		cout << *it << " ";
	//		++it;
	//	}
	//	cout << endl;
	//	for (size_t i = 0; i < v.size(); ++i)
	//	{
	//		cout << v[i] << " ";
	//	}
	//	cout << endl;

	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;

	//}
	////����insert
	//void test2()
	//{
	//	/*vector<int> v;
	//	v.resize(10, -1);
	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;*/
	//	vector<int> v;
	//	v.push_back(1);
	//	v.push_back(2);
	//	v.push_back(3);
	//	v.push_back(4);

	//	v.insert(v.begin(), 0);
	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;

	//}
	////����insert������ʧЧ
	//void test3()
	//{
	//	//������ż��ǰ�����2
	//	vector<int> v;
	//	v.push_back(1);
	//	v.push_back(2);
	//	v.push_back(3);
	//	v.push_back(4);
	//	v.push_back(5);
	//	v.push_back(6);
	//	vector<int>::iterator it = v.begin();
	//	while (it != v.end())
	//	{
	//		if (*it % 2 == 0)
	//		{
	//			it = v.insert(it,20);
	//			++it;
	//		}

	//		++it;
	//	}

	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//}
	////����erase�ĵ�����ʧЧ
	//void test4()
	//{
	//	vector<int> v;
	//	v.push_back(1);
	//	v.push_back(2);
	//	v.push_back(2);
	//	v.push_back(2);
	//	v.push_back(3);
	//	v.push_back(4);
	//	v.push_back(4);
	//	v.push_back(5);
	//	cout << v.size() << ":" << v.capacity() << endl;
	//	auto pos = find(v.begin(), v.end(), 4);
	//	if (pos != v.end())
	//	{
	//		v.erase(pos);
	//	}

	//	cout << *pos << endl;
	//	*pos = 10;
	//	cout << *pos << endl << endl;
	//	cout << v.size() << ":" << v.capacity() << endl;

	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;

	//}

	//void test5()
	//{
	//	vector<int> v;
	//	v.push_back(1);
	//	v.push_back(2);
	//	v.push_back(3);
	//	v.push_back(4);
	//	v.push_back(5);

	//	vector<int> v1(v.begin(), v.end());
	//	std::string s("hello");
	//	vector<int> v2(s.begin(), s.end());
	//	for (auto e : v1)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	for (auto e : v2)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;

	//	vector<int> v3(v);
	//	for (auto e : v3)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;

	//	v1 = v2;
	//	for (auto e : v1)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;

	//}

	//void test6()
	//{
	//	// �ų���
	//	vector<int> v1(10, 2);
	//	for (auto e : v1)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;

	//	vector<char> v2(10, 'x');
	//	for (auto e : v2)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//}
	//class Solution {
	//public:
	//	vector<vector<int>> generate(int numRows) {
	//		vector<vector<int>> vv;
	//		vv.resize(numRows);
	//		for (size_t i = 0; i < vv.size(); ++i)
	//		{
	//			// ������ǣ�ÿ�и������ε���
	//			vv[i].resize(i + 1, 0);

	//			// ��һ�������һ����ʼ����1
	//			vv[i][0] = 1;
	//			vv[i][vv[i].size() - 1] = 1;
	//		}

	//		for (size_t i = 0; i < vv.size(); ++i)
	//		{
	//			for (size_t j = 0; j < vv[i].size(); ++j)
	//			{
	//				if (vv[i][j] == 0)
	//				{
	//					// �м�λ�õ�����һ��j-1 �� j�����
	//					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
	//				}
	//			}
	//		}

	//		for (size_t i = 0; i < vv.size(); ++i)
	//		{
	//			for (size_t j = 0; j < vv[i].size(); ++j)
	//			{
	//				cout << vv[i][j] << " ";
	//			}
	//			cout << endl;
	//		}
	//		cout << endl;

	//		return vv;
	//	}
	//};

	//void test7()
	//{
	//	vector<vector<int>> ret = Solution().generate(5);

	//	for (size_t i = 0; i < ret.size(); ++i)
	//	{
	//		for (size_t j = 0; j < ret[i].size(); ++j)
	//		{
	//			cout << ret[i][j] << " ";
	//		}
	//		cout << endl;
	//	}
	//	cout << endl;
	//}

}
