//
//  moveTest.hpp
//  pic10c
//
//  Created by Stephanie Wang on 6/5/18.
//  Copyright © 2018 srw. All rights reserved.
//

#ifndef moveTest_hpp
#define moveTest_hpp

//Extra office hour:
//Next Monday  6/11 3-4:30
//Next Tuesday 6/12 3-4:30

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>

namespace std {
    struct Loud {
        size_t size;
        int* data;
        
        Loud(size_t size = 0) : size(size) {
            data = size ? new int[size] : nullptr;
            cout << "Loud defaultly constructed. " << endl;
        }
        
        ~Loud() {
            delete[] data;
            cout << "Loud defaultly destructed. " << endl;
        }
        
        Loud(const Loud& other) : size(other.size) {
            data = size ? new int[size] : nullptr;
            copy(other.data, other.data + other.size, data);
            cout << "Loud deeply copy-constructed. " << endl;
        }
        
        Loud(Loud&& other) : size(other.size) {
            data = other.data;
            other.data = nullptr;
            cout << "Loud move-constructed. " << endl;
        }
        
        /* copy-swap idiom */
        Loud& operator=(Loud other) {
            swap(*this, other);
            cout << "Loud copy-swap-assigned. " << endl;
            return *this;
        }
        
        //        /* the naive (ugly) assignment operator */
        //        Loud& operator=(const Loud& other) {
        //            if (this != &other) {
        //                this->size = other.size;
        //                delete[] data;
        //                data = size ? new int[size] : nullptr;
        //                copy(other.data, other.data + other.size, data);
        //            }
        //            return *this;
        //        }
        
        void swap(Loud& first, Loud& second) {
            std::swap(first.size, second.size);
            std::swap(first.data, second.data);
            cout << "Loud swapped. " << endl;
        }
        
    };

    Loud makeLoud() { return Loud(7); }

    template <class Func1, class Func2>
    void someFunc(Loud&& other, Func1 lam1, Func2 lam2) {
        lam2();
        cout << "someFunc ending. " << endl;
    }

    struct Foo {
        Foo () { cout << "Foo foo" << endl; }
    };

    void moveTest() {
        someFunc(makeLoud(), Foo(), []() { cout << "Lam speaking. " << endl; });
    }
}

#endif /* moveTest_hpp */
