/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  int sumNumbers(TreeNode* root, int currentSum) {
        if (root == NULL) {
            return 0;
        }

        // Update the current sum
        currentSum = currentSum * 10 + root->val;

        // If it's a leaf node, return the current sum
        if (root->left == NULL && root->right == NULL) {
            return currentSum;
        }

        // Recursively calculate the sum for both left and right subtrees
        int leftSum = sumNumbers(root->left, currentSum);
        int rightSum = sumNumbers(root->right, currentSum);

        // Return the total sum from both subtrees
        return leftSum + rightSum;
    }
    int sumNumbers(TreeNode* root) {
     return sumNumbers(root, 0);
    }
};