// row wise sum if the 2-D array
#include<bits/stdc++.h>
using namespace std;

vector<int>findSum(vector<vector<int>>&arr){
    int sum = 0;
    vector<int>result;
    for(int i =0;i<arr.size();i++){
        int rowSum =0; 
        for(int j =0;j<arr[0].size();j++){
            rowSum += arr[i][j];
        }
        result.push_back(rowSum);
    }
    return result;
}

int maxSum(vector<vector<int>>&arr){
    int maxSum = 0;
    
    for(int i =0;i<arr.size();i++){
        int rowSum =0; 
        for(int j =0;j<arr[0].size();j++){
            rowSum += arr[i][j];
        }
        if(rowSum>maxSum){
            maxSum = rowSum;
        }
    }

    return maxSum;
}

int main(){
    
    vector<vector<int>>arr = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<int>result = findSum(arr);
    for(auto i : result){
        cout<<" "<<i;
    }

    cout<<"\n Max row Sum : "<<maxSum(arr);

}    