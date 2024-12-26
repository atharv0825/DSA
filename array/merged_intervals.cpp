#include <iostream>
#include <vector>
#include <algorithm> // For sort function

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Brute force algorithm for sorted intervals
        vector<vector<int>> merged_pairs;
        if (intervals.size() == 0) {
            return merged_pairs;
        }

        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0];

        for (auto it : intervals) {
            if (it[0] <= tempInterval[1]) {
                tempInterval[1] = max(tempInterval[1], it[1]);
            } else {
                merged_pairs.push_back(tempInterval);
                tempInterval = it;
            }
        }

        merged_pairs.push_back(tempInterval);
        return merged_pairs;
    }
};

int main() {
    // Test case input
    vector<vector<int>> intervals = {
        {1, 3}, {2, 6}, {8, 10}, {15, 18}
    };

    Solution solution;
    vector<vector<int>> result = solution.merge(intervals);

    // Output the merged intervals
    cout << "Merged Intervals: " ;
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
