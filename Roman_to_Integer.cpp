#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        vector<int> values(26, 0);
        
        values['I' - 'A'] = 1;
        values['V' - 'A'] = 5;
        values['X' - 'A'] = 10;
        values['L' - 'A'] = 50;
        values['C' - 'A'] = 100;
        values['D' - 'A'] = 500;
        values['M' - 'A'] = 1000;

        int result = 0;

        for (size_t i = 0; i < s.size(); ++i) {
            int current = values[s[i] - 'A'];

            if (i + 1 < s.size() && current < values[s[i + 1] - 'A']) {
                result -= current;
            } else { 
                result += current;
            }
        }

        return result;
    }
};

int main () {
    Solution solution;
    string s;
    
    cout << "Enter a roman numeral: ";
    cin >> s;
    
    cout << solution.romanToInt(s) << endl;
    return 0;
}