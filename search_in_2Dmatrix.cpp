#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();
    int s = 0;
    int e = row * col - 1;

    while (s <= e) {
        int mid = s + (e - s) / 2;
        int ele = matrix[mid / col][mid % col];

        if (ele == target) {
            return true;
        }
        else if (ele > target) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return false;
}

int main() {
    int n, m, target;
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter elements of matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Enter target element: ";
    cin >> target;

    if (searchMatrix(matrix, target)) {
        cout << "Element found";
    } else {
        cout << "Element not found";
    }

    return 0;
}
