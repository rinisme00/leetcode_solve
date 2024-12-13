/*
Given a string s, find the length of the longest substring (A substring is a contiguous non-empty sequence of characters 
within a string.) without repeating characters.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int max_length = 0;
        vector<int> index(128, -1);
        int left = 0;

        for (int right = 0; right < n; right++) {
            if (index[s[right]] >= left) {
                left = index[s[right]] + 1;
            }
            index[s[right]] = right;
            max_length = max(max_length, right - left + 1);
        }
        return max_length;   
    }
};

int main() {
    Solution solution;
    string s;
    getline(cin, s);
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}