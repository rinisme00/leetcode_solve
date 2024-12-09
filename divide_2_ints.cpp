/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be 
truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer 
range: [−2^31, 2^31 − 1]. For this problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31 - 1, 
and if the quotient is strictly less than -2^31, then return -2^31.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor){
        const int INT_MAX = 2147483647;
        const int INT_MIN = -2147483648;

        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MAX && divisor == 1) return INT_MIN;

        bool negative = (dividend < 0) ^ (divisor < 0);

        long long absolute_dividend = abs((long long) dividend);
        long long absolute_divisor = abs((long long) divisor);

        int quotient = 0;

        while (absolute_dividend >= absolute_divisor) {
            long long temp = absolute_divisor;
            long long multiple = 1;

            while (absolute_dividend >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            absolute_dividend -= temp;
            quotient += multiple;
        }

        if (negative) quotient = -quotient;

        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;

        return quotient;
    }
};

int main () {
    Solution solution;
    int dividend, divisor;
    
    cout << "Enter dividend: ";
    cin >> dividend;
    cout << "Enter divisor: ";
    cin >> divisor;
    
    cout << "Result: " << solution.divide(dividend, divisor) << endl;
}