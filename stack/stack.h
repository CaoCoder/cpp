// #pragma once

// namespace cao
// {
//     template<class T, class Container = deque<T>>
//     class stack
//     {
//     public:
//         void push(const T& x)
//         {
//             _con.push_back(x);
//         }

//         void pop()
//         {
//             _con.pop_back();
//         }

//         const T& top()
//         {
//             return _con.back();
//         }

//         size_t size()
//         {
//             return _con.size();
//         }
//         bool empty()
// 		{
// 			return _con.empty();
// 		}

//     private:
//         Container _con;
//     };

//     void test_stack()
//     {
//         stack<int> s;
//         s.push(1);
//         s.push(1);
//         s.push(1);
//         s.push(1);
//         while(!s.empty())
//         {
//             cout << s.top() << " ";
//             s.pop();
//         }
//         cout << endl;

//     }
// }