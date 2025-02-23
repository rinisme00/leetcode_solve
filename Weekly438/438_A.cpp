#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool hasSameDigits(string s) {
        while(s.length() > 2) {
            string newS = "";
            for (size_t i = 0; i < s.length() - 1; i++) {
                int res = (s[i] - '0' + s[i+1] - '0') % 10;
                newS += to_string(res);
            }
            s = newS;
        }
        return s[0] == s[1];
    }
};

int main () {
    Solution sol;
    
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    
    cout << (sol.hasSameDigits(s) ? "true" : "false") << endl;
    return 0;
}