#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

namespace std {
    
/* templates */
template <class T1, class T2>
void doIt1(vector<double>::iterator b1, vector<double>::iterator e1, T1& p, T2& f)
{
    for (; b1 != e1; ++b1)
        if (p(*b1))
            f(*b1);
}

    bool nonZero(double in) { return in != 0.0; }
    class AccumulateSquares {
    public:
        double& storage;
        double& operator()(double in) { return storage += in * in; }
        
        AccumulateSquares(double& ref_storage) : storage(ref_storage) {}
    };
    
    bool isNegative(double in) { return in < 0.0; }
    class UnitReLu {
    public:
        double& operator()(double& in) { return in = 0.0; }
    };
    
    void doItNormTest() {
        vector<double> vec = {1.0, -2.0, 2.3, -1.34, -2.7, 3.14};

        function<bool(double)> nonZeroFunc = nonZero;
        double storage = 0.0;
        AccumulateSquares ac(storage);
        doIt1(vec.begin(), vec.end(), nonZeroFunc, ac);

        cout << sqrt(storage) << endl;
        
        function<bool(double)> isNegativeFunc = isNegative;
        UnitReLu rl;
        doIt1(vec.begin(), vec.end(), isNegativeFunc, rl);
        
        for (auto it = vec.cbegin(); it != vec.cend(); ++it)
            cout << *it << ' ';
        cout << endl;
        
    }

}
