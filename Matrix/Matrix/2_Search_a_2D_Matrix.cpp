#include <iostream>
#include <vector>

class Solution {
public:
    bool Binarysearch(std::vector<std::vector<int>>& matrix, int a, int b, int target, int r, int c) {
        if (a > b) {
            return false;
        }
        int mid = (a + b) / 2;
        if (matrix[mid / c][mid % c] == target) {
            return true;
        } else if (matrix[mid / c][mid % c] > target) {
            return Binarysearch(matrix, a, mid - 1, target, r, c);
        } else {
            return Binarysearch(matrix, mid + 1, b, target, r, c);
        }
    }

    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int r = matrix.size();
        int c = matrix[0].size();
        return Binarysearch(matrix, 0, r * c - 1, target, r, c);
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;

    bool result = solution.searchMatrix(matrix, target);

    if (result) {
        std::cout << "Output: true\n";
    } else {
        std::cout << "Output: false\n";
    }

    return 0;
}
