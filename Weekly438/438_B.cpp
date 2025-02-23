#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
            vector<int> elements;

            for (int i = 0; i < grid.size(); i++) {
                sort(grid[i].rbegin(), grid[i].rend());
                int count = min(limits[i], (int)grid[i].size());
                for (int j = 0; j < count; j++) {
                    elements.push_back(grid[i][j]);
                } 
            }
            sort(elements.rbegin(), elements.rend());

            long long sum = 0;
            for (int i = 0; i < min(k, (int)elements.size()); i++) {
                sum += elements[i];
            }

            return sum;
        }
    };

int main () {
    Solution sol;
    
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> limits(n);
    for (int i = 0; i < n; i++) {
        cin >> limits[i];
    }

    cin >> k;

    cout << sol.maxSum(grid, limits, k) << endl;

    return 0;
}