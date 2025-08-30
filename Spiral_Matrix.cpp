#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int Col = matrix[0].size();
        int total = row * Col;
        int count = 0;
        int sRow = 0;
        int sCol = 0;
        int eRow = row - 1;
        int eCol = Col - 1;

        while (count < total) {
            for (int i = sCol; i <= eCol && count < total; i++) {
                ans.push_back(matrix[sRow][i]);
                count++;
            }
            sRow++;
            for (int i = sRow; i <= eRow && count < total; i++) {
                ans.push_back(matrix[i][eCol]);
                count++;
            }
            eCol--;
            for (int i = eCol; i >= sCol && count < total; i--) {
                ans.push_back(matrix[eRow][i]);
                count++;
            }
            eRow--;
            for (int i = eRow; i >= sRow && count < total; i--) {
                ans.push_back(matrix[i][sCol]);
                count++;
            }
            sCol++;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> result = sol.spiralOrder(matrix);

    cout << "Spiral Order Traversal: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
