#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int n = heights.size();
        int leftSmaller[n];
        int rightSmaller[n];

        std::stack<int> s;

        for (int i = 0; i < n; i++) {
            if (s.empty()) {
                leftSmaller[i] = -1;
                s.push(i);
            } else if (heights[s.top()] < heights[i]) {
                leftSmaller[i] = s.top();
                s.push(i);
            } else {
                while (!s.empty() && heights[s.top()] >= heights[i]) {
                    s.pop();
                }
                if (s.empty()) {
                    leftSmaller[i] = -1;
                    s.push(i);
                } else {
                    leftSmaller[i] = s.top();
                    s.push(i);
                }
            }
        }

        while (!s.empty()) {
            s.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            if (s.empty()) {
                rightSmaller[i] = n;
                s.push(i);
            } else if (heights[s.top()] < heights[i]) {
                rightSmaller[i] = s.top();
                s.push(i);
            } else {
                while (!s.empty() && heights[s.top()] >= heights[i]) {
                    s.pop();
                }
                if (s.empty()) {
                    rightSmaller[i] = n;
                    s.push(i);
                } else {
                    rightSmaller[i] = s.top();
                    s.push(i);
                }
            }
        }

        int maxArea = heights[0];
        int currArea = heights[0];
        for (int i = 0; i < n; i++) {
            currArea = heights[i] * (rightSmaller[i] - leftSmaller[i] - 1);
            maxArea = std::max(maxArea, currArea);
        }

        return maxArea;
    }
};

int main() {
    Solution solution;
    std::vector<int> heights = {2, 1, 5, 6, 2, 3};

    int result = solution.largestRectangleArea(heights);

    std::cout << "Output: " << result << std::endl;

    return 0;
}
