#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sorting intervals based on the start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        int i = 0;

        for (auto interval : intervals) {
            if (ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            } else {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};

int main() {
    // Example usage
    Solution solution;

    vector<vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result1 = solution.merge(intervals1);

    cout << "Example 1: ";
    for (const auto& interval : result1) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    vector<vector<int>> intervals2 = {{1, 4}, {4, 5}};
    vector<vector<int>> result2 = solution.merge(intervals2);

    cout << "Example 2: ";
    for (const auto& interval : result2) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
