#include <iostream>
#include <cassert>
#include <utility>
#include <vector>
#include <stack>
#include <string>

namespace std {
    bool checkParenthesis(const string& input)
    {
        stack<char> record;
        for (auto iter = input.cbegin(); iter != input.cend(); ++iter) {
            if (*iter == '(') {
                record.push(*iter);
            }
            else if (*iter == '[')
                record.push(*iter);
            else if (*iter == ')') {
                if (record.top() == '(')
                    record.pop();
                else
                    return false;
            }
            else if (*iter == ']') {
                if (record.top() == '[')
                    record.pop();
                else
                    return false;
            }
        }
        return true;
    }

    void parenthesisTest () {
        cout << "Please input the string: ";
        string msg;
        getline(cin, msg);
        
        cout << "To verify, the input is " << msg << endl;
        if (checkParenthesis(msg))
            cout << "The paretheses match!" << endl;
        else
            cout << "Naaaahhhhh" << endl;
    }
}
