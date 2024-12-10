#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return n;

        int i = 1, j = 1;
        while (j < n) {
            if (nums[i] != nums[j-1]) {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }

        return i;
    }
};

int main () {
    Solution solution;
    int size;
    cin >> size;
    vector<int> nums(size);

    for (int i = 0; i < nums.size(); i++){
        cin >> nums[i];
    }
    int n = solution.removeDuplicates(nums);
    for (int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    return 0;
}