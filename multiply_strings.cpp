/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented 
as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int converted_num1 = num1.size(), converted_num2 = num2.size();
        vector<int> result(converted_num1 + converted_num2, 0);

        for (int i = converted_num1 - 1; i >= 0; --i) {
            for (int j = converted_num2 - 1; j >= 0; --j) {
                int multi = (num1.at(i) - '0') * (num2.at(j) - '0');
                int sum = multi + result.at(i + j + 1);
                result.at(i + j + 1) = sum % 10;
                result.at(i + j) += sum / 10;
            }    
        }

        string product = "";
        for (int i = 0; i < result.size(); ++i) {
            if (!(product.empty() && result.at(i) == 0)) {
                product += to_string(result.at(i));
            }
        }

        return product;
    }
};

int main () {
    Solution solution;
    string num1, num2;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    string product = solution.multiply(num1, num2);
    cout << "Product: " << product << endl;

    return 0;
}