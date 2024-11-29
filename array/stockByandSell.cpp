#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minSoFar = prices[0];

        for(int i=1;i<prices.size();i++){
            if(prices[i] < minSoFar){
                minSoFar = prices[i];
            }
            int currentMax = prices[i] - minSoFar;
            maxProfit = max(maxProfit, currentMax);
        }

        return maxProfit;
    }
};

int main() {
    Solution solution;

    // Test Case
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Call maxProfit and print the result
    int result = solution.maxProfit(prices);
    cout << "Maximum profit: " << result << endl;

    return 0;
}
