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
        assert(*iter >= current_range.second); //, "convertSorted only works with sorted data. ");
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
}
