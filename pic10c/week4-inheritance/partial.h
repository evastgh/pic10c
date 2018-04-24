#include <array>
#include <vector>
#include <iostream>
#include <string>

namespace std {
    // see http://en.cppreference.com/w/cpp/container/array for documentation on std::array
    
    class GenericArrayBase {
    public:
        string name;
        GenericArrayBase(const string& name) : name(name) {}
    };

    template <class Type, size_t size>
    class GenericArray : public GenericArrayBase {
    public:
        using Base = GenericArrayBase;
        array<Type, size> inner_arr;
        
        GenericArray(const string& name) : Base(name) {}
        GenericArray(const string& name, Type entry);
    };
    
    template <class Type, size_t size>
    GenericArray<Type, size>::GenericArray(const string& name, Type entry) : Base(name) {
        for (size_t q = 0; q < size; ++q)
            inner_arr[q] = entry;
    }
    
    template <>
    GenericArray<double, 10>::GenericArray(const string& name, double entry) : Base(name + " postfix-- double & 10") {
        for (size_t q = 0; q < 10; ++q)
            inner_arr[q] = entry;
    }

//    /* the following won't work: can't do partial specialization of a class member without partial specialization of the class itself */
//    template <class Type>
//    GenericArray<Type, 10>::GenericArray(const string& name, Type entry) : Base(name + "postfixsize10") {
//        for (size_t q = 0; q < 10; ++q)
//            inner_arr[q] = entry;
//    }
    
    /* partial specialization of the class */
    template <class Type>
    class GenericArray<Type, 10> : public GenericArrayBase {
    public:
        using Base = GenericArrayBase;
        array<Type, 10> inner_arr;
        
        GenericArray(const string& name) : Base(name) {}
        GenericArray(const string& name, Type entry) : Base(name + " postfix-- fixed size 10") {
            for (size_t q = 0; q < 10; ++q)
                inner_arr[q] = entry;
        }
    };
    template <size_t size>
    class GenericArray<double, size> : public GenericArrayBase {
    public:
        using Base = GenericArrayBase;
        array<double, size> inner_arr;
        
        GenericArray(const string& name) : Base(name) {}
        GenericArray(const string& name, double entry) : Base(name + " postfix-- double") {
            for (size_t q = 0; q < size; ++q)
                inner_arr[q] = entry;
        }
    };
    

    void genericArrayTest() {
        vector<GenericArrayBase*> pointers;
        
        GenericArrayBase* vec1 = new GenericArray<double, 10>("Double10Arr", 3.14); // with this give us postfix "double & 10" or "fixed size 10" ???
        GenericArrayBase* vec2 = new GenericArray<double, 6>("Double6Arr", 3.14);
        GenericArrayBase* vec3 = new GenericArray<int, 7>("Int7Arr", 3);
        GenericArrayBase* vec4 = new GenericArray<int, 10>("Int10Arr", 3);
        pointers.emplace_back(vec1);
        pointers.emplace_back(vec2);
        pointers.emplace_back(vec3);
        pointers.emplace_back(vec4);
        pointers.emplace_back(new GenericArray<int, 7>("Int7Arr", 3));
        
        for (auto it = pointers.begin(); it != pointers.end(); ++it)
            cout << (*it)->name << endl;
    }
}
