// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the 
// signed 32-bit integer range [-2^31, 2^31 - 1], then return 0

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long reversed {0};
        while (x != 0) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        return (reversed > 2147483647 || reversed < -2147483647) ? 0 : (int)reversed;
    }
};

int main () {
    Solution solution;
    int x {};
    cin >> x;

    cout << solution.reverse(x) << endl;
    return 0;
}