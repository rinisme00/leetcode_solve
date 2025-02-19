/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m, mid = (m + n + 1) / 2;

        while (left <= right) {
            int i = (left + right) / 2;
            int j = mid - i;

            int left1 = (i > 0) ? nums1[i - 1] : INT_MIN;
            int right1 = (i < m) ? nums1[i] : INT_MAX;
            int left2 = (j > 0) ? nums2[j - 1] : INT_MIN;
            int right2 = (j < n) ? nums2[j] : INT_MAX;
    
            if (left1 <= right2 && left2 <= right1) {
                if ((m + n) % 2 == 0) 
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                else 
                    return max(left1, left2);
            } 
            else if (left1 > right2) 
                right = i - 1;
            else 
                left = i + 1;
        }
        
        return 0.0;        
    }
};

vector<int> input_array() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> arr;
    int num;
    while(iss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    Solution solution;
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> nums1 = input_array();
    vector<int> nums2 = input_array();

    double median = solution.findMedianSortedArrays(nums1, nums2);
    cout << median << endl;

    return 0;
}