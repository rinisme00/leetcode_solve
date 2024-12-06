// Given an integer x, return true if x is a palindrome, and false otherwise
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        return x == reversed || x == reversed / 10;
    }
};

int main() {
    Solution solution;

    int x;
    cout << "Enter an integer to check if it is palindromic or not: ";
    cin >> x;

    bool result = solution.isPalindrome(x);

    cout << (result ? "true" : "false") << endl;
    return 0;
}