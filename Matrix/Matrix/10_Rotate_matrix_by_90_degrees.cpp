#include <iostream>
#include <algorithm> // Include the algorithm header for reverse

using namespace std;

const int n = 4;

void rotate(int mat[n][n]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(mat[i][j], mat[j][i]); 
        }
    }
    for (int i = 0; i < n; i++) {
        reverse(mat[i], mat[i] + n);
    }
}

void print(int mat[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int mat[n][n] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
    rotate(mat);
    print(mat);

    return 0;
}
