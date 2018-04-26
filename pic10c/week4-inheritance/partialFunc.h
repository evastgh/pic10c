#ifndef PARTIAL_FUNC
#define PARTIAL_FUNC
#include <array>
#include <vector>
#include <iostream>
#include <string>

namespace std {

    template <class Type, size_t times>
    void print(const Type& input) {
        for (size_t i = 0; i < times; ++i)
            cout << input << endl;
    }
//    /* Can't do this! No Function template partial specialization allowed! */
//    template <class Type>
//    void print<Type, 0>(const Type& input) {
//        cout << "Nothing" << endl;
//    }
    
    /* instead, use a partially specialized functor */
    /* functor? https://www.urbandictionary.com/define.php?term=functor */
    template <class Type, size_t times>
    struct Print{
        void operator()(const Type& input) {
            for (size_t i = 0; i < times; ++i)
                cout << input << endl;
        }
    };
    
    template <class Type>
    struct Print<Type, 0> {
        string msg = string("hi");
        void operator()(const Type& input) {
            cout << "Nothing" << endl;
        }
        void f(bool) { cout << msg << endl;}
    };

    void partialFuncTest() {
        print<string, 0>("hello");
    
        Print<string, 0> print_class;
        print_class("hello");
        print_class.f(true);
    }
    
}
#endif
