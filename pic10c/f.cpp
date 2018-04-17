#include "f.h"
#include <iostream>
#include <string>

namespace std {

template <class T>
void f(T input)
{
    cout << input << endl;
}

    template void f<unsigned int>(unsigned int);
    template void f<string>(string);
    template void f<double>(double);
}
