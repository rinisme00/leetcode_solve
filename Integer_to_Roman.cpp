/*
Seven different symbols represent Roman numerals with the following values:
Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> rom = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string result;

        for (size_t i = 0; i < val.size(); ++i) {
            while (num >= val[i]) {
                result += rom[i];
                num -= val[i];
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    
    int num {};
    cout << "Enter a number to convert to Roman numeral: ";
    cin >> num;

    cout << "Roman numeral for " << num << " is: " << solution.intToRoman(num) << endl;
    return 0;
}