#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int numTrees1(int n){
            return solve(n);
        }
        int numTrees2(int n){
            vector<int>dp(n+1 , 0);

            dp[0] = 1;

            for(int nodes = 1 ; nodes <= n ; nodes++){
                for(int left = 0 ; left < nodes;left++){
                    int right = nodes - left -1;
                    dp[nodes] += dp[left] * dp[right];
                }
            }
            return dp[n];
        }
    private:
        int solve(int n){
            if(n <= 1) return 1;

            int ans = 0;

            for(int nodes = 1 ; nodes<= n ; nodes++){
                ans += solve(nodes-1)*solve(n-nodes); 
            }

            return ans;
        }
};


int main() {
    Solution solution;  
    int n;

    cout << "Enter the number of nodes: ";
    cin >> n;

    int result1 = solution.numTrees1(n);  
    cout << "Number of unique BSTs with " << n << " nodes is: " << result1 << endl;
    int result2 = solution.numTrees2(n);  
    cout << "Number of unique BSTs with " << n << " nodes is: " << result2 << endl;

    return 0;
}