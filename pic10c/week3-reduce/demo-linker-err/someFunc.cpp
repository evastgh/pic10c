#include "someFunc.h"
#include <iostream>
#include <string>

namespace std {

    template <class T>
    void someFunc(T input)
    {
        cout << input << endl;
    }

    // without the following explicit instantiations, we will get linker error from linkerErrTest()
    template void someFunc<unsigned int>(unsigned int);
    template void someFunc<string>(string);
    template void someFunc<double>(double);
}
