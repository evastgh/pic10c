#include <iostream>
#include <list>
#include <numeric>
#include "lists.h"

namespace std {
    void testInnerProd() {
        list<double> l1, l2;
        readList(l1);
        readList(l2);
        
        cout << "The inner product of the two lists is " << inner_product(l1.begin(), l1.end(), l2.begin(), 0.0);
    }
}
