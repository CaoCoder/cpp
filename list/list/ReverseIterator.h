#pragma once
//反向迭代器
namespace cao
{
      //           正向迭代器     引用       指针  
    template<class Iterator, class Ref, class Ptr>
    struct Reverse_iterator
    {
        //用传过来的正向迭代器进行定义一个对象
        Iterator _it;

        //然后typedef成Self
        typedef Reverse_iterator<Iterator, Ref, Ptr> Self;

        //构造函数构造正向迭代器对象
        Reverse_iterator(Iterator it)
            :_it(it)
        {}


        Ref operator*()
        {
            Iterator tmp = _it;
            return *(--tmp);
        }

        Ptr operator->()
        {
            return &(operator*());
        }

        Self& operator++()
        {
            --_it;
            return *this;
        }

        Self& operator--()
        {
            ++_it;
            return *this;
        }

        bool operator!=(const Self& s)
        {
            return _it != s._it;
        }

    };
}