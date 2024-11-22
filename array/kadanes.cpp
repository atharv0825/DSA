#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int max_current = nums[0];
    int max_global = nums[0];
    vector<int> current_subarray = {nums[0]};
    vector<int> global_subarray = {nums[0]};

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > max_current + nums[i]) {
            max_current = nums[i];
            current_subarray = {nums[i]};
        } else {
            max_current += nums[i];
            current_subarray.push_back(nums[i]);
        }

        if (max_current > max_global) {
            max_global = max_current;
            global_subarray = current_subarray;
        }

        // Print current step details
        cout << "Step " << i << ": Current Subarray = [";
        for (int n : current_subarray) cout << n << " ";
        cout << "] with Sum = " << max_current << endl;
    }

    // Print the global subarray
    cout << "Global Maximum Subarray = [";
    for (int n : global_subarray) cout << n << " ";
    cout << "] with Sum = " << max_global << endl;

    return max_global;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    maxSubArray(nums);
    return 0;
}
