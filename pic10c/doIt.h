#include <iostream> 
#include <utility>
#include <vector>
#include <set>
#include <algorithm>

namespace std {
    
    class Predicate {
    public:
        int p;
        Predicate(int p) : p(p) {}
        bool operator() (int n) { return n % p == 0; }
    };


///* std::functions */
// void doIt(vector<int>::iterator b1, vector<int>::iterator e1, function<bool(int)>& p, function<void(int)>& f)
// {
//     for (; b1 != e1; ++b1)
//         if (p(*b1))
//             f(*b1);
// }
//
///* c-style function pointers */
//void doIt(vector<int>::iterator b1, vector<int>::iterator e1, bool(*p)(int), void(*f)(int))
//{
//    for (; b1 != e1; ++b1)
//        if (p(*b1))
//            f(*b1);
//}
//
///* predicate */
//void doIt(vector<int>::iterator b1, vector<int>::iterator e1, Predicate& p, void(*f)(int))
//    {
//        for (; b1 != e1; ++b1)
//            if (p(*b1))
//                f(*b1);
//    }

/* templates */
template <class TFunc1, class TFunc2>
void doIt(vector<int>::iterator b1, vector<int>::iterator e1, TFunc1& p, TFunc2& f)
{
    for (; b1 != e1; ++b1)
        if (p(*b1))
            f(*b1);
}

bool isEven(int i) { return i%2 == 0; }
void printInt(int i) { cout << i << " "; }
void addOne(int& i) { i += 1; }

int doItTestMain () {
    vector<int> vec = {0, 1, 2, 5, 6, 7, 8};

    auto it = vec.begin();
    for (; it != vec.end(); ++it) {
            printInt(*it);
    }
    
    cout << endl << "========" << endl;
//
////    doIt(vec.begin(), vec.end(), &isEven, &printInt);
//
//    cout << endl << "========" << endl;
//
//    function<bool(int)> p = isEven;
//    function<void(int)> f = printInt;
//    doIt(vec.begin(), vec.end(), p, f);
//
//    cout << endl << "========" << endl;
    
    Predicate pp(4);
//    doIt(vec.begin(), vec.end(), pp, f);

    function<void(int&)> add = addOne;
    doIt(vec.begin(), vec.end(), pp, add);
    
    it = vec.begin();
    for (; it != vec.end(); ++it) {
            printInt(*it);
    }
    
    

    return 0;
}
}
