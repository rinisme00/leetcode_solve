// Given an integer x, return true if x is a palindrome, and false otherwise
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int reversed = 0;
        int original = x;
        while (x != 0) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        return original == reversed;
    }
};

int main() {
    Solution solution;

    int x;
    cout << "Enter an integer to check if it is palindromic or not: ";
    cin >> x;

    bool result = solution.isPalindrome(x);

    cout << (result ? "True" : "False") << endl;
    return 0;
}