//
//  findEndTest.hpp
//  pic10c
//
//  Created by Stephanie Wang on 5/29/18.
//  Copyright © 2018 srw. All rights reserved.

//ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2)
//ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate pred)

#ifndef findEndTest_hpp
#define findEndTest_hpp
#include <algorithm>
#include <string>
#include <iterator>
#include <iostream>
#include <vector>
using namespace std;

class Twice
{
public:
    bool operator()(size_t first, size_t second) const
    {
        return first == (second << 1);
    }
};
void findEndTest()
{
    string sarr[] =
    {
        "alpha", "bravo", "charley", "delta", "echo",
        "foxtrot", "golf", "hotel",
        "foxtrot", "golf", "hotel",
        "india", "juliet", "kilo"
    };
    string search[] =
    {
        "foxtrot",
        "golf",
        "hotel"
    };
    string  *last = sarr + sizeof(sarr) / sizeof(string);
    
//    copy
//    (
//     find_end(sarr, last, search, search + 3),   // sequence starting
//     last, ostream_iterator<string>{ cout, " " } // at 2nd 'foxtrot'
//     );
//    cout << '\n';
    
    size_t range[] = {2, 4, 6, 8, 10, 4, 6, 8, 10};
    size_t nrs[]   = {2, 3, 4};
    
//    copy                // sequence of values starting at last sequence
//    (                   // of range[] that are twice the values in nrs[]
//     find_end(range, range + 9, nrs, nrs + 3, Twice{}),
//     range + 9, ostream_iterator<size_t>{ cout, " " }
//     );
//    cout << '\n';
    
    vector<size_t> record;
    auto tw = [&record](size_t first, size_t second) {
        if (first == (second << 1))
            return true;
        else {
            record.push_back(first);
            return false;
        }
    };
    copy                // sequence of values starting at last sequence
    (                   // of range[] that are twice the values in nrs[]
     find_end(range, range + 9, nrs, nrs + 3, tw),
     range + 9, ostream_iterator<size_t>{ cout, " " }
     );
    cout << '\n';
    
    cout << "The record = ";
    for (size_t i : record)
        cout << i << ' ';
}
#endif /* findEndTest_hpp */
