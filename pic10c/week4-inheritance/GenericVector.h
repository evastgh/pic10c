#include <vector>
#include <iostream>
#include <string>

namespace std {
    class GenericVectorBase {
    public:
        string name;
        GenericVectorBase(const string& name) : name(name) {}
    };
    
    template <class Type>
    class GenericVector : public GenericVectorBase { // what'd happen if we forgot keyword 'public'?
    public:
        using Base = GenericVectorBase;
        vector<Type> inner_vec;
        
        GenericVector(const string& name) : Base(name) {}
        GenericVector(const string& name, size_t count, Type entry) : Base(name), inner_vec(count, entry) {}
    };
    
    void genericVectorTest() {
        vector<GenericVectorBase*> pointers;
        
        GenericVectorBase* vec1 = new GenericVector<double>("DoubleVec", 10, 3.14);
        GenericVectorBase* vec2 = new GenericVector<int>("IntVec", 7, 3);
        pointers.emplace_back(vec1);
        pointers.emplace_back(vec2);

        for (auto it = pointers.begin(); it != pointers.end(); ++it)
            cout << (*it)->name << endl;
    }
}
