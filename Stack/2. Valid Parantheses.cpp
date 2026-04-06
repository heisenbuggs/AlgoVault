/**
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 * 1. Open brackets must be closed by the same type of brackets.
 * 2. Open brackets must be closed in the correct order.
 * 3. Every close bracket has a corresponding open bracket of the same type.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty() || isNotMatch(c, st.top())) return false;
                st.pop();
            }
        }
        return st.empty();
    }

    bool isNotMatch(char c, char top) {
        return (c == ')' && top != '(') ||
               (c == '}' && top != '{') ||
               (c == ']' && top != '[');
    }
};