#ifndef CONVERT_SORTED
#define CONVERT_SORTED
#include <vector>
#include <utility>
#include <cassert>
#include <iostream>

namespace std {
    template <class TContainer>
    vector<pair<int, int> > convertSorted(const TContainer& set)
    {
        vector<pair<int, int> > return_value;
        auto iter = set.cbegin();
        pair<int, int> current_range(*iter, *iter + 1);
        cout << "[" << *iter << ", ";

        for (++iter; iter != set.cend(); ++iter) {
            assert(*iter >= current_range.second);
            if (*iter == current_range.second) {
                current_range.second = *iter + 1;
            }
            else {
                return_value.push_back(current_range);
                cout << current_range.second << ") \n[" << *iter << ", ";
                current_range.first = *iter;
                current_range.second = *iter + 1;
            }
        }
        cout << current_range.second << ")\n";
        return_value.push_back(current_range);

        return return_value;
    }

    void convertTest () {
        cout << "Please input number of integers: ";
        size_t size;
        cin >> size;
        
        vector<int> some_set;
        cout << "Please input the integers, separated by space. " << endl;
        for (size_t i = 0; i < size; ++i) {
            int entry;
            cin >> entry;
            some_set.push_back(entry);
        }
        sort(some_set.begin(), some_set.end());
        
        cout << "To verify, the input is ";
        for (auto it = some_set.cbegin(); it != some_set.cend(); ++it)
            cout << *it << ' ';
        cout << endl;
        
        vector<pair<int, int> > ranges = convertSorted(some_set);
        // cout << "The converted ranges is: ";
        // for (auto it = ranges.cbegin(); it != ranges.cend(); ++it)
        //     cout << "[" << it->first << ", " << it->second << ") " << endl;
    }
}
#endif
