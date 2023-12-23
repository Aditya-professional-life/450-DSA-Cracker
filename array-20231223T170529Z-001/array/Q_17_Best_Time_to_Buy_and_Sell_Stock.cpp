#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int maxProfit = 0;
        int minimumNumber = arr[0];

        for (int i = 0; i < n; i++) {
            maxProfit = max(maxProfit, arr[i] - minimumNumber);
            minimumNumber = min(minimumNumber, arr[i]);
        }
        return maxProfit;
    }
};

int main() {
    // Example usage
    Solution solution;

    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Example 1: " << solution.maxProfit(prices1) << endl;

    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Example 2: " << solution.maxProfit(prices2) << endl;

    return 0;
}
