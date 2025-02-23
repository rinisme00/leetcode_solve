
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string &s) {
        int n = s.length(), N = n - 2, f0 = 0, f1 = 0;
        
        for (int j = 0; j <= N; j++) {
            int c = binomMod10(N, j);
            f0 = (f0 + c * (s[j] - '0')) % 10;
            f1 = (f1 + c * (s[j + 1] - '0')) % 10;
        }

        return f0 == f1;
    }

private:
    int binomMod10(int n, int k) {
        int r2 = binomMod2(n, k), r5 = binomMod5(n, k);
        for (int x = 0; x < 10; x++)
            if (x % 2 == r2 && x % 5 == r5) return x;
        return 0;
    }

    int binomMod2(int n, int k) {
        return ((n & k) == k) ? 1 : 0;
    }

    int binomMod5(int n, int k) {
        int t[5][5] = {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 1, 4, 1}};
        int res = 1;
        while (n > 0 || k > 0) {
            int nd = n % 5, kd = k % 5;
            if (kd > nd) return 0;
            res = (res * t[nd][kd]) % 5;
            n /= 5; k /= 5;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    Solution sol;
    cout << (sol.hasSameDigits(s) ? "true" : "false") << '\n';

    return 0;
}



