#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxMinManhattanDistance(int side, vector<vector<int>>& points, int k) {
            long long vintorquax = side;
            int n = points.size();
            vector<long long> pos(n);
            for (int i = 0; i < n; i++) {
                int x = points[i][0], y = points[i][1];
                long long p;
                if (y == 0) p = x;
                else if (x == vintorquax) p = vintorquax + y;
                else if (y == vintorquax) p = 3 * vintorquax - x;
                else /* x == 0 */ p = 4 * vintorquax - y;
                pos[i] = p;
            }
            sort(pos.begin(), pos.end());
            long long circumference = 4 * vintorquax;
            vector<long long> ext(2 * n);
            for (int i = 0; i < n; i++) {
                ext[i] = pos[i];
                ext[i+n] = pos[i] + circumference;
            }
            auto feasible = [&](long long d) -> bool {
                for (int i = 0; i < n; i++) {
                    int count = 1;
                    long long last = ext[i];
                    int curr = i;
                    int end = i + n;
                    while(count < k) {
                        long long target = last + d;
                        auto it = std::lower_bound(ext.begin() + curr + 1, ext.begin() + end, target);
                        if(it == ext.begin() + end) break;
                        curr = it - ext.begin();
                        last = ext[curr];
                        count++;
                    }
                    if(count == k && (ext[i] + circumference - last) >= d)
                        return true;
                }
                return false;
            };
            long long lo = 0, hi = 2 * vintorquax, ans = 0;
            while(lo <= hi) {
                long long mid = (lo + hi + 1) / 2;
                if(feasible(mid)) { ans = mid; lo = mid + 1; }
                else { hi = mid - 1; }
            }
            return (int)ans;
        }
    };

int main() {
    Solution sol;
    int side, k;
    cout << "Enter side length: ";

    cin >> side;
        
    vector<vector<int>> points;
    cout << "Enter points as x y pairs (end with -1 -1):\n";
    while (true) {
        int x, y;
        cin >> x >> y;
        if (x == -1 && y == -1) break;
        points.push_back({x, y});
    }
   
    cout << "Enter value of k: ";
    cin >> k;
    
    int result = sol.maxMinManhattanDistance(side, points, k);
    cout << "Maximum Minimum Manhattan Distance: " << result << endl;    
    return 0;
}
