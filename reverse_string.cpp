/*
Write a function that reverses a string. The input string is given as an array of characters s
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;

        for (char c : s) {
            st.push(c);
        }

        for (int i = 0; i < s.size(); i++) {
            s[i] = st.top();
            st.pop();
        }
    }
};

int main() {
    Solution solution;
    vector<char> s = {};

    char c;

    while (cin.get(c) && c != '\n') {
        s.push_back(c);
    }

    solution.reverseString(s);
    for (char ch : s) cout << ch;
    cout << endl;

    return 0;
}