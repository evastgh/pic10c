//
//  moveDemo.hpp
//  pic10c
//
//  Created by Stephanie Wang on 6/7/18.
//  Copyright © 2018 srw. All rights reserved.
//

#ifndef moveDemo_hpp
#define moveDemo_hpp

#include "moveTest.h"
#include <vector>

namespace std {
    struct MyClassBase {
        const string name;
        MyClassBase(const string& name) : name(name) {}
        virtual void something() = 0;
        virtual ~MyClassBase() {}
    };

    template <class T>
    struct MyClass : MyClassBase {
        using Base = MyClassBase;
        vector<T> data;
        MyClass() = default;
        MyClass(const string& name, vector<T>&& array) : Base(name), data(move(array)) {
            cout << "Move constructor called. " << endl;
        }
//        MyClass(MyClass&& other) = delete;
//        MyClass(const string& name, const vector<T>& array) = delete;
//        MyClass(const string& name, const vector<T>& array) : Base(name), data(array) {
//            cout << "Copy constructor called. " << endl;
//        }
        void something() override {}
        ~MyClass() {}
    };
    
    void moveDemo() {
        vector<Loud> loud_array{Loud(1), Loud(2)};
        
        cout << "=====\n";
        MyClass<Loud> loud_mc("loud", move(loud_array)); // something is wrong here
        
        cout << "=====\n";
        vector<unique_ptr<MyClassBase>> vecmc;

        cout << "=====\n";
        vector<char> array{'a', 'b', 'c'};
        MyClass<char> mc("name", move(array));

        cout << "=====\n";
        unique_ptr<MyClass<char>> ptr = make_unique<MyClass<char>>(move(mc));
        vecmc.push_back(move(ptr));

        cout << "=====\n";
        vecmc.emplace_back(make_unique<MyClass<Loud>>(move(loud_mc)));
        
        
        cout << "=====\n";
        for (auto& up : vecmc) {
            if (dynamic_cast<MyClass<char>*>(up.get()))
                up->something();
        }
        

        
        cout << "=====\n";
    }
}

#endif /* moveDemo_hpp */
