/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public: 
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int arr[26] = {0};
        
        for (char c : s) arr[c - 'a']++;

        for (char c : t) {
            arr[c - 'a']--;
            if(arr[c - 'a'] < 0) return false;
        }

        return true;
    }
};

int main() {
    Solution solution;
    string s, t;
    
    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;
    
    cout << (solution.isAnagram(s, t)? "true" : "false") << endl;
    
    return 0;
}