#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> matrix  , int target){
    if(matrix.empty() && matrix[0].size())
        return false;

    int rows = matrix.size();
    int cols = matrix[0].size();

    int row = 0;
    int col = col -1;

    while(row < rows && col>=0){
        if(matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target){
            row++;
        }
        else{
            col--;
        }    
    }
    return false;  
}

int main(){
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    
    int target = 5;

    if(searchMatrix(matrix , target)){
        cout<<"Target found in Matrix";
    }
    else{
        cout<<"Target not found in Matrix";
    }
}