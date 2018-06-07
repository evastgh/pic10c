#ifndef lam_hpp
#define lam_hpp
#include <iostream>
#include <vector>

class MyClass {
    int data;
    MyClass(int input) : data(intput) {
        auto lam = [this]() { cout << data; }
        lam();
    }
    std::function<int&()> giveData() {
        return [this]() { return data; };
    }
    int& giveData() {
        return data;
    }
};
//bool largerThanSomething(int input) { return input > something; }
//struct largerThanFunctor {
//    int something;
//    largerThanFunctor(int something) : something(something) {}
//    bool operator()(int input) { return input > something; }
//};
//struct largerThanRefFunctor {
//    int& something;
//    largerThanFunctor(int& something) : something(something) {}
//    bool operator()(int input) { return input > something; }
//};

namespace std {
    void testLam() {
//
//        int something = 4;
//        largerThanFunctor(4);
//        auto largerThanLam = [something](int input) { return input > something; };
//        auto largerThanRefLam = [&something](int input) { return input > something; };
//
//
//        largerThanLam(5);
//        largerThanRefLam(5);
//
        auto addLam = [](int a, int b) { return a+b; };
        
        cout << addLam(10, 12);
        
        vector<double> vec(10, 3.14);
        vec.emplace_back(10.0);
        vec.emplace_back(12.4);
        copy(vec.begin(), vec.end(), ostream_iterator<double>(cout, " "));
        
        double sum = 0.0;
        auto accumulate = [&sum](int a) { sum += a; };
        for (double val : vec)
            accumulate(val);
        cout << "The accumulated value is " << sum << endl;
        
        double threshold = 5.0;
        auto largerThanT = [threshold](double a) -> bool { return a > threshold; };
        copy_if(vec.begin(), vec.end(), ostream_iterator<double>(cout, " "), largerThanT);
    }
}

#endif /* lam_hpp */
