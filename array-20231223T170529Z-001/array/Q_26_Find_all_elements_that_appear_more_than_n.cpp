#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Moore's voting algorithm
        vector<int> ans;
        int el1;
        int el2;
        int count1 = 0;
        int count2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (count1 == 0 && nums[i] != el2) {
                el1 = nums[i];
                count1++;
            } else if (count2 == 0 && nums[i] != el1) {
                el2 = nums[i];
                count2++;
            } else if (count1 > 0 && nums[i] == el1) {
                count1++;
            } else if (count2 > 0 && nums[i] == el2) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == el1) {
                count1++;
            } else if (nums[i] == el2) {
                count2++;
            }
        }

        if (count1 > nums.size() / 3) {
            ans.push_back(el1);
        }
        if (count2 > nums.size() / 3) {
            ans.push_back(el2);
        }

        return ans;
    }
};

int main() {
    // Example usage
    Solution solution;

    vector<int> nums1 = {3, 2, 3};
    vector<int> result1 = solution.majorityElement(nums1);
    cout << "Example 1: ";
    for (const auto& num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {1};
    vector<int> result2 = solution.majorityElement(nums2);
    cout << "Example 2: ";
    for (const auto& num : result2) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums3 = {1, 2};
    vector<int> result3 = solution.majorityElement(nums3);
    cout << "Example 3: ";
    for (const auto& num : result3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
