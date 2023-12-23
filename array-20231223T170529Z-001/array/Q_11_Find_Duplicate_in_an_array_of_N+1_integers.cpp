#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

 int n = nums.size();
        int arr[n + 2];
        for (int j = 0; j < n + 2; j++) {
            arr[j] = 0;
        }

        for (int i = 0; i < n; i++) {
            arr[nums[i]]++;
        }
        for (int i = 1; i <= n + 1; i++) {
            if (arr[nums[i]] > 1) {
                return nums[i];
            }
        }
        return -1;
    }
    
};

int main() {
    // Example usage
    Solution solution;

    vector<int> nums1 = {1, 3, 4, 2, 2};
    cout << "Example 1: " << solution.findDuplicate(nums1) << endl;

    vector<int> nums2 = {3, 1, 3, 4, 2};
    cout << "Example 2: " << solution.findDuplicate(nums2) << endl;

    return 0;
}
