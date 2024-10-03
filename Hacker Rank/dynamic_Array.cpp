#include<bits/stdc++.h>
using namespace std;

vector<int> dynamicArray(int n , vector<vector<int>> quires){
    int lastAnswer = 0;
    vector<vector<int>>arr(n);
    vector<int>result;

    for(auto query : quires){
        int queryType = query[0];
        int x = query[1];
        int y = query[2];

        int index = (x^lastAnswer)%n;

        if(queryType == 1){
            arr[index].push_back(y);
        }else if(queryType == 2){
            lastAnswer = arr[index][y%arr[index].size()];
            result.push_back(lastAnswer);
        }
    }

    return result;
}

int main(){
    vector<vector<int>>quires = {
        {1, 0 ,5},
        {1 ,1 ,7},
        {1 ,0, 3},
        {2, 1 ,0},
        {2, 1 ,1}
    };
 

    vector<int>result = dynamicArray(quires.size(),quires);
}
