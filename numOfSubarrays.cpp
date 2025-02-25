/*
Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 10^9 + 7
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int oddCount = 0, evenCount = 1, ans = 0, prefixParity = 0;

        for (int num : arr) {
            prefixParity ^= (num % 2); 

            if (prefixParity) {  
                ans = (ans + evenCount) % MOD;
                oddCount++;
            } else {
                ans = (ans + oddCount) % MOD;
                evenCount++;
            }
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    cout << sol.numOfSubarrays(arr) << "\n";

    return 0;
}

