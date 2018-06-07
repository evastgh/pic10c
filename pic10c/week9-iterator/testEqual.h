//
//  testEqual.hpp
//  pic10c
//
//  Created by Stephanie Wang on 5/29/18.
//  Copyright © 2018 srw. All rights reserved.
//

#ifndef testEqual_hpp
#define testEqual_hpp

#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

class CaseString
{
public:
    bool operator()(string const &first,
                    string const &second) const
    {
        return !strcasecmp(first.c_str(), second.c_str());
    }
};
void testEqual()
{
    string first[] =
    {
        "Alpha", "bravo", "Charley", "delta", "Echo",
        "foxtrot", "Golf", "hotel"
    };
    string second[] =
    {
        "alpha", "bravo", "charley", "delta", "echo",
        "foxtrot", "golf", "hotel"
    };
    string *last = first + sizeof(first) / sizeof(string);
    
    auto cs = [](string const &first, string const &second)
    {
        return !strcasecmp(first.c_str(), second.c_str());
    };
    
    string perturb = "ha";
    auto cp = [&perturb = static_cast<const string&>(perturb)](string const &first, string const &second)
    {
        string first_perturbed = first + perturb;
        return first_perturbed == second;
    };
    
    cout << "The elements of `first' and `second' are pairwise " <<
    (equal(first, last, second) ? "equal" : "not equal") <<'\n' <<
    "compared case-insensitively, they are " <<
    (equal(first, last, second, CaseString{}) ? "equal" : "not equal") << '\n' <<
    "lambda expression comparison, they are " <<
    (equal(first, last, second, cs) ? "equal" : "not equal") << '\n' <<
    "perturbed comparison, they are " <<
    (equal(first, last, second, cp) ? "equal" : "not equal") << '\n'
    ;
}
#endif /* testEqual_hpp */
