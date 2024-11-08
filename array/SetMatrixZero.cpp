#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<bool>zeroRow(row,false);
        vector<bool>zeroCol(col,false);

        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(matrix[i][j] == 0){
                    zeroRow[i] = true;
                    zeroCol[j] = true;
                }
            }
        }
        
        for(int i = 0;i<row;i++){
            if(zeroRow[i]){
                for(int j = 0;j<col;j++){
                    matrix[i][j]=0;
                }
            }    
        }
        
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(zeroCol[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    // Example test case
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    Solution sol;
    sol.setZeroes(matrix);

    // Output the modified matrix
    cout << "Output Matrix: \n";
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
