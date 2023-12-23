#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverse(vector<int>& nums, int i, int n) {
        int start = i;
        int end = n - 1;
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = n - 1;

            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        reverse(nums, i + 1, n);
    }
};

int main() {
    // Example usage
    Solution solution;

    vector<int> nums1 = {1, 2, 3};
    solution.nextPermutation(nums1);
    cout << "Example 1: ";
    for (const auto& num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {3, 2, 1};
    solution.nextPermutation(nums2);
    cout << "Example 2: ";
    for (const auto& num : nums2) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums3 = {1, 1, 5};
    solution.nextPermutation(nums3);
    cout << "Example 3: ";
    for (const auto& num : nums3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
