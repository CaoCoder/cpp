#pragma once
#include <assert.h>
//#include "ReverseIterator.h"

namespace cao
{
	template<class T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _data;

		list_node(const T& val = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(val)
		{}

		list_node(T&& val)
			:_next(nullptr)
			, _prev(nullptr)
			, _data(std::forward<T>(val))
		{}
	};

	// typedef __list_iterator<T, T&, T*> iterator;
	// typedef __list_iterator<T, const T&, const T*> const_iterator;

	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;

		typedef Ptr pointer;
		typedef Ref reference;

		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}

		// 析构函数  -- 节点不属于迭代器，不需要迭代器释放
		// 拷贝构造和赋值重载 -- 默认生成的浅拷贝就可以

		// *it
		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			//return &(operator*());
			return &_node->_data;
		}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}


		bool operator!=(const self& it)
		{
			return _node != it._node;
		}

		bool operator==(const self& it)
		{
			return _node == it._node;
		}

	};

	// 复用性很差
	// 单独实现一个类，支持不能修改迭代器指向节点的数据
	//template<class T>
	//struct __list_const_iterator;



	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:

		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		// 反向迭代器适配支持
		/*	typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;
			typedef Reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;*/

			//typedef Reverse_iterator<iterator> reverse_iterator;
			//typedef Reverse_iterator<const_iterator> const_reverse_iterator;

		const_iterator begin() const
		{
			// list_node<int>*
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		iterator begin()
		{
			return iterator(_head->_next);
			//return _head->_next;
		}

		iterator end()
		{
			return iterator(_head);
		}

		//const_reverse_iterator rbegin() const
		//{
		//	// list_node<int>*
		//	return const_reverse_iterator(end());
		//}

		//const_reverse_iterator rend() const
		//{
		//	return const_reverse_iterator(begin());
		//}

		//reverse_iterator rbegin()
		//{
		//	return reverse_iterator(end());
		//}

		//reverse_iterator rend()
		//{
		//	return reverse_iterator(begin());
		//}

		list()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
		}

		// lt2(lt1)
		/*list(const list<T>& lt)
		{
		_head = new Node();
		_head->_next = _head;
		_head->_prev = _head;

		for (auto e : lt)
		{
		push_back(e);
		}
		}*/

		void empty_init()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
		}

		template <class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			empty_init();

			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		// 17:00 继续
		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
		}

		// lt2(lt1) -- 现代写法
		list(const list<T>& lt)
		{
			empty_init();
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}

		// lt2 = lt1
		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_back(T&& xx)
		{
			insert(end(), std::forward<T>(xx));
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		// 插入在pos位置之前
		iterator insert(iterator pos, const T& x)
		{
			Node* newNode = new Node(x);
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			// prev  newnode  cur
			prev->_next = newNode;
			newNode->_prev = prev;
			newNode->_next = cur;
			cur->_prev = newNode;

			return iterator(newNode);
		}

		iterator insert(iterator pos, T&& xx)
		{
			Node* newNode = new Node(std::forward<T>(xx));
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			// prev  newnode  cur
			prev->_next = newNode;
			newNode->_prev = prev;
			newNode->_next = cur;
			cur->_prev = newNode;

			return iterator(newNode);
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());

			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			// prev  next
			prev->_next = next;
			next->_prev = prev;
			delete cur;

			return iterator(next);
		}

	private:
		Node* _head;
	};
}