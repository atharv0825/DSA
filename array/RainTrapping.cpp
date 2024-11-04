#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if(size < 2)
            return 0;
        int left = 0 , right = size-1;
        int rightMax = 0 ,  leftMax = 0;
        int result = 0;

        while(left<right){
            if(height[left] < height[right]){
                leftMax = max(leftMax , height[left]);
                result += leftMax - height[left];
                left++;
            }
            else{
                rightMax = max(rightMax , height[right]);
                result += rightMax - height[right];
                right--;
            }
        }

        return result;
    }
};

int main() {
    // Input height array
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    // Create a Solution object
    Solution solution;
    
    // Call the trap function and print the result
    int result = solution.trap(height);
    cout << "Total water trapped: " << result << endl;

    return 0;
}
