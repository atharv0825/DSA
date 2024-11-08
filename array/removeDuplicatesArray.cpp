#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main() {
    // Input sorted array with duplicates
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    // Create a Solution object
    Solution solution;

    cout<<"Original Array : ";
    for (int i = 0; i < nums.size(); i++) {
        cout<<nums[i]<<" ";
    }

    // Call the removeDuplicates function and store the new length
    int newLength = solution.removeDuplicates(nums);

    // Output the array with unique elements up to the new length
    cout << "\nArray after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    // Output the new length of the array
    cout << "New length of the array: " << newLength << endl;

    return 0;
}
