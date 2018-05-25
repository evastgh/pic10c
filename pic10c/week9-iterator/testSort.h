#include <iostream>
#include <vector>
#include <algorithm>

namespace std {
    class IntWrapper {
        int data;
    public:
        IntWrapper(int data) : data(data) {}
        int getData() const { return data; }
        bool operator<(const IntWrapper& other) const { return this->data < other.data; }
    };
    
    void testSort() {
        vector<IntWrapper> vec;
        vec.reserve(10);
        for (int i = 9; i >= 0; --i)
            vec.emplace_back(IntWrapper(i));
        
        cout << "Starting state: ";
        for (auto& iw : vec)
            cout << iw.getData() << ' ';
        cout << endl;
        
        sort(vec.begin(), vec.end());
        
        cout << "Ending state: ";
        for (auto& iw : vec)
            cout << iw.getData() << ' ';
        cout << endl;
    }
}








