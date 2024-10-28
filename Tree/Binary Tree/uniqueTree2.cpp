#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution class to generate trees
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }

private:
    vector<TreeNode*> solve(int left, int right) {
        vector<TreeNode*>result;
        if(left > right){
            result.push_back(nullptr);
        }
        else{
            for(int root = left ; root<=right;root++){
                vector<TreeNode*>leftSubTree = solve(left,root-1);
                vector<TreeNode*>rightSubTree = solve(root+1,right);

                for(TreeNode * leftSide : leftSubTree){
                    for(TreeNode * rightSide : rightSubTree){
                        TreeNode* trees = new TreeNode(root , leftSide, rightSide);
                        result.push_back(trees);
                    }
                }
            }
        }
        return result;    
    }
};

// Function to print the binary tree in pre-order traversal
void printTree(TreeNode* node) {
    if (!node) {
        cout << "null ";
        return;
    }
    cout << node->val << " ";
    printTree(node->left);
    printTree(node->right);
}

int main() {
    Solution solution;
    int n;// Example value of n
    cout << "Enter the number of nodes: ";
    cin >> n;
    vector<TreeNode*> allTrees = solution.generateTrees(n);

    // Print all generated trees
    cout << "Total number of unique BSTs: " << allTrees.size() << endl;
    for (int i = 0; i < allTrees.size(); i++) {
        cout << "Tree " << i + 1 << ": ";
        printTree(allTrees[i]);
        cout << endl;
    }

    return 0;
}
