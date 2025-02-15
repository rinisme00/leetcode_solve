/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number 
of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, 
nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 
0 and should be ignored. nums2 has a length of n.
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i -= 1;
            } else {
                nums1[k] = nums2[j];
                j -= 1;
            }
            k -= 1;
        }
    }
};

int main() {
    Solution solution;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m, n;
    cin >> m >> n;

    vector<int> nums1(m + n, 0);
    vector<int> nums2(n);

    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    solution.merge(nums1, m, nums2, n);

    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
