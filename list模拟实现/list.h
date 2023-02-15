#pragma once
#include <assert.h>

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
            ,_prev(nullptr)
            ,_data(val)
        {} 
    };
        template<class T, class Ref, class Ptr>
        struct _list_iterator
        {
            typedef list_node<T> Node;
            typedef _list_iterator<T,Ref,Ptr> self;
            Node* _node;

            _list_iterator(Node* node)
                :_node(node)
                {}

                Ref operator*()
                {
                    return _node->_data;
                }

                Ptr operator->()
                {
                    return &_node->_data;
                }

                self& operator++()
                {
                    _node = _node->_next;
                    return *this;
                }

                self& operator--()
                {
                    _node = _node->_prev;
                    return *this;
                }

                self operator++(int)
                {
                    self tmp(*this);
                    _node = _node->_next;
                    return tmp;
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

        template<class T>
        class list
        {
            typedef list_node<T> Node;
        public:
            typedef _list_iterator<T, T&, T*> iterator;
            typedef _list_iterator<T, const T&, const T*> const_iterator;
            const_iterator begin() const{
                return const_iterator(_head->_next);
            }

            const_iterator end() const{
                return const_iterator(_head);
            }

            iterator begin()
            {
                return iterator(_head->_next);
            }

            iterator end()
            {
                return iterator(_head);
            }
     

            list()
            {
                _head = new Node();
                _head->_next = _head;
                _head->_prev = _head;
            }
            template <class InputIterator>
            list(InputIterator first, InputIterator last)
            {
                empty_init();

                while(first != last)
                {
                    push_back(*first);
                    ++first;
                }
            }

            void empty_init()
            {
                _head = new Node();
                _head->_next = _head;
                _head->_prev = _head;
            }

            void swap(list<T>& lt)
            {
                std::swap(_head,lt._head);
            }

             list(const list<T>& lt)
             {
                 empty_init();
                 list<T> tmp(lt.begin(),lt.end());
                 swap(tmp);
             }

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
            cout << "我被调用了" << endl;
		}
            void push_back(const T& x)
            {
                Node* tail = _head->_prev;
                Node* newnode = new Node(x);

                tail->_next = newnode;
                newnode->_prev = tail;
                newnode->_next = _head;
                _head->_prev = newnode;
            }
            iterator insert(iterator pos,const T& x)
            {
                Node* newNode = new Node(x);
                Node* cur = pos._node;
                Node* prev = cur->_prev;

                //prev  newnode cur
                prev->_next = newNode;
                newNode->_prev = prev;
                newNode->_next = cur;
                cur->_prev = newNode;

                return iterator(newNode);
            }
            void push_front(const T& x)
            {
                insert(begin(),x);
            }
            void pop_back()
            {
                erase(--end());
            }

            void pop_front()
            {
                erase(begin());
            }
            iterator erase(iterator pos)
            {
                assert(pos != end());

                Node* cur = pos._node;
                Node* prev = cur->_prev;
                Node* next = cur->_next;

                //prev  next
                prev->_next = next;
                next->_prev = prev;
                
                delete cur;

                return iterator(next);
            }
            
            void clear()
            {
                iterator it = begin();
                while(it != end())
                {
                    it = erase(it);
                }
            }






















        private:
            Node* _head;

        };

void test1()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);

    list<int>::iterator it = lt.begin();
    while(it != lt.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}
struct AA
{
    AA(int a1 = 0, int a2 = 0)
        :_a1(a1)
        ,_a2(a2)
        {}
    int _a1;
    int _a2;  
};
void test2()
{
    list<AA> lt;
    lt.push_back(AA(1,1));
    lt.push_back(AA(2,2));
    lt.push_back(AA(3,3));
    lt.push_back(AA(4,4));

    list<AA>::iterator it = lt.begin();
    while(it != lt.end())
    {
        cout << it->_a1<< it->_a2 << " ";
        ++it;
    }
    cout << endl;
}
void test3()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);

    lt.push_front(1);
    lt.push_front(2);
    lt.push_front(3);
    lt.push_front(4);
    for(auto e : lt)
    {
        cout << e << " ";
    }
    cout << endl;

    lt.pop_front();
    lt.pop_front();
    lt.pop_back();
    lt.pop_back();
    for(auto e : lt)
    {
        cout << e << " ";
    }
    cout << endl;
}

void test4()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(2);
    lt.push_back(4);
    lt.push_back(5);
    lt.push_back(6);
    lt.push_back(7);
    
    //在偶数前面插入10
    auto it1 = lt.begin();
    while(it1 != lt.end())
    {
        if(*it1 % 2 == 0)
        {
            lt.insert(it1,*it1*10);
        }
        ++it1;
    }
    for(auto e: lt)
    {
        cout << e <<" ";
    }
    cout << endl;
}

void test5()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(5);
    lt.push_back(6);
    
    auto it1 = lt.begin();
    while(it1 != lt.end())
    {
        if(*it1 % 2 == 0)
        {
            it1 = lt.erase(it1);
        }
        else
        {
            ++it1;
        }
    }
    for(auto e : lt)
    {
        cout << e << " ";
    }
    cout << endl;

    lt.clear();

     for(auto e : lt)
    {
        cout << e << " ";
    }
    cout << endl;


    	lt.push_back(10);
		lt.push_back(20);
		lt.push_back(30);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

}

void test6()
{
    	list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		lt.push_back(6);

		list<int> lt1(lt);

		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;
        
        for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
}





















}

