#ifndef GENERIC_VECTOR
#define GENERIC_VECTOR

#include <vector>
#include <iostream>
#include <string>

namespace std {
//    /* this is bad because you need the Type template everytime */
//    template <class Type>
//    class GenericVector {
//    public:
//        string name;
//        vector<Type> inner_vec;
//        GenericVector(const string& name, size_t count, Type entry) : name(name), inner_vec(count, entry) {}
//    };
    
    /* introduce-- inheritence! */
    class GenericVectorBase {
    public:
        string name;
        GenericVectorBase(const string& name) : name(name) {}
        virtual void doNothing () {}
    };

    template <class Type>
    class GenericVector : public GenericVectorBase { // what'd happen if we forgot keyword 'public'?
    public:
        using Base = GenericVectorBase;
        vector<Type> inner_vec;

        GenericVector(const string& name) : Base(name) {}
        GenericVector(const string& name, size_t count, Type entry) : Base(name), inner_vec(count, entry) {}
        void doNothing () {
            name += "haha";
        }
    };
    
    void genericVectorTest() {
//        GenericVector<double> vec1("DoubleVec", 10, 3.14);
//        GenericVector<int> vec2("IntVec", 7, 3);
//
//        cout << vec1.name << endl;
//        cout << vec2.name << endl;
        
        vector<GenericVectorBase*> pointers;
        
        GenericVectorBase* vec1 = new GenericVector<double>("DoubleVec", 10, 3.14);
        GenericVectorBase* vec2 = new GenericVector<int>("IntVec", 7, 3);
        pointers.emplace_back(vec1);
        pointers.emplace_back(vec2);
        
        for (auto it = pointers.begin(); it != pointers.end(); ++it) {
            cout << (*it)->name << endl;
            (*it)->doNothing();
            cout << (*it)->name << endl;
            delete *it;
        }
    }
}

#endif
