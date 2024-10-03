#include<bits/stdc++.h>
using namespace std;

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
        int appleCount = 0;
        int orangeCount = 0;
        
        for(int i = 0;i<apples.size();i++){
                int dis = a + apples[i];
                if(dis >= s && dis <= t){
                      appleCount++;         
                }
        }
        
        for(int i = 0;i<oranges.size();i++){
                int dis = b + oranges[i];
                if(dis >= s && dis <= t){
                      orangeCount++;         
                }
        }
        
        cout<<"Apples : "<<appleCount<<endl<<"Oranges : "<<orangeCount;
}

int main() {
    int s = 7;  // Start point of the house
    int t = 10; // End point of the house
    int a = 4;  // Position of the apple tree
    int b = 12; // Position of the orange tree

    vector<int> apples = {2, 3, -4};   // Distances where each apple falls
    vector<int> oranges = {3, -2, -4}; // Distances where each orange falls

    countApplesAndOranges(s, t, a, b, apples, oranges);

    return 0;
}