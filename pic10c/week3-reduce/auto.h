#include <vector>
#include <iostream>

namespace std {

    template <class T>
    class Abcdefghijklmnopqrstuvwxyz {
    public:
        T t;
        Abcdefghijklmnopqrstuvwxyz(T t) : t(t) {}
    };
    
    void autoTest() {
        int t = 0;
        vector<Abcdefghijklmnopqrstuvwxyz<int>> vec(0, Abcdefghijklmnopqrstuvwxyz<int>(t));
        for (vector<Abcdefghijklmnopqrstuvwxyz<int>>::iterator it = vec.begin(); it != vec.end(); ++it)
            cout << it->t << endl;
        
        for (auto it = vec.begin(); it != vec.end(); ++it)
            cout << it->t << endl;
    }

}
