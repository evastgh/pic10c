#include "auto.h"
#include <vector>
#include <iostream>

namespace std {
int autoTest() {
    int t = 0;
    vector<Abcdefghijklmnopqrstuvwxyz<int>> vec(0, Abcdefghijklmnopqrstuvwxyz<int>(t));
    for (auto it = vec.begin(); it != vec.end(); ++it)
        cout << it->t << endl;
    
    return 0;
}
}
